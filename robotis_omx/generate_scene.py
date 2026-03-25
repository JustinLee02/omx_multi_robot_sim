"""
Generate MuJoCo scene XML for the multi-robot pick-and-place environment.

Layout:
  4x4 grid (16 zones), each 0.2m x 0.2m
  9 OMX-F robots at internal grid intersections
  Zone numbering: left-to-right, top-to-bottom (1-16)
  Robot numbering: left-to-right, top-to-bottom (R1-R9)

  Top-down view (Y increases downward in this diagram, but in MuJoCo Y is horizontal):
  
    C1    C2    C3    C4
  ┌─────┬─────┬─────┬─────┐
  │  1  │  2  │  3  │  4  │
  ├──R1─┼──R2─┼──R3─┤
  │  5  │  6  │  7  │  8  │
  ├──R4─┼──R5─┼──R6─┤
  │  9  │ 10  │ 11  │ 12  │
  ├──R7─┼──R8─┼──R9─┤
  │ 13  │ 14  │ 15  │ 16  │
  └─────┴─────┴─────┴─────┘

Coordinate system (MuJoCo default):
  X: left-right (columns)
  Y: front-back (rows)  
  Z: up

  Grid origin at (0, 0), zone 1 center at (0.1, 0.7)
  X: col * 0.2 + 0.1
  Y: (3 - row) * 0.2 + 0.1  (inverted so row 0 is at top = high Y)
"""

import os

CELL_SIZE = 0.4  # 40cm per cell
GRID_COLS = 4
GRID_ROWS = 4
NUM_ROBOTS = 9

# Test objects: place boxes in zones 1, 6, 11, 16 (diagonal)
TEST_OBJECT_ZONES = [1, 6, 11, 16]


def zone_center(zone_id):
    """Get (x, y) center of a zone (1-indexed)."""
    idx = zone_id - 1
    col = idx % GRID_COLS
    row = idx // GRID_COLS
    x = col * CELL_SIZE + CELL_SIZE / 2
    y = (GRID_ROWS - 1 - row) * CELL_SIZE + CELL_SIZE / 2
    return x, y


def robot_position(robot_id):
    """Get (x, y) position of a robot (1-indexed, at internal intersections)."""
    idx = robot_id - 1
    col = idx % 3  # 0, 1, 2
    row = idx // 3  # 0, 1, 2
    x = (col + 1) * CELL_SIZE  # intersections at 0.2, 0.4, 0.6
    y = (GRID_ROWS - 1 - row) * CELL_SIZE  # intersections at 0.6, 0.4, 0.2
    return x, y


def robot_adjacent_zones(robot_id):
    """Get the 4 zone IDs adjacent to a robot."""
    idx = robot_id - 1
    col = idx % 3
    row = idx // 3
    top_left = row * GRID_COLS + col + 1
    return [top_left, top_left + 1, top_left + GRID_COLS, top_left + GRID_COLS + 1]


