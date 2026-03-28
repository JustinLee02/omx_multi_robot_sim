"""
Behavior Tree(BT)의 하이레벨 명령(Pick, Place, Reach)을 
Low-level 조인트 각도와 시간(duration), 그리고 어떤 Action을 호출할지(action) 시퀀스로 변환해주는 라이브러리입니다.
"""

import math

# ──────────────────────────────────────────────
# 환경 설정 및 로봇 상수
# ──────────────────────────────────────────────
CELL_SIZE = 0.4

# Grasp 자세 조인트 값 (J2, J3, J4, J5)
GRASP_J2 = 0.38
GRASP_J3 = 0.0
GRASP_J4 = 0.558
GRASP_J5 = 0.0

# 그리퍼 상태 값
GRIPPER_OPEN = 0.916
GRIPPER_CLOSE = 0.0

# 기본 대기(Home) 자세
HOME = [0.0, 0.0, 0.0, 0.0, 0.0, GRIPPER_OPEN]


# ──────────────────────────────────────────────
# 내부 좌표 및 각도 계산 로직
# ──────────────────────────────────────────────
def _zone_center(zone_id):
    """특정 zone의 중심 (x, y) 좌표를 계산합니다."""
    idx = zone_id - 1
    col = idx % 4
    row = idx // 4
    x = col * CELL_SIZE + CELL_SIZE / 2
    y = (3 - row) * CELL_SIZE + CELL_SIZE / 2
    return x, y

def _robot_position(robot_id):
    """특정 로봇의 베이스 (x, y) 좌표를 계산합니다."""
    idx = robot_id - 1
    col = idx % 3
    row = idx // 3
    x = (col + 1) * CELL_SIZE
    y = (3 - row) * CELL_SIZE
    return x, y

def _calculate_j1(robot_id, zone_id):
    """해당 구역(zone)을 바라보기 위한 로봇의 J1(몸통 회전) 각도를 계산합니다."""
    zx, zy = _zone_center(zone_id)
    rx, ry = _robot_position(robot_id)
    return math.atan2(zy - ry, zx - rx)


# ──────────────────────────────────────────────
# 하이레벨 명령 ➔ 조인트 시퀀스 변환 함수들
# ──────────────────────────────────────────────
def get_pick_sequence(robot_id, zone_id):
    """
    Pick 명령에 대한 시퀀스를 반환합니다.
    물건을 잡는 순간에만 'pick' 액션을 사용하고 나머지는 'reach'로 이동합니다.
    """
    j1 = _calculate_j1(robot_id, zone_id)
    
    return [
        {"action": "reach", "joints": HOME, "duration": 1.0},
        {"action": "reach", "joints": [j1, 0.0, 0.0, 0.0, 0.0, GRIPPER_OPEN], "duration": 1.5},
        {"action": "reach", "joints": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_OPEN], "duration": 2.0},
        # ⚠️ 여기서 물건을 잡습니다 (지훈님 서버의 attach 로직 발동)
        {"action": "pick",  "joints": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_CLOSE], "duration": 1.0},
        {"action": "reach", "joints": [j1, 0.1, 0.0, 0.2, 0.0, GRIPPER_CLOSE], "duration": 1.5},
        {"action": "reach", "joints": [0.0, 0.0, 0.0, 0.0, 0.0, GRIPPER_CLOSE], "duration": 1.5}
    ]

def get_place_sequence(robot_id, zone_id):
    """
    Place 명령에 대한 시퀀스를 반환합니다.
    물건을 놓는 순간에만 'place' 액션을 사용합니다.
    """
    j1 = _calculate_j1(robot_id, zone_id)
    
    return [
        {"action": "reach", "joints": [j1, 0.0, 0.0, 0.0, 0.0, GRIPPER_CLOSE], "duration": 1.5},
        {"action": "reach", "joints": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_CLOSE], "duration": 2.0},
        # ⚠️ 여기서 물건을 놓습니다 (지훈님 서버의 detach 로직 발동)
        {"action": "place", "joints": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_OPEN], "duration": 1.0},
        {"action": "reach", "joints": [j1, 0.1, 0.0, 0.2, 0.0, GRIPPER_OPEN], "duration": 1.5},
        {"action": "reach", "joints": HOME, "duration": 1.5}
    ]

def get_reach_sequence(robot_id, zone_id):
    """Reach 명령에 대한 시퀀스(집지 않고 도달만 함)를 반환합니다. 전부 'reach' 액션을 사용합니다."""
    j1 = _calculate_j1(robot_id, zone_id)
    
    return [
        {"action": "reach", "joints": HOME, "duration": 1.0},
        {"action": "reach", "joints": [j1, 0.0, 0.0, 0.0, 0.0, GRIPPER_OPEN], "duration": 1.5},
        {"action": "reach", "joints": [j1, GRASP_J2, GRASP_J3, GRASP_J4, GRASP_J5, GRIPPER_OPEN], "duration": 2.0},
        {"action": "reach", "joints": HOME, "duration": 2.0}
    ]
