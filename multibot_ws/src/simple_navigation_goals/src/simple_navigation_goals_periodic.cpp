#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

  int count = 0;

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move 1 meter forward
  /*goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x = 1.0;
  goal.target_pose.pose.orientation.w = 1.0;*/

  while (ros::ok()){
  goal.target_pose.header.frame_id = "base_link";   //map is recommended
  goal.target_pose.header.stamp = ros::Time::now();

  if(count != 5){
    goal.target_pose.pose.position.x = 1.0;
    goal.target_pose.pose.orientation.w = 1.0;
  }
  else{
    ROS_INFO("The agent was detected to be stuck");
    goal.target_pose.pose.position.x = -1.0;
    goal.target_pose.pose.orientation.w = 1.0;
    ros::Duration(5.0).sleep();
    count = 0;
  }

  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  //ac.waitForResult();
  ros::Duration(10.0).sleep();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved 1 meter forward in 10 seconds");
  else{
    count++;
    ROS_INFO("The base failed to move forward 1 meter in 10 seconds for some reason");
    }
  }
  return 0;
}
