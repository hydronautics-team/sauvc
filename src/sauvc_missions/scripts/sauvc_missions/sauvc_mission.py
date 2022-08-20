#! /usr/bin/env python3

from abc import abstractmethod
from stingray_tfsm.auv_mission import AUVMission


class SAUVCMission(AUVMission):
    """ Abstract class to implement AUV missions for SAUVC competitnion """
    @abstractmethod
    def __init__(self,
                 name: str,
                 front_camera: str,
                 bottom_camera: str,
                 gate="gate",
                 red_flare="red_flare",
                 yellow_flare="yellow_flare",
                 mat="mat",
                 blue_bowl="blue_bowl",
                 red_bowl="red_bowl",
                 ):
        """ Abstract class to implement AUV missions for SAUVC competitnion

        Args:
            name (str): mission name
            front_camera (str): front camera topic
            bottom_camera (str): bottom camera topic
            gate (str, optional): gate object name. Defaults to "gate".
            red_flare (str, optional): red_flare object name. Defaults to "red_flare".
            yellow_flare (str, optional): yellow_flare object name. Defaults to "yellow_flare".
            mat (str, optional): mat object name. Defaults to "mat".
            blue_bowl (str, optional): blue_bowl object name. Defaults to "blue_bowl".
            red_bowl (str, optional): red_bowl object name. Defaults to "red_bowl".
        """
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

        self.confirmation = 5
        self.exhaust_max = 40
        super().__init__(name)