def generate_robot_body(robot_id, x, y):
    """Generate XML for one OMX robot with prefixed names."""
    prefix = f"r{robot_id}_"
    return f"""
    <!-- OMX Robot {robot_id} at ({x:.2f}, {y:.2f}) -->
    <body name="{prefix}link0" pos="{x:.3f} {y:.3f} 0" childclass="omx">
      <inertial pos="-1.441250800e-02 -3.149887900e-03 1.927659900e-02" quat="1.0 0.0 0.0 0.0" mass="2.238905100e-01" diaginertia="0.00035680461 0.00021941932 0.00045575899"/>
      <geom mesh="follower_01_base" class="visual"/>
      <geom mesh="follower_01_base" class="collision"/>
      <body name="{prefix}link1" pos="-0.01125 0 0.034">
        <inertial pos="-6.223620500e-06 6.049232000e-04 4.741880300e-02" quat="1.0 0.0 0.0 0.0" mass="6.598704100e-02" diaginertia="2.1731667e-05 2.1351513e-05 1.1657955e-05"/>
        <joint name="{prefix}Joint1" class="Joint1"/>
        <geom mesh="follower_02_base_tilt_Revised" class="visual"/>
        <geom mesh="follower_02_base_tilt_Revised" class="collision"/>
        <body name="{prefix}link2" pos="0 0 0.0635">
          <inertial pos="1.808991600e-02 2.977875800e-04 9.900545200e-02" quat="1.0 0.0 0.0 0.0" mass="8.722147100e-02" diaginertia="0.00010307915 0.00012086327 4.1993677e-05"/>
          <joint name="{prefix}Joint2" class="Joint2"/>
          <geom mesh="follower_03_middle_verticle" class="visual"/>
          <geom mesh="follower_03_middle_verticle" class="collision"/>
          <body name="{prefix}link3" pos="0.0415 0 0.11315">
            <inertial pos="8.739860200e-02 4.131006500e-04 -3.582921000e-03" quat="1.0 0.0 0.0 0.0" mass="8.375912900e-02" diaginertia="1.5203101e-05 0.00022606158 0.00023066887"/>
            <joint name="{prefix}Joint3" class="Joint3"/>
            <geom mesh="follower_04_middle_horizontal" class="visual"/>
            <geom mesh="follower_04_middle_horizontal" class="collision"/>
            <body name="{prefix}link4" pos="0.162 0 0">
              <inertial pos="2.323498000e-02 6.773537800e-05 5.976131200e-03" quat="1.0 0.0 0.0 0.0" mass="2.997506300e-02" diaginertia="5.099513e-06 7.0990471e-06 6.3119495e-06"/>
              <joint name="{prefix}Joint4" class="Joint4"/>
              <geom mesh="follower_05_tip" class="visual"/>
              <geom mesh="follower_05_tip" class="collision"/>
              <body name="{prefix}link5" pos="0.0287 0 0">
                <inertial pos="2.807240700e-02 2.413594100e-05 1.352891400e-02" quat="1.0 0.0 0.0 0.0" mass="4.381088700e-02" diaginertia="2.3694459e-05 2.3236924e-05 7.1806291e-06"/>
                <joint name="{prefix}Joint5" class="Joint5"/>
                <geom mesh="follower_06_pan_Revised" class="visual"/>
                <geom mesh="follower_06_pan_Revised" class="collision"/>
                <body name="{prefix}link6" pos="0.0295 0.0075 0">
                  <inertial pos="1.616456500e-02 1.273103200e-03 2.729159800e-04" quat="1.0 0.0 0.0 0.0" mass="1.209067700e-02" diaginertia="2.7083287e-06 6.8733728e-06 4.6941881e-06"/>
                  <joint name="{prefix}Gripper" class="Gripper"/>
                  <geom mesh="follower_07_gripper_motorized" class="visual"/>
                  <geom mesh="follower_07_gripper_motorized" class="collision"/>
                </body>
                <body name="{prefix}link7" pos="0.0295 -0.0108 0">
                  <inertial pos="1.616456500e-02 1.273103200e-03 2.729159800e-04" quat="1.0 0.0 0.0 0.0" mass="1.209067700e-02" diaginertia="2.7083287e-06 6.8733728e-06 4.6941881e-06"/>
                  <joint name="{prefix}Gripper_mimic" class="Gripper_mimic"/>
                  <geom mesh="follower_08_gripper_gear" class="visual"/>
                  <geom mesh="follower_08_gripper_gear" class="collision"/>
                </body>
              </body>
            </body>
          </body>
        </body>
      </body>
    </body>"""


def generate_actuators(robot_id):
    """Generate actuator XML for one robot."""
    prefix = f"r{robot_id}_"
    return f"""
    <position class="Joint1" name="{prefix}Joint1" joint="{prefix}Joint1" inheritrange="1"/>
    <position class="Joint2" name="{prefix}Joint2" joint="{prefix}Joint2" inheritrange="1"/>
    <position class="Joint3" name="{prefix}Joint3" joint="{prefix}Joint3" inheritrange="1"/>
    <position class="Joint4" name="{prefix}Joint4" joint="{prefix}Joint4" inheritrange="1"/>
    <position class="Joint5" name="{prefix}Joint5" joint="{prefix}Joint5" inheritrange="1"/>
    <position class="Gripper" name="{prefix}Gripper" joint="{prefix}Gripper" inheritrange="1"/>"""


def generate_contacts(robot_id):
    """Generate contact exclusion XML for one robot."""
    prefix = f"r{robot_id}_"
    return f"""
    <exclude body1="{prefix}link0" body2="{prefix}link1"/>
    <exclude body1="{prefix}link5" body2="{prefix}link6"/>
    <exclude body1="{prefix}link5" body2="{prefix}link7"/>
    <exclude body1="{prefix}link6" body2="{prefix}link7"/>"""


def generate_equality(robot_id):
    """Generate equality constraint for gripper mimic."""
    prefix = f"r{robot_id}_"
    return f'    <joint joint1="{prefix}Gripper_mimic" joint2="{prefix}Gripper" polycoef="0 -1 0 0 0"/>'


