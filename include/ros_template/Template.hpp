/*
 *  @file Template.hpp
 *  @author JunYoung Kim
 *  @date 05/04/22
 */
#include <ros/ros.h>
#include "geometry_msgs/Vector3.h"
#include "ros_template/custom_msg.h"
#include "ros_template/custom_srv.h"

class ROSTemplate
{
public:
    explicit ROSTemplate(ros::NodeHandle nh);
    ~ROSTemplate();

    // Callback Func
    void SubsciberCallback(const geometry_msgs::Vector3 &msg);
    bool ServiceCallback(ros_template::custom_srv::Request &req,
                         ros_template::custom_srv::Response &res);

    // Algorithm Func
    void PublishData();

    // Initialize and mainProcess Func
    void init();
    void mainProcess();

private:
    float data_;

    ros::NodeHandle nh_;

    ros::Subscriber sub_;
    ros::Publisher pub_;
    ros::ServiceServer server_;
    ros::ServiceClient client_;

    std::string SubscriberTopic_;
    std::string PublisherTopic_;
    std::string Service_;
    std::string Client_;
};