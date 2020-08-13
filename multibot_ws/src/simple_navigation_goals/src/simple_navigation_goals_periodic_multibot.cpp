#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

  int count1=0, count2 =0;

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac1("/robot1/move_base", true);
  MoveBaseClient ac2("/robot2/move_base", true);

  //wait for the action server to come up
  while(!ac1.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the /robot1/move_base action server to come up");
  }

  while(!ac2.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the /robot2/move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal1;
  move_base_msgs::MoveBaseGoal goal2;

  //we'll send a goal to the robot to move 1 meter forward
  /*goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  goal.target_pose.pose.position.x = 1.0;
  goal.target_pose.pose.orientation.w = 1.0;*/

  while (ros::ok()){
  goal1.target_pose.header.frame_id = "robot1_tf/base_link";
  goal1.target_pose.header.stamp = ros::Time::now();

  goal2.target_pose.header.frame_id = "robot2_tf/base_link";
  goal2.target_pose.header.stamp = ros::Time::now();

  if(count1 != 5){
    goal1.target_pose.pose.position.x = 1.0;
    goal1.target_pose.pose.orientation.w = 1.0;
  }
  else{
    ROS_INFO("The agent was detected to be stuck");
    goal1.target_pose.pose.position.x = -1.0;
    goal1.target_pose.pose.orientation.w = 1.0;
    ros::Duration(5.0).sleep();
    count1 = 0;
  }

  if(count2 != 5){
    goal2.target_pose.pose.position.x = 1.0;
    goal2.target_pose.pose.orientation.w = 1.0;
  }
  else{
    ROS_INFO("The agent was detected to be stuck");
    goal2.target_pose.pose.position.x = -1.0;
    goal2.target_pose.pose.orientation.w = 1.0;
    ros::Duration(5.0).sleep();
    count1 = 0;
  }

  ROS_INFO("Sending goal");
  ac1.sendGoal(goal1);

  ROS_INFO("Sending goal");
  ac2.sendGoal(goal2);

  //ac.waitForResult();
  ros::Duration(7.0).sleep();

  if(ac1.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved 1 meter forward in 7 seconds");
  else{
    count1++;
    ROS_INFO("The base failed to move forward 1 meter in 7 seconds for some reason");
    }

  if(ac2.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, the base moved 1 meter forward in 7 seconds");
  else{
    count2++;
    ROS_INFO("The base failed to move forward 1 meter in 7 seconds for some reason");
    }

  }
  return 0;
}
