# sauvc
Software for [SAUVC](https://sauvc.org/) competition

## Building

Install dependencies:

```bash
sudo apt-get install ros-$ROS_DISTRO-usb-cam ros-$ROS_DISTRO-rosbridge-server ros-$ROS_DISTRO-image-view ros-$ROS_DISTRO-actionlib ros-$ROS_DISTRO-smach ros-$ROS_DISTRO-smach-viewer
```

Initialize and update git submodules used in project:

```bash
git submodule update --init --recursive
```

Use following commands to build:
```bash
source /opt/ros/$ROS_DISTRO/setup.bash
catkin_make
```
Do not forget to setup workspace before you start to work:
```bash
source devel/setup.bash
```

## Simulation startup

* Clone and built our [simulator](https://github.com/hidronautics/simulator) for SAUVC competition.
* Run simulator.
* in sauvc directory run
```bash
roslaunch sauvc_startup simulation.launch
```