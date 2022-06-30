# sauvc
Software for [SAUVC](https://sauvc.org/) competition based on [Stingray](https://github.com/hidronautics/stingray)

# Installation

- Initialize and update git submodules used in project:

```bash
git submodule update --init --recursive
```

- Complete pre-build steps in [stingray](/src/stingray/)

- Build **sauvc**:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
catkin_make
```

# Run

Setup workspace before you start to work:

```bash
source devel/setup.bash
```

### Simulation startup

* Clone and built our [simulator](https://github.com/hidronautics/simulator) for SAUVC competition.
* Run simulator.
* in sauvc directory run
```bash
roslaunch sauvc_startup simulation.launch
```

### Object detection
- Run detection on real cameras:
```bash
roslaunch sauvc_startup object_detection.launch real_cam:=true 
```
- Run detection on simulation cameras:
```bash
roslaunch sauvc_startup object_detection.launch simulation:=true
```
- Run detection on video from files:
```bash
roslaunch sauvc_startup object_detection.launch file:=true file1_path:=PATH_TO_VIDEO_1 file2_path:=PATH_TO_VIDEO_2
```
