/*
 * C++에서 백트래킹을 구현할 때 주로 사용하는 방법: 재귀 함수
 * 주로 문제를 해결할 때 가능한 모든 경우의 수를 탐색하면서 조건에 맞는 결과를 찾아내야 할 때 사용
 * 대표적으로 퍼즐 게임, 경로 찾기, 조합 문제의 해결 등에 활용

 [C++에서 백트래킹 구현 기본 구조]
   1. 재귀 함수 정의: 문제의 해를 찾기 위해 재귀 함수를 정의. 재귀함수는 선택된 요소를 기반으로 다음 요소의 선택 진행
   2. 종료 조건 설정: 재귀의 깊이가 일정 수준에 도달하거나, 해답을 찾았을 때 함수의 실행 종료
   3. 반복 구조 사용: 현재 선택할 수 있는 옵션들을 반복하면서 조건에 따라 재귀 함수를 호출
   4. 백트래킹 실행: 조건에 맞지 않을 경우 이전 단계로 돌아가 (재귀의 이전 단계로 되돌아가) 다른 가능성 탐색
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;  // 자연수 개수 N과 고를 개수 M
set<int> unique_elements;  // 요소 정렬 & 중복 제거
vector<int> elements;  // 수열 생성 vector
set<vector<int> > all_sequences;  // 모든 유일한 수열 저장

// 재귀 함수: 가능한 모든 수열 생성
void generateSequence(vector<int>& current) {
    if (current.size() == M) {  // 현재 수열 길이가 M일 때
        all_sequences.insert(current);  // set에 수열 추가(중복 제거)
        return;
    }

    // 사용 가능한 모든 요소에 대해 반복
    for (int elem : elements) {
        current.push_back(elem);  // 현재 수열에 요소 추가
        generateSequence(current);  // 재귀적으로 다음 요소 추가
        current.pop_back();  // 백트래킹: 마지막에 추가된 요소 제거하고 다음 요소 시도
    }
}

int main() {
    cin >> N >> M;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;  // 자연수 N개
        unique_elements.insert(input);  // 자연수 set에 추가 (자동 중복 제거 및 정렬)
    }

    // set의 모든 요소를 vector로 이동
    elements.assign(unique_elements.begin(), unique_elements.end());  // set을 vector로 변환

    vector<int> current;  // 현재 구성 중인 수열을 저장할 임시 vector
    generateSequence(current);  // 수열 생성 함수를 호출하여 모든 가능한 수열을 생성

    // set에 저장된 모든 수열을 출력
    for (const auto& seq : all_sequences) {  // all_sequences의 모든 vector 순회
        for (int num : seq) {  // 각 vector의 모든 요소 순회
            cout << num << " ";  // 요소 출력
        }
        cout << "\n";  // 한 수열이 끝날 때마다 줄바꿈
    }

    return 0;
}
