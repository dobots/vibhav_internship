# Keyboard control

## Current status
The following are implemented at the moment:-

1. Spawning of the URDF robot onto a predefined world on gazebo. To launch it, use:-
```bash
roslaunch mb_gazebo mb_arena.launch
```

2. The above function, running it on rviz, controlling the bot with a keyboard, localisation using hector_slam and saving the 2D map. To launch this, use:- 
```bash
roslaunch mb_gazebo mb_keyboard_sim_hector_slam.launch
``` 

3. The above function, running it on rviz, controlling the bot with a keyboard, localisation using gmapping and saving the 2D map. To launch this, use:- 
```bash
roslaunch mb_gazebo mb_keyboard_sim_gmapping.launch.launch

4. To save the map generated, ensure that gazebo (and thus the map server) is still running and use:-
```bash
rosrun map_server map_saver -f <NAME_OF_MAP>
```

5. Running a bot in an unknown map using the navigation stack is giving an issue of "Control loop missing desired rate". Need to run it on another laptop and check if its a laptop issue. To launch this, use:-
```bash 
roslaunch mb_navigation nav_tut.launch
```
