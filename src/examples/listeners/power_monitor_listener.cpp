#include <rclcpp/rclcpp.hpp>
#include <px4_msgs/msg/power_monitor.hpp>

/**
 * @brief Sensor Combined uORB topic data callback
 */
class PowerMonitorListener : public rclcpp::Node
        {
        public:
            explicit PowerMonitorListener() : Node("power_monitor_listener") {
                subscription_ = this->create_subscription<px4_msgs::msg::PowerMonitor>(
                        "PowerMonitor_PubSubTopic",
#ifdef ROS_DEFAULT_API
10,
#endif
[this](const px4_msgs::msg::PowerMonitor::UniquePtr msg) {
                            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                            std::cout << "RECEIVED VOXL POWER MONITOR DATA"   << std::endl;
                            std::cout << "================================"   << std::endl;
                            std::cout << "ts: "          << msg->timestamp    << std::endl;
                            std::cout << "voltage (V): " << msg->voltage_v    << std::endl;
                            std::cout << "current (A): " << msg->current_a    << std::endl;
                            std::cout << "Power (W): " << msg->rconf        << std::endl;
                            std::cout << "Power (W): " << msg->rsv        << std::endl;
                            std::cout << "Power (W): " << msg->rbv        << std::endl;
                            std::cout << "Power (W): " << msg->rp        << std::endl;
                            std::cout << "Power (W): " << msg->rc        << std::endl;
                            std::cout << "Power (W): " << msg->rcal        << std::endl;
                            std::cout << "Power (W): " << msg->me        << std::endl;
                            std::cout << "Power (W): " << msg->al        << std::endl;
                        });
            }

        private:
            rclcpp::Subscription<px4_msgs::msg::PowerMonitor>::SharedPtr subscription_;
        };

int main(int argc, char *argv[])
{
    std::cout << "Starting power_monitor listener node..." << std::endl;
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PowerMonitorListener>());

    rclcpp::shutdown();
    return 0;
}
