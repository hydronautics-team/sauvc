#! /bin/bash

source devel/setup.bash

WAIT=1.7
WAIT_UP=4.5

rosservice call /stingray/services/devices/updown -- 1 110
echo 'lowering'

sleep $WAIT

rosservice call /stingray/services/devices/updown -- 1 -110
echo 'lifting'

sleep  $WAIT_UP

rosservice call /stingray/services/devices/updown -- 1 0
echo 'lifting done'