def generate_zone_label(zone_id):
    """Generate a visual label for a zone on the ground."""
    x, y = zone_center(zone_id)
    # Alternate colors for checkerboard pattern
    idx = zone_id - 1
    col = idx % GRID_COLS
    row = idx // GRID_COLS
    if (row + col) % 2 == 0:
        rgba = "0.75 0.82 0.90 1"  # light blue
    else:
        rgba = "0.55 0.65 0.78 1"  # darker blue

    return f"""
    <!-- Zone {zone_id} -->
    <geom name="zone_{zone_id}" type="box" size="{CELL_SIZE/2 - 0.002:.4f} {CELL_SIZE/2 - 0.002:.4f} 0.001"
          pos="{x:.3f} {y:.3f} 0.001" rgba="{rgba}" contype="0" conaffinity="0"/>
    <site name="zone_{zone_id}_label" type="sphere" size="0.001"
          pos="{x:.3f} {y:.3f} 0.002" rgba="0 0 0 0"/>"""


def generate_grid_lines():
    """Generate grid boundary lines."""
    lines = []
    total_w = GRID_COLS * CELL_SIZE
    total_h = GRID_ROWS * CELL_SIZE

    # Horizontal lines
    for row in range(GRID_ROWS + 1):
        y = row * CELL_SIZE
        lines.append(
            f'    <geom type="box" size="{total_w/2:.3f} 0.002 0.002" '
            f'pos="{total_w/2:.3f} {y:.3f} 0.002" rgba="0.3 0.3 0.3 1" '
            f'contype="0" conaffinity="0"/>'
        )

    # Vertical lines
    for col in range(GRID_COLS + 1):
        x = col * CELL_SIZE
        lines.append(
            f'    <geom type="box" size="0.002 {total_h/2:.3f} 0.002" '
            f'pos="{x:.3f} {total_h/2:.3f} 0.002" rgba="0.3 0.3 0.3 1" '
            f'contype="0" conaffinity="0"/>'
        )

    return "\n".join(lines)


def generate_object(zone_id, obj_idx):
    """Generate a graspable box object in a zone."""
    x, y = zone_center(zone_id)
    colors = [
        "0.9 0.2 0.2 1",   # red
        "0.2 0.2 0.9 1",   # blue
        "0.9 0.9 0.2 1",   # yellow
        "0.9 0.5 0.1 1",   # orange
    ]
    color = colors[obj_idx % len(colors)]
    return f"""
    <!-- Object in zone {zone_id} -->
    <body name="obj_zone{zone_id}" pos="{x:.3f} {y:.3f} 0.015">
      <freejoint name="obj_zone{zone_id}_joint"/>
      <geom name="obj_zone{zone_id}_geom" type="box" size="0.025 0.025 0.025"
            rgba="{color}" mass="0.01" friction="2 0.01 0.001" condim="6"/>
    </body>"""


