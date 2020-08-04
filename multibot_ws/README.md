# Important launch commands

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
roslaunch multi_robot multirobot_arena.launch
```
