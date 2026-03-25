# OMX Multi-Robot Simulation

MuJoCo 기반 멀티로봇 pick-and-place 시뮬레이션 환경.
9대의 ROBOTIS OMX-F 로봇이 4×4 그리드에서 물체를 조작하는 시뮬레이션을 제공하며,
ROS2 Action Server를 통해 BT(Behaviour Tree)와 연동할 수 있다.

## 시스템 구조

```
BT.xml → py_bt_ros → ROS2 Action Server → MuJoCo Simulation
                          ↓
                    /sim_state (Topic)
                          ↓
                   BT Condition Nodes
```

## 그리드 레이아웃

4×4 그리드 (16개 구역) + 9대 로봇 (내부 교차점)

```
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
```

각 로봇은 인접한 4개 구역에 접근 가능:

| 로봇 | 접근 가능 구역 |
|------|-------------|
| R1 | 1, 2, 5, 6 |
| R2 | 2, 3, 6, 7 |
| R3 | 3, 4, 7, 8 |
| R4 | 5, 6, 9, 10 |
| R5 | 6, 7, 10, 11 |
| R6 | 7, 8, 11, 12 |
| R7 | 9, 10, 13, 14 |
| R8 | 10, 11, 14, 15 |
| R9 | 11, 12, 15, 16 |

---

## 환경 요구사항

- Ubuntu 24.04
- ROS2 Jazzy
- Python 3.12
- MuJoCo 3.6+

---

## 설치 방법

### 1. ROBOTIS MuJoCo 모델 다운로드

```bash
cd ~
git clone https://github.com/ROBOTIS-GIT/robotis_mujoco_menagerie.git
```

### 2. 시스템 Python에 MuJoCo 설치

conda를 사용하지 않고 시스템 Python에 설치해야 ROS2와 호환된다.

```bash
pip install mujoco numpy --break-system-packages
```

### 3. 시뮬레이션 파일 배치

다음 파일들을 `~/robotis_mujoco_menagerie/robotis_omx/`에 넣는다:

- `generate_scene.py` — scene XML 자동 생성 스크립트
- `sim_manager.py` — 시뮬레이션 매니저 (MuJoCo 제어 코어)

```bash
cd ~/robotis_mujoco_menagerie/robotis_omx
python generate_scene.py   # multi_robot_scene.xml 생성
```

### 4. ROS2 워크스페이스 빌드

```bash
source /opt/ros/jazzy/setup.bash

mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
# omx_sim_interfaces, omx_sim 패키지를 여기에 배치

cd ~/ros2_ws
colcon build
source install/setup.bash
```

---

## 실행 방법

### MuJoCo 시뮬레이션만 실행 (ROS2 없이)

```bash
cd ~/robotis_mujoco_menagerie/robotis_omx

# 멀티로봇 데모 (9대 동시 동작 + 충돌 테스트)
python sim_manager.py --multi

# 단일 로봇 데모 (R5만)
python sim_manager.py --single

# 뷰어에서 조인트 값 찾기 (waypoint 튜닝용)
python sim_manager.py --find
```

### ROS2 Action Server 실행

**터미널 1** — Action Server + MuJoCo 뷰어:

```bash
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash
ros2 run omx_sim sim_action_server
```

**터미널 2** — 명령 전송:

```bash
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash

# Pick: 로봇 5가 구역 6에서 물체를 집는다
ros2 action send_goal /pick omx_sim_interfaces/action/Pick "{robot_id: 5, zone_id: 6}"

# Place: 로봇 5가 구역 11에 물체를 놓는다
ros2 action send_goal /place omx_sim_interfaces/action/Place "{robot_id: 5, zone_id: 11}"

# Reach: 로봇 1이 구역 2 방향으로 팔을 뻗었다 돌아온다
ros2 action send_goal /reach omx_sim_interfaces/action/Reach "{robot_id: 1, zone_id: 2}"
```

**터미널 3** — 시뮬레이션 상태 모니터링:

```bash
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash
ros2 topic echo /sim_state
```

---

## 인풋/아웃풋 형식

### Action: `/pick`

물체를 집는다. 해당 구역에 물체가 없으면 헛손질 후 실패.

**Request:**
```yaml
robot_id: 5    # 로봇 번호 (1~9)
zone_id: 6     # 구역 번호 (1~16)
```

**Result:**
```yaml
success: true/false
message: "SUCCESS" | "FAILED" | "FAIL_BUSY" | "FAIL_OUT_OF_REACH"
```

