from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'marker_finder'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test', 'marker_debug']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*.launch.py'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='super_ubuntu22',
    maintainer_email='camelpoem32@gmail.com',
    description='The marker_finder package',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'marker_finder = marker_finder.marker_detector:main',
        ],
    },
)
