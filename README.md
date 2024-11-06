
# philosophers

`philosophers` 프로젝트는 **동시성 프로그래밍**을 경험하기 위해 설계된 프로젝트로, **스레드**, **뮤텍스**를 사용하여 `철학자 문제`를 해결합니다. 프로젝트는 자원의 공유와 동기화 문제를 해결하면서 스레드 안전성을 확보하는 방법을 익히는 것이 목표입니다.

## 목차
- [프로젝트 개요](#프로젝트-개요)
- [철학자 문제 설명](#철학자-문제-설명)
- [사용된 개념](#사용된-개념)
- [구현 세부 사항](#구현-세부-사항)
- [설치 방법](#설치-방법)
- [사용 방법](#사용-방법)
- [테스트](#테스트)
- [라이선스](#라이선스)

## 프로젝트 개요

이 프로젝트는 다섯 명의 철학자가 한 식탁에 앉아 있으며, 각 철학자는 생각하고, 먹고, 잠자는 활동을 반복해야 합니다. 각 철학자는 포크 두 개를 사용해야 식사를 할 수 있으며, **뮤텍스**를 통해 포크 자원을 동기화합니다. 주요 목표는 철학자들이 교착 상태(데드락)에 빠지지 않도록 하는 것입니다.

## 철학자 문제 설명

1. 다섯 명의 철학자가 원형으로 배치된 테이블에 앉아 있습니다.
2. 각 철학자 사이에는 하나의 포크가 놓여 있습니다.
3. 철학자는 식사하기 위해 양쪽의 포크를 모두 들어야 합니다.
4. 철학자는 생각 -> 식사 -> 잠자기 순서로 활동을 반복합니다.
5. 식사 중에는 다른 철학자가 포크를 사용할 수 없으므로, 동기화가 필요합니다.

## 사용된 개념

- **스레드**: 각 철학자는 독립적인 스레드로 실행되어 개별적으로 행동합니다.
- **뮤텍스(Mutex)**: 포크 자원에 대한 상호 배제를 위해 뮤텍스를 사용하여 두 철학자가 동시에 같은 포크를 사용하지 못하도록 합니다.
- **교착 상태 방지**: 철학자들이 동시에 두 포크를 들려고 할 때 발생할 수 있는 교착 상태를 방지하기 위해 특정 규칙과 타이밍을 적용합니다.

## 구현 세부 사항

- **포크 관리**: 각 포크는 뮤텍스로 보호되며, 철학자는 포크를 획득하고 반납하는 과정을 통해 자원을 독점적으로 사용합니다.
- **철학자 상태 추적**: 철학자의 상태(생각, 식사, 잠자기)를 추적하고, 상태가 변경될 때마다 해당 상태를 출력합니다.
- **시간 제한**: 철학자가 일정 시간 동안 식사하지 않으면 굶주림으로 인해 철학자가 죽습니다. 이 경우 프로그램은 종료됩니다.
- **동기화 및 상호 배제**:
  - 철학자는 양쪽 포크를 획득할 수 있을 때에만 식사를 시작합니다.
  - 교착 상태를 방지하기 위해 홀수 철학자는 왼쪽 포크를, 짝수 철학자는 오른쪽 포크를 먼저 들어 교착 상태에 빠지지 않도록 합니다.

## 설치 방법

1. 터미널에서 이 저장소를 클론합니다.
    ```bash
    git clone https://github.com/jmsmg/philosophers.git
    cd philosophers
    ```

2. 프로젝트를 빌드합니다.
    ```bash
    make
    ```

3. 컴파일이 완료되면 `philosophers` 실행 파일이 생성됩니다.

## 사용 방법

`philosophers` 프로그램을 실행하여 철학자들의 행동을 시뮬레이션합니다. 프로그램은 명령줄 인수를 통해 다양한 파라미터를 설정할 수 있습니다.

```bash
./philosophers <철학자 수> <식사 시간> <잠자는 시간> <굶주림 한계 시간> [최대 식사 횟수]
```

예를 들어, 5명의 철학자가 식사 시간 200ms, 잠자는 시간 100ms, 굶주림 한계 시간 800ms로 설정된 경우:

```bash
./philosophers 5 200 100 800
```

- `철학자 수`: 철학자의 수 (기본 5)
- `식사 시간`: 철학자가 식사를 마치기까지 걸리는 시간
- `잠자는 시간`: 철학자가 잠자기 상태에 있는 시간
- `굶주림 한계 시간`: 철학자가 일정 시간 동안 식사를 하지 않을 경우 죽는 한계 시간
- `[최대 식사 횟수]`: (선택 사항) 철학자가 식사할 최대 횟수. 이 횟수에 도달하면 철학자는 더 이상 식사하지 않습니다.
