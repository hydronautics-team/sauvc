#! /usr/bin/env python3

from stingray_tfsm.auv_mission import AUVMission


class SAUVCMission(AUVMission):
    def __init__(self,
                 front_camera: str,
                 bottom_camera: str,
                 gate="gate",
                 red_flare="red_flare",
                 yellow_flare="yellow_flare",
                 mat="mat",
                 blue_bowl="blue_bowl",
                 red_bowl="red_bowl",
                 ):
        super().__init__()
        # objects
        self.gate = gate
        self.red_flare = red_flare
        self.yellow_flare = yellow_flare
        self.mat = mat
        self.blue_bowl = blue_bowl
        self.red_bowl = red_bowl
        # cameras
        self.front_camera = front_camera
        self.bottom_camera = bottom_camera

        self.confirmation = 10
        self.exhaust_max = 40
