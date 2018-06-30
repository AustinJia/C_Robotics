cmake_minimum_required(VERSION 2.8.3)
project(learning_tf)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
)


## Generate messages in the 'msg' folder
# add_message_files(FILES Message1.msg)

## Generate services in the 'srv' folder
# add_service_files(FILES Service1.srv)

## Generate actions in the 'action' folder
# add_action_files(DIRECTORY FILES Action1.action)

## Generate added messages and services
# generate_messages(DEPENDENCIES std_msgs)


catkin_package()



## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_tf_broadcaster src/turtle_tf_broadcaster.cpp)
target_link_libraries(turtle_tf_broadcaster ${catkin_LIBRARIES})

add_executable(turtle_tf_listener src/turtle_tf_listener.cpp)
target_link_libraries(turtle_tf_listener ${catkin_LIBRARIES})

add_executable(frame_tf_broadcaster src/frame_tf_broadcaster.cpp)
target_link_libraries(frame_tf_broadcaster ${catkin_LIBRARIES})
