from setuptools import find_packages, setup

package_name = 'omx_sim'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Justin',
    maintainer_email='justin@todo.todo',
    description='OMX multi-robot simulation with ROS2 action servers',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'sim_action_server = omx_sim.sim_action_server:main',
            'state_publisher = omx_sim.state_publisher:main',
        ],
    },
)
