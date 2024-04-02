#include <iostream>
#include <vector>
#include <algorithm> // max 함수 사용
using namespace std;

// 가장 긴 증가하는 부분 수열의 길이를 찾는 함수
int longestIncreasingSubsequence(vector<int>& seq) {
    size_t n = seq.size();
    vector<int> dp(n, 1); // 각 위치에서의 최대 증가 부분 수열 길이를 저장할 dp 벡터 초기화

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            // seq[j] < seq[i]인 경우, 증가 부분 수열을 만들 수 있음
            if (seq[j] < seq[i]) {
                dp[i] = max(dp[i], dp[j] + 1); // 최대 길이 갱신
            }
        }
    }

    // dp 배열에서 가장 큰 값을 찾음
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int N;
    cin >> N; // 수열 A의 크기

    vector<int> seq(N); // 수열 A를 저장할 벡터

    for (int i = 0; i < N; ++i) {
        cin >> seq[i]; // 수열 A의 원소 입력받음
    }

    cout << longestIncreasingSubsequence(seq) << "\n"; // 가장 긴 증가하는 부분 수열의 길이를 출력

    return 0;
}
