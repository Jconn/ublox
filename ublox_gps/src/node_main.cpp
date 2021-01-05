#include <memory>

#include <rclcpp/rclcpp.hpp>

#include <ublox_gps/node.hpp>

int main(int argc, char** argv) {
  // Force flush of the stdout buffer.
  setvbuf(stdout, nullptr, _IONBF, BUFSIZ);

  rclcpp::init(argc, argv);

  auto ublox_node = std::make_shared<ublox_node::UbloxNode>(rclcpp::NodeOptions());
  ublox_node->createBond();
  rclcpp::spin(ublox_node);

  rclcpp::shutdown();

  return 0;
}
