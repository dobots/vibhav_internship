# Keyboard control

## Current status
The following are implemented at the moment:-
1. Spawning of the URDF robot onto a predefined world on gazebo. To launch it, use:-
```bash
roslaunch mb_gazebo mb_arena.launch
```
2. The above function, running it on rviz, controlling the bot with a keyboard, localisation using hector_slam and saving the 2D map. To launch this, use:- 
```bash
roslaunch mb_gazebo mb_keyboard_sim.launch
``` 
3. To save the map generated, ensure that gazebo (and thus the map server) is still running and use:-
```bash
rosrun map_server map_saver -f <NAME_OF_MAP>
``` 

