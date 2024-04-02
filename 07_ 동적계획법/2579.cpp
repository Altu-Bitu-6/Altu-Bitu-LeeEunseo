#include <iostream>
#include <vector>
#include <algorithm> // max 함수
using namespace std;

int maxScore(int numofsteps, vector<int>& scores) {
    vector<int> dp(numofsteps, 0); // 최대 점수를 저장할 dp 벡터 초기화

    dp[0] = scores[0]; // 첫 번째 계단의 점수는 그대로 가져옴
    if (numofsteps > 1)  {
        dp[1] = scores[0] + scores[1]; // 두 번째 계단까지의 최대 점수
    }
    if (numofsteps > 2) {
        dp[2] = max(scores[0], scores[1]) + scores[2]; // 세 번째 계단까지의 최대 점수
    }

    for (int i = 3; i < numofsteps; ++i) {
        // i번째 계단에 도달하는 최대 점수를 계산함
        // 두 가지 경우를 고려함:
        // 1. i-2번째 계단에서 i번째 계단으로 바로 올라온 경우
        // 2. i-3번째 계단에서 i-1번째 계단을 거쳐 i번째 계단으로 올라온 경우
        dp[i] = max(dp[i-2], dp[i-3] + scores[i-1]) + scores[i];
    }

    // 마지막 계단이나 그 전 계단에서 얻을 수 있는 최대 점수가 전체 최대 점수임
    return dp[numofsteps-1];
}

int main() {
    int N;
    cin >> N; // 계단 수

    vector<int> scores(N); // 계단별 점수를 저장할 벡터

    for (int i = 0; i < N; ++i) {
        cin >> scores[i]; // 계단별 점수를 입력받음
    }

    cout << maxScore(N, scores) << "\n"; // 최대 점수를 계산하여 출력

    return 0;
}
