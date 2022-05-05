/*
 *  @file Template.cpp
 *  @author JunYoung Kim
 *  @date 05/04/22
 */
#include <ros_template/Template.hpp>
#include <iostream>
using namespace std;

ROSTemplate::ROSTemplate(ros::NodeHandle nh)
    : nh_(nh),
      SubscriberTopic_("/subscriber_topic_name"),
      PublisherTopic_("/publisher_topic_name"),
      Service_("/server_service_name"),
      Client_("/client_service_name")
{
    ROS_INFO("[roscpp_template] Node Starts");
    init();
    mainProcess();
}
ROSTemplate::~ROSTemplate() {}

void ROSTemplate::init()
{
    // Publisher & Subscriber
    pub_ = nh_.advertise<ros_template::custom_msg>(PublisherTopic_, 10);
    sub_ = nh_.subscribe(SubscriberTopic_, 10, &ROSTemplate::SubsciberCallback, this);
    // Server & Client
    server_ = nh_.advertiseService(Service_, &ROSTemplate::ServiceCallback, this);
    client_ = nh_.serviceClient<ros_template::custom_srv>(Client_);
    return;
}

bool ROSTemplate::ServiceCallback(ros_template::custom_srv::Request &req,
                                  ros_template::custom_srv::Response &res)
{
    if (req.a != 0 || req.b != 0)
    {
        res.sum = req.a + req.b;
        data_ = res.sum;
    }
    return true;
}

void ROSTemplate::SubsciberCallback(const geometry_msgs::Vector3 &msg)
{
    data_ = msg.x;
}

void ROSTemplate::PublishData()
{
    ros_template::custom_msg new_msg;
    new_msg.num = data_;
    new_msg.stamp = ros::Time::now();
    pub_.publish(new_msg);
}

void ROSTemplate::mainProcess()
{
    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        PublishData();
        ROS_INFO("[roscpp_template] Process Running");
        ros::spinOnce();
        loop_rate.sleep();
    }

    return;
}