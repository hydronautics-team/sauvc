#! /bin/bash

source devel/setup.bash

rosservice call /stingray/services/devices/updown -- 4 50 
sleep 0.3
echo 'sweeping'
rosservice call /stingray/services/devices/updown -- 4 100
sleep 0.3
rosservice call /stingray/services/devices/updown -- 4 50 
sleep 0.3
rosservice call /stingray/services/devices/updown -- 4 100
echo 'done'