**Feedback (동작 중):**
```yaml
status: "PICKING"
```

### Action: `/place`

들고 있는 물체를 놓는다. 물체를 들고 있지 않으면 실패.

**Request:**
```yaml
robot_id: 5    # 로봇 번호 (1~9)
zone_id: 11    # 구역 번호 (1~16)
```

**Result:**
```yaml
success: true/false
message: "SUCCESS" | "FAIL_BUSY" | "FAIL_OUT_OF_REACH" | "FAIL_NOT_HOLDING" | "FAIL_ZONE_OCCUPIED"
```

**Feedback (동작 중):**
```yaml
status: "PLACING"
```

### Action: `/reach`

물체를 잡지 않고 해당 구역으로 팔을 뻗었다 돌아온다.

**Request:**
```yaml
robot_id: 1    # 로봇 번호 (1~9)
zone_id: 2     # 구역 번호 (1~16)
```

**Result:**
```yaml
success: true/false
message: "SUCCESS" | "FAIL_BUSY" | "FAIL_OUT_OF_REACH"
```

### Topic: `/sim_state`

시뮬레이션 상태를 1초마다 JSON으로 발행. BT의 Condition Node에서 사용.

**메시지 타입:** `std_msgs/String`

**데이터 형식 (JSON):**
```json
{
  "zone_objects": {
    "1": "obj_zone1",
    "11": "obj_zone11",
    "16": "obj_zone16"
  },
  "robot_states": {
    "1": {
      "holding": null,
      "adjacent_zones": [1, 2, 5, 6],
      "status": "IDLE",
      "target_zone": null
    },
    "5": {
      "holding": "obj_zone6",
      "adjacent_zones": [6, 7, 10, 11],
      "status": "PICKING",
      "target_zone": 6
    }
  }
}
```

**주요 필드:**
- `zone_objects`: 어느 구역에 어떤 물체가 있는지
- `robot_states.holding`: 로봇이 들고 있는 물체 이름 (없으면 null)
- `robot_states.status`: IDLE / PICKING / PLACING / REACHING
- `robot_states.target_zone`: 현재 동작의 목표 구역 (없으면 null)

---

## 충돌 감지

두 로봇이 동시에 같은 구역에 접근하면 충돌로 판정된다.

- 충돌은 dispatch 시점이 아니라 **도달 시점**(그리퍼가 닫히는 순간)에 감지
- 충돌 시 **양쪽 로봇 모두** 물체를 잡지 못하고 빈손으로 복귀
- 터미널에 `[COLLISION] Robot X & Robot Y collided at Zone Z!` 로그 출력

---

## 파일 구조

```
robotis_mujoco_menagerie/robotis_omx/
├── assets/                        # OMX 3D 메시 파일 (ROBOTIS 제공)
├── omx.xml                        # OMX 로봇 모델 (ROBOTIS 제공)
├── scene.xml                      # 기본 scene (ROBOTIS 제공)
├── generate_scene.py              # 멀티로봇 scene 생성기
├── multi_robot_scene.xml          # 생성된 4x4 그리드 scene
└── sim_manager.py                 # 시뮬레이션 매니저

ros2_ws/src/
├── omx_sim_interfaces/            # ROS2 인터페이스 (Action 정의)
│   ├── action/
│   │   ├── Pick.action
│   │   ├── Place.action
│   │   └── Reach.action
│   ├── CMakeLists.txt
│   └── package.xml
└── omx_sim/                       # ROS2 노드 패키지
    ├── omx_sim/
    │   ├── __init__.py
    │   └── sim_action_server.py   # Action Server + State Publisher
    ├── package.xml
    ├── setup.py
    └── setup.cfg
```

---

## 설정 변경

### 그리드 크기 변경

`generate_scene.py`에서 `CELL_SIZE` 수정 후 재생성:

```python
CELL_SIZE = 0.4  # 40cm per cell (기본값 0.2)
```

```bash
python generate_scene.py
```

### 초기 물체 배치 변경

`generate_scene.py`에서 `TEST_OBJECT_ZONES` 수정:

```python
TEST_OBJECT_ZONES = [1, 6, 11, 16]  # 원하는 구역 번호
```

### 상자 크기 변경

`generate_scene.py`의 `generate_object` 함수에서 `size` 수정:

```python
size="0.025 0.025 0.025"  # half-size (실제 크기 5cm x 5cm x 5cm)
```
