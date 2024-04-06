#ifndef HYDROACOUSTIC_BRIDGE_H
#define HYDROACOUSTIC_BRIDGE_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/u_int16.hpp>
#include <std_msgs/msg/float64.hpp>
#include <std_msgs/msg/u_int32.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/u_int8_multi_array.hpp>
#include <std_srvs/srv/set_bool.hpp>
#include <std_srvs/srv/trigger.hpp>
#include "std_msgs/msg/string.hpp"

#include <sstream>
#include <string>
#include <vector>
#include <math.h>

#include "stingray_core_interfaces/srv/set_twist.hpp"
#include "stingray_core_interfaces/srv/set_device.hpp"
#include "stingray_core_interfaces/srv/set_stabilization.hpp"
#include "stingray_core_interfaces/msg/uv_state.hpp"
#include "stingray_core_interfaces/msg/device_state.hpp"
#include "stingray_core_interfaces/msg/device_state_array.hpp"
#include "stingray_core_communication/messages/common.h"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

template <class RequestMessage, class ResponseMessage>
class HydroacousticBridge {
public:
    HydroacousticBridge(std::shared_ptr<rclcpp::Node> _node) : _node(_node) {

        // ROS PARAMETERS
        // topic names
        _node->declare_parameter("driver_request_topic", "/stingray/topics/driver_request");
        _node->declare_parameter("driver_response_topic", "/stingray/topics/driver_response");
        _node->declare_parameter("angle_hydroacoustic_topic", "/stingray/topics/angle_hydroacoustic");

        // ROS publishers
        this->driverRequestPub = _node->create_publisher<std_msgs::msg::UInt8MultiArray>(
            _node->get_parameter("driver_request_topic").as_string(), 1000);
        this->angleToPingerPub = _node->create_publisher<std_msgs::msg::Float64>(
            _node->get_parameter("angle_hydroacoustic_topic").as_string(), 1000);

        // ROS subscribers
        this->driverResponseSub = _node->create_subscription<std_msgs::msg::UInt8MultiArray>(
            _node->get_parameter("driver_response_topic").as_string(), 1000,
            std::bind(&HydroacousticBridge::driverResponseCallback, this, std::placeholders::_1));

        // Output message container
        driverHydroacousticRequestMsg.layout.dim.push_back(std_msgs::msg::MultiArrayDimension());
        driverHydroacousticRequestMsg.layout.dim[0].size = RequestMessage::length;
        driverHydroacousticRequestMsg.layout.dim[0].stride = RequestMessage::length;
        driverHydroacousticRequestMsg.layout.dim[0].label = "driverHydroacousticRequestMsg";

        // Initializing timer for publishing messages. Callback interval: 0.05 ms
        this->publishingTimer = _node->create_wall_timer(500ms, std::bind(&HydroacousticBridge::driverRequestCallback, this));
    }

    std::shared_ptr<rclcpp::Node> _node;

private:

    void driverRequestCallback() {
        // Make output message
        std::vector<uint8_t> output_vector;

        requestMessage.angle = 0;
        requestMessage.pack(output_vector);
        driverHydroacousticRequestMsg.data.clear();
        for (int i = 0; i < RequestMessage::length; i++) {

            driverHydroacousticRequestMsg.data.push_back(output_vector[i]);
        }
        // Publish messages
        driverRequestPub->publish(driverHydroacousticRequestMsg);
    }

    void driverResponseCallback(const std_msgs::msg::UInt8MultiArray &msg) {
        std::vector<uint8_t> received_vector;
        for (int i = 0; i < ResponseMessage::length; i++) {
            received_vector.push_back(msg.data[i]);
        }
        bool ok = responseMessage.parse(received_vector);
        if (ok) {
            int8_t offset = reinterpret_cast<int8_t>(responseMessage.angle);
            uint16_t Fs = 1250; // kHz
            float angle = asin(1498 * offset / (Fs * 24.89)) / M_PI * 180;
            angleToPinger.data = angle;
            angleToPingerPub->publish(angleToPinger);

        } else
            RCLCPP_ERROR(_node->get_logger(), "Wrong checksum HYDROACOUSTIC");
    }

    // ROS publishers
    rclcpp::Publisher<std_msgs::msg::UInt8MultiArray>::SharedPtr driverRequestPub;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr angleToPingerPub;

    // ROS subscribers
    rclcpp::Subscription<std_msgs::msg::UInt8MultiArray>::SharedPtr driverResponseSub;

    // Message containers
    std_msgs::msg::Float64 angleToPinger;
    std_msgs::msg::UInt8MultiArray driverHydroacousticRequestMsg;
    RequestMessage requestMessage;
    ResponseMessage responseMessage;
    // Other
    rclcpp::TimerBase::SharedPtr publishingTimer; // Timer for publishing messages
};

#endif // HYDROACOUSTIC_BRIDGE_H
