"""Deterministic gate detections for testing the FSM and control in Gazebo."""

import math

import rclpy
from nav_msgs.msg import Odometry
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from stingray_interfaces.msg import Bbox, BboxArray


def yaw_of(q):
    return math.atan2(2.0 * (q.w * q.z + q.x * q.y),
                      1.0 - 2.0 * (q.y * q.y + q.z * q.z))


class SimGateDetector(Node):
    def __init__(self):
        super().__init__('sim_gate_detector')
        self.declare_parameter('gate_x', 8.0)
        self.declare_parameter('gate_y', 6.0)
        self.declare_parameter('gate_width', 1.7)
        self.declare_parameter('gate_height', 1.2)
        self.declare_parameter('horizontal_fov_deg', 60.0)
        self.declare_parameter(
            'bbox_topic', '/stingray/topics/camera/front/bbox_array')
        self.pose = None
        self.create_subscription(
            Odometry, '/core/state/odometry', self.on_odometry,
            qos_profile_sensor_data)
        self.publisher = self.create_publisher(
            BboxArray, self.get_parameter('bbox_topic').value, 10)
        self.create_timer(0.1, self.publish_detection)

    def on_odometry(self, msg):
        self.pose = msg.pose.pose

    def publish_detection(self):
        result = BboxArray()
        if self.pose is None:
            self.publisher.publish(result)
            return
        dx = self.get_parameter('gate_x').value - self.pose.position.x
        dy = self.get_parameter('gate_y').value - self.pose.position.y
        yaw = yaw_of(self.pose.orientation)
        forward = math.cos(yaw) * dx + math.sin(yaw) * dy
        # Optical +X points to image right; Gazebo body +Y points left.
        image_right = math.sin(yaw) * dx - math.cos(yaw) * dy
        angle = math.atan2(image_right, forward)
        half_fov = math.radians(
            self.get_parameter('horizontal_fov_deg').value) / 2.0
        gate_width = float(self.get_parameter('gate_width').value)
        # Keep publishing while any part of the gate remains in view. Using
        # only the gate centre makes a close target disappear exactly when a
        # lateral correction is most important.
        gate_half_angle = math.atan2(0.5 * gate_width, max(0.2, forward))
        # During search, require the gate centre to enter the camera. At close
        # range retain the detection while a visible edge is still in frame.
        # Otherwise search can accept a distant sliver and approach the gate
        # almost sideways, creating an unnecessarily large sway correction.
        visible_margin = gate_half_angle if forward < 3.0 else 0.0
        if forward <= 0.2 or abs(angle) >= half_fov + visible_margin:
            self.publisher.publish(result)
            return

        center_x = 320 + int(320 * math.tan(angle) / math.tan(half_fov))
        # Approximate the apparent size of the official 1.5 x 1.0 m SAUVC
        # opening (including its frame) for consumers that inspect bbox shape.
        pixel_height = max(20, min(440, int(650 / max(1.0, forward))))
        aspect_ratio = (
            gate_width /
            self.get_parameter('gate_height').value)
        pixel_width = max(20, min(500, int(pixel_height * aspect_ratio)))
        bbox = Bbox()
        bbox.name = 'gate'
        bbox.id = 0
        bbox.confidence = 0.99
        bbox.top_left_x = max(0, min(639, center_x - pixel_width // 2))
        bbox.bottom_right_x = max(0, min(639, center_x + pixel_width // 2))
        bbox.top_left_y = max(0, 240 - pixel_height // 2)
        bbox.bottom_right_y = min(479, 240 + pixel_height // 2)
        bbox.pos_x = float(image_right)
        bbox.pos_y = 0.0
        bbox.pos_z = float(forward)
        bbox.horizontal_angle = math.degrees(angle)
        bbox.vertical_angle = 0.0
        result.bboxes.append(bbox)
        self.publisher.publish(result)


def main():
    rclpy.init()
    node = SimGateDetector()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
