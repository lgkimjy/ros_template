/*
 *  @file main_node.cpp
 *  @author JunYoung Kim
 *  @date 05/04/22
 */
#include <ros/ros.h>
#include <ros_template/Template.hpp>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "roscpp_template");
    ros::NodeHandle nh;

    // Class Declaration
    ROSTemplate ROSTemplate(nh);

    return 0;
}