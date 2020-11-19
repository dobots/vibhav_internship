# Mapping, planning and control of single and multiple robots

This repository consists of the code to:-

1. Run a single robot and explore an area using 
	1. Hector Slam
	2. GMapping
	3. Cartographer
2. Run multiple robots and explore an area using 
	1. Hector Slam
	2. GMapping
	3. Cartographer
3. Run RRT based frontier exploration with a single robot and map an area using 
	1. Hector Slam
	2. GMapping
	3. Cartographer
	
***
## Important Packages
The launch files have been developed and tested on Ubuntu LTS 18.04 and ROS Melodic with Gazebo 9 and RViz. The important ROS packages that must be installed are:-

#### Multi robot map merge [(link)](http://wiki.ros.org/multirobot_map_merge)
This package is already present in the repository.

#### Cartographer [(link)](http://wiki.ros.org/cartographer)
An important resource on this package can be found [here](https://ouster.com/blog/building-maps-using-google-cartographer-and-the-os1-lidar-sensor/). To install this package, use:-
```bash
sudo apt-get install ros-melodic-cartographer ros-melodic-cartographer-ros ros-melodic-cartographer-ros-msgs ros-melodic-cartographer-rviz
```

#### Teleop twist keyboard [(link)](http://wiki.ros.org/teleop_twist_keyboard)
```bash
sudo apt-get install ros-melodic-teleop-twist-keyboard
```

#### RRT Frontier Exploration [(link)](http://wiki.ros.org/rrt_exploration)
This package is already present in the repository.

***
## Launch commands
Before running any of the below commands, navigate to the run

```bash
cd ~/multibot_ws
```
```bash
catkin_make
```
```bash
source ~/multibot_ws/devel/setup.bash
```

#### Single robot with controlled by a user 
These commands launch the robot in a predefined world with different types of mapping algorithms. I order to control the robot, the teleop-twist-keyboard command needs to be launched.

```bash
roslaunch mb_navigation nav_tut_hectorslam.launch
```
```bash
roslaunch mb_navigation nav_tut_gmapping.launch
```
```bash
roslaunch mb_navigation nav_tut_carto.launch
```
```bash
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

#### Autonomous Single Robot Exploration
In this section, the commands run autonomous exploration of a single robot where goals are periodically (every 10 seconds) assigned to a single robot.
```bash
roslaunch mb_navigation autexpl_hector_slam.launch
```
```bash
roslaunch mb_navigation autexpl_gmapping.launch
```
```bash
roslaunch mb_navigation autexpl_cartographer.launch
```
#### Autonomous Multiple Robot Exploration
In this section, the commands run autonomous exploration of a single robot where goals are periodically (every 10 seconds) assigned to multiple robots seperately. Thus there is a non coordinated movement of robots in the arena.
```bash
roslaunch multi_robot multirobot_arena_gmapping.launch
```
#### Single robot RRT Frontier Exploration
A frontier is defined as the region seperating a known from an unkown area. First, an RRT (Rapidly expanding random tree) algorithm detects points on the frontier region. The frontier regions are clustered and the filtered points are sent to an assigner node. At the assigner node the robot is assigned goal positions based on the distance of the goal from the robot and an estimated amount of unexplored area that it can discover. Finally, the robot uses a dijkstras planning method to plan its path to the goal position that is assigned to it.

The original algorithm however does not take care of many corner cases and therefore the following temporary modifications have been made:-
1. Frontiers are cleared up before being published on the map
2. A 5 cycle loop cunter is given to reset the goals
3. A goal is given 0.5m lesser is both X and Y axis from the assigned goal. 

To launch the original RRT exploration algorithm along with GMapping, run:
```bash
roslaunch multi_robot nav_tut_gmapping_single_rrt.launch
```

To launch the RRT exploration algorithm with GMapping and the first modification, run:
```bash
roslaunch multi_robot nav_tut_gmapping_single_mod_rrt.launch
```

To launch the RRT exploration algorithm with Hector SLAM and with the first modification, run:
```bash
roslaunch multi_robot nav_tut_hectorslam_single_mod_rrt.launch
```

To launch the RRT exploration algorithm with Hector SLAM and with the first, second and third modification, run:
```bash
roslaunch multi_robot nav_tut_hectorslam_single_rrt_algo_edit.launch
```
