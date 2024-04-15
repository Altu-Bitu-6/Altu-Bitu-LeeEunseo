#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K; // 참외 개수
    cin >> K;

    vector<int> dir(6);    // 방향 저장 벡터
    vector<int> len(6);    // 길이 저장 벡터

    for (int i = 0; i < 6; i++) {
        cin >> dir[i] >> len[i];
    }

    // 전체 면적 rngkrl
    // L1 * L2 + L3 * L4 + L5 * L6 - (L2 * L3 + L4 * L5 + L6 * L1)
    // 작은 사각형 위치 찾기 (구멍 찾기)
    int big_area = 0;
    int small_area = 0;
    int index_for_small = 0;

    // 대형 직사각형 넓이
    for (int i = 0; i < 6; i++) {
        big_area = max(big_area, len[i] * len[(i + 1) % 6]);
    }

    // 참외밭의 구조: 큰 직사각형에서 작은 직사각형이 하나 빠져나간 형태
    // 구멍의 위치: 각 방향의 반대쪽 길이를 가지는 인덱스 찾기    cf. (3, 4) (1, 2) (5, 6) 처럼 2개씩 묶어서 생각
    for (int i = 0; i < 6; i++) {
        if (len[i] * len[(i + 1) % 6] == big_area) {
            // 구멍 찾기: 큰 네모의 변을 가지는 인덱스 발견
            index_for_small = (i + 3) % 6; // 큰 직사각형을 구성하는 한 변 인덱스 + 3 모듈로 6
            small_area = len[index_for_small] * len[(index_for_small + 1) % 6];
            break;
        }
    }

    int melon_count = K * (big_area - small_area);
    cout << melon_count << "\n";

    return 0;
}