def generate_scene():
    """Generate the complete scene XML."""

    # --- Robots ---
    robot_bodies = []
    robot_actuators = []
    robot_contacts = []
    robot_equalities = []

    for rid in range(1, NUM_ROBOTS + 1):
        x, y = robot_position(rid)
        robot_bodies.append(generate_robot_body(rid, x, y))
        robot_actuators.append(generate_actuators(rid))
        robot_contacts.append(generate_contacts(rid))
        robot_equalities.append(generate_equality(rid))

    # --- Zones ---
    zone_labels = []
    for zid in range(1, 17):
        zone_labels.append(generate_zone_label(zid))

    # --- Grid lines ---
    grid_lines = generate_grid_lines()

    # --- Objects ---
    objects = []
    for i, zid in enumerate(TEST_OBJECT_ZONES):
        objects.append(generate_object(zid, i))

    # --- Keyframe ---
    num_robot_joints = NUM_ROBOTS * 7  # 5 joints + gripper + gripper_mimic per robot
    num_object_joints = len(TEST_OBJECT_ZONES) * 7  # freejoint = 3 pos + 4 quat
    total_qpos = num_robot_joints + num_object_joints
    # Don't use keyframe to avoid qpos mismatch issues

    # --- Assemble ---
    xml = f"""<mujoco model="multi_robot_grid">
  <compiler angle="radian" meshdir="assets/"/>

  <option cone="elliptic" impratio="10"/>

  <statistic center="0.4 0.4 0.15" extent="0.8"/>

  <visual>
    <headlight diffuse="0.6 0.6 0.6" ambient="0.3 0.3 0.3" specular="0 0 0"/>
    <rgba haze="0.15 0.25 0.35 1"/>
    <global azimuth="180" elevation="-45"/>
  </visual>

  <asset>
    <material name="black" rgba="0.1 0.1 0.1 1"/>
    <texture type="skybox" builtin="gradient" rgb1="0.3 0.5 0.7" rgb2="0 0 0" width="512" height="3072"/>

    <mesh name="follower_01_base" file="follower_01_base.stl" scale="0.001 0.001 0.001"/>
    <mesh name="follower_02_base_tilt_Revised" file="follower_02_base_tilt_Revised.stl" scale="0.001 0.001 0.001"/>
    <mesh name="follower_03_middle_verticle" file="follower_03_middle_verticle.stl" scale="0.001 0.001 0.001"/>
    <mesh name="follower_04_middle_horizontal" file="follower_04_middle_horizontal.stl" scale="0.001 0.001 0.001"/>
    <mesh name="follower_05_tip" file="follower_05_tip.stl" scale="0.001 0.001 0.001"/>
    <mesh name="follower_06_pan_Revised" file="follower_06_pan_Revised.stl" scale="0.001 0.001 0.001"/>
    <mesh name="follower_07_gripper_motorized" file="follower_07_gripper_motorized.stl" scale="0.001 0.001 0.001"/>
    <mesh name="follower_08_gripper_gear" file="follower_08_gripper_gear.stl" scale="0.001 0.001 0.001"/>
  </asset>

  <default>
    <default class="omx">
      <joint frictionloss="0.1" armature="0.1"/>
      <position kp="50" dampratio="1" forcerange="-3.5 3.5"/>
      <default class="Joint1">
        <joint axis="0 0 1" range="-4.712389 6.283185"/>
      </default>
      <default class="Joint2">
        <joint axis="0 1 0" range="-2.094395 1.570796"/>
      </default>
      <default class="Joint3">
        <joint axis="0 1 0" range="-2.094395 1.570796"/>
      </default>
      <default class="Joint4">
        <joint axis="0 1 0" range="-1.745329 1.745329"/>
      </default>
      <default class="Joint5">
        <joint axis="1 0 0" range="-4.712389 4.712389"/>
      </default>
      <default class="Gripper">
        <joint axis="0 0 1" range="0 1.745329"/>
      </default>
      <default class="Gripper_mimic">
        <joint axis="0 0 1" range="-1.745329 0"/>
      </default>
      <default class="visual">
        <geom type="mesh" contype="0" conaffinity="0" density="0" group="2" material="black"/>
      </default>
      <default class="collision">
        <geom group="3" type="mesh" material="black"/>
      </default>
    </default>
  </default>

  <worldbody>
    <!-- Lights -->
    <light pos="0.4 0.4 2.0" dir="0 0 -1" directional="true" castshadow="false" diffuse="0.5 0.5 0.5"/>
    <light pos="0.4 0.4 1.0" dir="0 0 -1" diffuse="0.3 0.3 0.3" specular="0.1 0.1 0.1"/>

    <!-- Ground plane -->
    <geom name="floor" size="2 2 0.05" type="plane" rgba="0.4 0.45 0.5 1"/>

    <!-- Grid lines -->
{grid_lines}

    <!-- Zone labels -->
{"".join(zone_labels)}

    <!-- Robots -->
{"".join(robot_bodies)}

    <!-- Objects -->
{"".join(objects)}
  </worldbody>

  <actuator>
{"".join(robot_actuators)}
  </actuator>

  <contact>
{"".join(robot_contacts)}
  </contact>

  <equality>
{"".join(robot_equalities)}
  </equality>

</mujoco>
"""
    return xml


def print_layout_info():
    """Print zone and robot positions for reference."""
    print("=" * 50)
    print("  Grid Layout Reference")
    print("=" * 50)
    print("\nZone positions (center):")
    for zid in range(1, 17):
        x, y = zone_center(zid)
        print(f"  Zone {zid:2d}: ({x:.3f}, {y:.3f})")

    print("\nRobot positions (intersection):")
    for rid in range(1, 10):
        x, y = robot_position(rid)
        zones = robot_adjacent_zones(rid)
        print(f"  Robot {rid}: ({x:.3f}, {y:.3f}) -> Zones {zones}")

    print("\nTest objects in zones:", TEST_OBJECT_ZONES)


if __name__ == "__main__":
    print_layout_info()

    xml = generate_scene()

    output_path = "multi_robot_scene.xml"
    with open(output_path, "w") as f:
        f.write(xml)

    print(f"\nScene XML written to: {output_path}")
    print(f"To view: python -m mujoco.viewer --mjcf {output_path}")
