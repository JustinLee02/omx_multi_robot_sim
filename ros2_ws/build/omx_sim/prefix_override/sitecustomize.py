import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/lsoo6741/omx_multi_robot_sim/ros2_ws/install/omx_sim'
