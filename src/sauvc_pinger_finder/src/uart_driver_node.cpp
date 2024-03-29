#include "stingray_core_communication/uart_driver.h"
#include "sauvc_pinger_finder/messages/msg_pingerFinder.h"

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("PingerUartDriver");
    auto bridge = UartDriver<PingerFinderMessage, PingerFinderMessage>(node);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}