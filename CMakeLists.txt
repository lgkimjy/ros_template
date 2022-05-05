cmake_minimum_required(VERSION 3.0.2)
project(ros_template)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  actionlib_msgs
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  message_generation
)

add_message_files(FILES custom_msg.msg)
add_service_files(FILES custom_srv.srv)
add_action_files(FILES custom_action.action)
generate_messages(DEPENDENCIES actionlib_msgs std_msgs)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES ${PROJECT_NAME}
 CATKIN_DEPENDS actionlib_msgs geometry_msgs roscpp rospy sensor_msgs std_msgs
 DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS scripts/PythonTemplate.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

add_executable(roscpp_template src/main_node.cpp src/Template.cpp)
target_link_libraries(roscpp_template ${catkin_LIBRARIES})
add_dependencies(roscpp_template ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})