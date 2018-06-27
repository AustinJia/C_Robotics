cmake_minimum_required(VERSION 2.8.3)
project(learning_tf)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  turtlesim
)

## Generate messages in the 'msg' folder
# add_message_files(msg FILES Message1.msg)

## Generate services in the 'srv' folder
# add_service_files(srv FILES Service1.srv)


## Generate added messages
# generate_messages(DEPENDENCIES std_msgs  # Or other packages containing msgs)

## Declare a catkin package
catkin_package()


## Build talker and listener
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_tf_broadcaster src/turtle_tf_broadcaster.cpp)
target_link_libraries(turtle_tf_broadcaster ${catkin_LIBRARIES})
