#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;

  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv;
  add_turtle.call(srv);
  // give birth to turtle3
  turtlesim::Spawn srv1;
  add_turtle.call(srv1);

  ros::Publisher turtle_vel2 = node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);
  ros::Publisher turtle_vel3 = node.advertise<geometry_msgs::Twist>("turtle3/cmd_vel", 10);


  tf::TransformListener listener;

  ros::Rate rate(10.0);
  while (node.ok()){
    tf::StampedTransform transform;
    try{
      listener.lookupTransform("/turtle2", "/turtle1",
                               ros::Time(0), transform);
    }
    catch (tf::TransformException &ex) {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }

    geometry_msgs::Twist vel_msg2;
    vel_msg2.angular.z = 4.0 * atan2(transform.getOrigin().y(),
                                    transform.getOrigin().x());
    vel_msg2.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
                                  pow(transform.getOrigin().y(), 2))-0.15;
	turtle_vel2.publish(vel_msg2);


    geometry_msgs::Twist vel_msg3;

    vel_msg3.angular.z = 4.0 * atan2(transform.getOrigin().y(),
    	transform.getOrigin().x());
    vel_msg3.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
        pow(transform.getOrigin().y(), 2))-0.1;

    turtle_vel3.publish(vel_msg3);

    rate.sleep();
  }
  return 0;
};