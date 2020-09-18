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

## Important Packages
The launch files have been developed and tested on Ubuntu LTS 18.04 and ROS Melodic with Gazebo 9 and RViz. The important ROS packages that must be installed are:-

# Multi robot map merge [link](http://wiki.ros.org/multirobot_map_merge)
This package needs to be cloned directly onto the current workspace. The repository can be found [here](https://github.com/hrnr/m-explore) and can be loaded using:-
```bash
git clone https://github.com/hrnr/m-explore.git
```
# Cartographer
An important resource on this package can be found [here](https://ouster.com/blog/building-maps-using-google-cartographer-and-the-os1-lidar-sensor/). To install this package, use:-
```bash
sudo apt-get install ros-melodic-cartographer ros-melodic-cartographer-ros ros-melodic-cartographer-ros-msgs ros-melodic-cartographer-rviz
```

## Current status
The following are implemented at the moment:-

Spawning of the URDF robot onto a predefined world on gazebo. To launch it, use:-
```bash
roslaunch mb_gazebo mb_arena.launch
```

The above function, running it on rviz, controlling the bot with a keyboard, localisation using hector_slam and saving the 2D map. To launch this, use:- 
```bash
roslaunch mb_gazebo mb_keyboard_sim_hector_slam.launch
``` 

The above function, running it on rviz, controlling the bot with a keyboard, localisation using gmapping and saving the 2D map. To launch this, use:- 
```bash
roslaunch mb_gazebo mb_keyboard_sim_gmapping.launch.launch
```

To save the map generated, ensure that gazebo (and thus the map server) is still running and use:-
```bash
rosrun map_server map_saver -f <NAME_OF_MAP>
```

To run a bot in an unknown map and use the navigation stack, ensure that in the "turtlebot3_waffle_base.gazebo.xacro" file in the mb_description package, the <commandTopic> is set as cmd(underscore)vel. To launch this and localise using hectorslam, use:-
```bash 
roslaunch mb_navigation nav_tut_hectorslam.launch
```

To launch this and localise using gmapping, use:-
```bash 
roslaunch mb_navigation nav_tut_gmapping.launch
```

To launch autonomous agent exploration in a map, launch:- 
```bash
roslaunch mb_navigation autexpl_gmapping.launch
```

To launch spawning of 2 agents in a map, launch:- 
```bash
roslaunch multi_robot multirobot_arena_v2.launch
```

To launch spawning of 2 agents with a navigation stack in map and localised by amcl, launch:- 
```bash
roslaunch multi_robot multi_navrobots_amcl.launch
```

To launch spawning of 2 agents with a navigation stack that explore and merge a map, launch:- 
```bash
roslaunch multi_robot multiexplrobot_arena.launch
```

Keyboard cartography one robot:- 
```bash
roslaunch mb_cartography nav_tut_cartographer.launch
```

Keyboard cartography multiple robot:- 
```bash
roslaunch multi_robot multiexplrobot_carto_seperate.launch
```
```bash
roslaunch multi_robot multiexplrobot_carto.launch
```


