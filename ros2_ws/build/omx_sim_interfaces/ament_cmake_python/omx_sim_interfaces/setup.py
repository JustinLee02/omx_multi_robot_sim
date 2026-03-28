from setuptools import find_packages
from setuptools import setup

setup(
    name='omx_sim_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('omx_sim_interfaces', 'omx_sim_interfaces.*')),
)
