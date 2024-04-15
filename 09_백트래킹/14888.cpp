/*

             [1]
             /|\
            / | \
          [-] [+] [*]
          /     |     \
       [-1]    [3]    [2]   <-- 첫 번째 단계: 각각 -1, 3, 2 계산
       / \     / \     / \
     [+] [*] [+] [*] [+] [*]
     /    |   /    |  /    |
   [2]  [-3] [6]  [0] [5] [6]    <-- 두 번째 단계: 각 조합 계산

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;  // 수열 A1, A2, ..., AN 개수
vector<int> nums;
int max_result = INT_MIN;
int min_result = INT_MAX;
int add, sub, mul, div_;

void eqMaxMin(int idx, int current) {
    if (idx == N) {
        max_result = max(max_result, current);
        min_result = min(min_result, current);
        return;
    }

    /*
     * { 백트래킹 구현 }
     * 각 연산자의 사용 횟수 (add, sub, mul, div)를 재귀 호출 전에 감소
     * 호출이 완료된 후에는 원래 값으로 복원
     */
    if (add > 0) {
        add--;
        eqMaxMin(idx + 1, current + nums[idx]);
        add++;
    }
    if (sub > 0) {
        sub--;
        eqMaxMin(idx + 1, current - nums[idx]);
        sub++;
    }
    if (mul > 0) {
        mul--;
        eqMaxMin(idx + 1, current * nums[idx]);
        mul++;
    }
    if (div_ > 0) {
        div_--;
        // C++14 표준에 따른 정수 나눗셈
        int next = (current < 0 && nums[idx] > 0) || (current > 0 && nums[idx] < 0) ? -abs(current) / abs(nums[idx]) : abs(current) / abs(nums[idx]);
        eqMaxMin(idx + 1, next);
        div_++;
    }
}

int main() {
    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    cin >> add >> sub >> mul >> div_;

    eqMaxMin(1, nums[0]);  // 첫 번째 숫자를 결과로 초기화하고 시작

    cout << max_result << "\n" << min_result;
    return 0;
}
