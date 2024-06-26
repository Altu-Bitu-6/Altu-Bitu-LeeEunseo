#include <iostream> // 구현, 시뮬레이션
#include <vector>
using namespace std;

void rotate(vector<int>& gear, int direction) {
    if (direction == 1) { // 시계 방향으로 회전할 경우
        int temp = gear.back(); // 마지막 원소를 임시 저장
        gear.pop_back(); // 마지막 원소를 제거
        gear.insert(gear.begin(), temp); // 임시 저장한 원소를 벡터의 시작 부분에 삽입
    } else if (direction == -1) { // 반시계 방향으로 회전할 경우
        int temp = gear.front(); // 첫 번째 원소를 임시 저장
        gear.erase(gear.begin()); // 첫 번째 원소를 제거
        gear.push_back(temp); // 임시 저장한 원소를 벡터의 마지막 부분에 삽입
    }
}

int main() {
    int T, K;
    cin >> T;
    vector<vector<int> > gear_status(T, vector<int>(8)); // 각 톱니바퀴의 현재 상태를 저장할 2차원 벡터

    for (int i = 0; i < T; i++) {
        string gear_input; // 각 톱니바퀴의 상태를 나타내는 문자열
        cin >> gear_input; // 공백 없이 연속된 숫자로 상태 입력 받음
        for (int j = 0; j < 8; j++) {
            // 문자열의 각 문자를 숫자로 변환하여 저장
            gear_status[i][j] = gear_input[j] - '0';
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        int gear_num, direction; // 회전시킬 톱니바퀴의 번호와 방향을 저장 변수
        cin >> gear_num >> direction;
        gear_num--;

        // 각 톱니바퀴의 회전 여부와 방향
        vector<int> rotate_direction(T, 0); // 초기화: 모든 톱니바퀴가 회전하지 않을 때(0)
        rotate_direction[gear_num] = direction; // 선택한 톱니바퀴를 회전 방향으로 설정

        // 선택한 톱니바퀴의 왼쪽에 있는 톱니바퀴들을 확인
        for (int j = gear_num; j > 0; j--) {
            if (gear_status[j][6] != gear_status[j-1][2]) { // 인접한 톱니바퀴가 서로 다른 극을 가지면
                rotate_direction[j-1] = -rotate_direction[j]; // 반대 방향으로 회전
            } else {
                break; // 같은 극이면 그 이후의 톱니바퀴는 영향을 받지 않음
            }
        }

        // 선택한 톱니바퀴의 오른쪽에 있는 톱니바퀴들을 확인
        for (int j = gear_num; j < T-1; j++) {
            if (gear_status[j][2] != gear_status[j+1][6]) { // 인접한 톱니바퀴가 서로 다른 극을 가지면
                rotate_direction[j+1] = -rotate_direction[j]; // 반대 방향으로 회전
            } else {
                break; // 같은 극이면 그 이후의 톱니바퀴는 영향을 받지 않음
            }
        }

        // 결정된 방향에 따라 톱니바퀴들을 회전
        for (int j = 0; j < T; j++) {
            if (rotate_direction[j] != 0) { // 회전할 경우
                rotate(gear_status[j], rotate_direction[j]); // 회전 함수를 호출
            }
        }
    }

    // 최종적으로 12시 방향이 S극인 톱니바퀴의 개수를 세어 출력
    int south_gear = 0;
    for (int i = 0; i < T; i++) {
        if (gear_status[i][0] == 1) south_gear++; // 12시 방향이 S극이면 카운트 증가
    }

    cout << south_gear << "\n"; // 결과 출력

    return 0;
}