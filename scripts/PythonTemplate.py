#!/usr/bin/env python
__author__ = "Jun Young Kim"
__email__ = "lgkimjy@hanyang.ac.kr"
__date__ = "05/05/2022"

import rospy
from std_msgs.msg import Int64
from ros_template.msg import custom_msg
from ros_template.srv import custom_srv


class ROSPyTemplate:
    def __init__(self):
        self.data = 0.0
        self.pub = rospy.Publisher(
            "/publisher_topic_name", Int64, queue_size=10)
        self.sub = rospy.Subscriber(
            "/subscriber_topic_name", Int64, self.SubsciberCallback)

    def SubsciberCallback(self, msg):
        self.data += msg.data
        new_msg = Int64()
        new_msg.data = self.data
        self.pub.publish(new_msg)

    def mainProcess(self):
        rospy.loginfo("[rospy_template] Process Running")
        new_msg = Int64()
        new_msg.data = 10
        self.pub.publish(new_msg)


if __name__ == '__main__':

    rospy.init_node('rospy_template')
    rospy.loginfo("[rospy_template] Node Starts")

    rate = rospy.Rate(100)  # 100hz = 10ms

    obj = ROSPyTemplate()

    while not rospy.is_shutdown():
        try:
            obj.mainProcess()
            rate.sleep()
        except KeyboardInterrupt:
            print("Shutting down")
