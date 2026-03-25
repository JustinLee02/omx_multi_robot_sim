cmake_minimum_required(VERSION 3.8)
project(omx_sim_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Pick.action"
  "action/Place.action"
  "action/Reach.action"
)

ament_package()
