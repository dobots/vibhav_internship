# Mapping, planning and control of single and multiple robots

This repository consists of the code to:-

1. Run a single robot and explore an area using 
	1.	Hector Slam
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
This package needs to be cloned directly onto the current workspace. The repository can be found [here](https://github.com/hrnr/m-explore) and can be loaded using:-
```bash
git clone https://github.com/hrnr/m-explore.git
```
#### Cartographer [(link)](http://wiki.ros.org/cartographer)
An important resource on this package can be found [here](https://ouster.com/blog/building-maps-using-google-cartographer-and-the-os1-lidar-sensor/). To install this package, use:-
```bash
sudo apt-get install ros-melodic-cartographer ros-melodic-cartographer-ros ros-melodic-cartographer-ros-msgs ros-melodic-cartographer-rviz
```

#### Teleop twist keyboard [(link)](http://wiki.ros.org/teleop_twist_keyboard)
```bash
sudo apt-get install ros-melodic-teleop-twist-keyboard
```

***
## Launch commands

#### Single robot with enabled 
roslaunch mb_navigation nav_tut_hectorslam.launch

roslaunch mb_navigation nav_tut_gmapping.launch

roslaunch mb_navigation nav_tut_carto.launch

rosrun teleop_twist_keyboard teleop_twist_keyboard.py


#### Single Robot Exploration

roslaunch mb_navigation autexpl_hector_slam.launch

roslaunch mb_navigation autexpl_gmapping.launch


