# OMX Multi-Robot Simulation

MuJoCo 기반 멀티로봇 pick-and-place 시뮬레이션 환경.
9대의 ROBOTIS OMX-F 로봇이 4×4 그리드에서 물체를 조작하는 시뮬레이션을 제공하며,
ROS2 Action Server를 통해 BT(Behaviour Tree)와 연동할 수 있다.

---

## 디렉토리 구조

```
~/
├── robotis_mujoco_menagerie/          # ROBOTIS 공식 리포 (git clone)
│   └── robotis_omx/
│       ├── assets/                    # 3D 메시 파일 (ROBOTIS 제공)
│       ├── omx.xml                    # 로봇 모델 (ROBOTIS 제공)
│       └── scene.xml                  # 기본 scene (ROBOTIS 제공)
│
├── omx_multi_robot_sim/               # 우리 시뮬레이션 코어
│   └── robotis_omx/
│       ├── sim_manager.py             # 시뮬레이션 엔진
│       ├── generate_scene.py          # scene XML 생성기
│       ├── multi_robot_scene.xml      # 생성된 scene (generate_scene.py로 생성)
│       ├── assets -> (심볼릭 링크)
│       └── omx.xml -> (심볼릭 링크)
│
├── omx_bt_planner/                    # BT 모션 플래너 + 테스트
│   ├── bt_motion_planner.py           # 하이레벨 명령 → 조인트 시퀀스 변환
│   └── test_integration.py            # 통합 테스트 스크립트
│
└── ros2_ws/                           # ROS2 워크스페이스
    └── src/
        ├── omx_sim_interfaces/        # Action 인터페이스 정의
        │   ├── action/
        │   │   ├── Pick.action
        │   │   ├── Place.action
        │   │   └── Reach.action
        │   ├── CMakeLists.txt
        │   └── package.xml
        └── omx_sim/                   # Action Server 패키지
            ├── omx_sim/
            │   ├── __init__.py
            │   └── sim_action_server.py
            ├── resource/omx_sim
            ├── package.xml
            ├── setup.py
            └── setup.cfg
```

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

### 2. 시뮬레이션 코드 다운로드

```bash
cd ~
git clone https://github.com/JustinLee02/omx_multi_robot_sim.git
```

### 3. 심볼릭 링크 생성

MuJoCo scene이 ROBOTIS 메시 파일을 참조하므로 심볼릭 링크가 필요하다.

```bash
ln -s ~/robotis_mujoco_menagerie/robotis_omx/assets ~/omx_multi_robot_sim/robotis_omx/assets
ln -s ~/robotis_mujoco_menagerie/robotis_omx/omx.xml ~/omx_multi_robot_sim/robotis_omx/omx.xml
```

### 4. MuJoCo 설치

conda를 사용하지 않고 시스템 Python에 설치해야 ROS2와 호환된다.

```bash
pip install mujoco numpy --break-system-packages
```

### 5. Scene XML 생성

```bash
cd ~/omx_multi_robot_sim/robotis_omx
python generate_scene.py
```

### 6. ROS2 워크스페이스 빌드

```bash
source /opt/ros/jazzy/setup.bash
mkdir -p ~/ros2_ws/src
cp -r ~/omx_multi_robot_sim/ros2_ws/src/omx_sim_interfaces ~/ros2_ws/src/
cp -r ~/omx_multi_robot_sim/ros2_ws/src/omx_sim ~/ros2_ws/src/
cd ~/ros2_ws
colcon build
source install/setup.bash
```

---

## 실행 방법

### MuJoCo 데모 (ROS2 없이)

```bash
cd ~/omx_multi_robot_sim/robotis_omx

# 멀티로봇 데모 (9대 동시 동작 + 충돌 테스트)
python sim_manager.py --multi

# 단일 로봇 데모 (R5만)
python sim_manager.py --single

# 뷰어에서 조인트 값 찾기
python sim_manager.py --find
```

### ROS2 Action Server + BT 테스트

**터미널 1** — Action Server 실행:

```bash
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash
ros2 run omx_sim sim_action_server
```

**터미널 2** — 통합 테스트 (bt_motion_planner 사용):

```bash
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash
cd ~/omx_multi_robot_sim/omx_bt_planner
python3 test_integration.py
```

**터미널 2** — 상태 모니터링:

```bash
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash
ros2 topic echo /sim_state
```

---

## 그리드 레이아웃

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

## 실패 조건

### Pick

| 코드 | 의미 |
|------|------|
| FAIL_BUSY | 로봇이 다른 동작 중 |
| FAIL_INVALID_ROBOT | 존재하지 않는 robot_id |
| FAIL_NO_OBJECT | 해당 구역에 물체 없음 |
| FAIL_ALREADY_HOLDING | 이미 물체를 들고 있음 |
| FAIL_COLLISION | 다른 로봇과 같은 구역 충돌 |
| FAIL_CTRL_RANGE | 조인트 값이 허용 범위 밖 |

### Place

| 코드 | 의미 |
|------|------|
| FAIL_BUSY | 로봇이 다른 동작 중 |
| FAIL_NOT_HOLDING | 물체를 들고 있지 않음 |
| FAIL_TARGET_ZONE_OCCUPIED | 목표 구역에 이미 물체 있음 |
| FAIL_COLLISION | 다른 로봇과 같은 구역 충돌 |

---

## 충돌 감지

- 충돌은 **도달 시점**에 감지 (두 로봇 모두 동작은 시작함)
- 충돌 시 **양쪽 로봇 모두** 빈손으로 복귀
- 터미널에 COLLISION 로그 출력
