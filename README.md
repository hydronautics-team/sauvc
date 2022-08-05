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

## Setup workspace before you start to work:

```bash
source devel/setup.bash
```
## Basic launch file:

```bash
roslaunch sauvc_startup sauvc_master.launch 
```
*see args inside

## Simulation startup

* Clone and built our [simulator](https://github.com/hidronautics/simulator) for SAUVC competition.
* Run simulator.
* in sauvc directory run

And use arg:
```bash
simulation:=true 
```

## Missions

* For gate mission with vision use arg:
```bash
gate_vision:=true
```
* For gate mission with preset path use arg:

```bash
gate_brute:=true
```

## Other args:

- `hardware_connection:=false` - disable connection btw jetson and stm32 via serial (uart_driver) 
- `stream:=true` - enable web video stream from all cameras 
- `debug:=false` - disable image_view nodes and publishing output videos after object detection
- `file_cam:=true` - provide input videos from file
- `record_raw:=true` - enable recording video from all cameras 
- `record_output:=true` - enable recording video after object detection 