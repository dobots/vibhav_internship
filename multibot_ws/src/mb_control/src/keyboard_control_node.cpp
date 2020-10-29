#include<ros/ros.h>
#include<geometry_msgs/Twist.h>
#include<math.h>
//#include<prius_msgs/Control.h>

//global varibles for parameters
float throttle_param;
float steer_param;

class SubscribeAndPublish
{
public:
  SubscribeAndPublish()	//default construcor
  {
    //to publish prius message
    pub_ = n_.advertise<geometry_msgs::Twist>("mod_cmd_vel",1000);

    //to subscribe to cmd_vel messages
    sub_ = n_.subscribe("turtle1/cmd_vel",1000, &SubscribeAndPublish::callback, this);
  }

  void callback(const geometry_msgs::Twist &msg)// callback function for subscriber
  {
    geometry_msgs::Twist mod_msg;
    if(msg.linear.x > 0)
      mod_msg.linear.x = throttle_param;
    else if(msg.linear.x < 0)
      mod_msg.linear.x = -throttle_param;

    if(msg.angular.z > 0)  //left
      mod_msg.angular.z = throttle_param;
    else if(msg.angular.z < 0)
      mod_msg.angular.z = -throttle_param;

    pub_.publish(mod_msg);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_; //private ROS publisher 
  ros::Subscriber sub_; //private ROS subscriber 
};
//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
//Initiate ROS
ros::init(argc, argv, "keyboard_control");

//get steering and throttle parameters from the parameter server.

const std::string PARAM_throttle = "keyboard_control_node/throttle_param";
const std::string PARAM_steer = "keyboard_control_node/steer_param";
bool ok;
ok = ros::param::get(PARAM_throttle,throttle_param);
if(!ok)
  {
    ROS_FATAL_STREAM("Could not get throttle parameter"<<PARAM_throttle);
  }
ok = ros::param::get(PARAM_steer,steer_param);
if(!ok)
  {
    ROS_FATAL_STREAM("Could not get steer parameter"<<PARAM_steer);
  }

ROS_INFO_STREAM("throttle_param "<<throttle_param);
ROS_INFO_STREAM("steer_param "<<steer_param);

if (throttle_param>1||throttle_param<-1)
  ROS_WARN_STREAM("throttle_param out of the range [-1,1]");
if (steer_param>1||steer_param<-1)
  ROS_WARN_STREAM("steer_param out of the range [0,1]");  

SubscribeAndPublish SAPObject; // object of class SubscribeAndPublish

ros::spin();

return 0;
}