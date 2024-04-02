#include "ros/ros.h"
#include "geometry_msgs/Quaternion.h"
#include <array>
#include <cmath>

void quaternionCallback(const geometry_msgs::Quaternion::ConstPtr& msg) {
    ROS_INFO("Orientation (Euler angles): \n x: %f \n y: %f \n z: %f \n", 
             msg->x, msg->y, msg->z);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "quaternion_listener_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("orientation", 10, quaternionCallback);

    ros::spin();

    return 0;
}

