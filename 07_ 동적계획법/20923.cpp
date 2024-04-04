#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>

using namespace std;

void RingTheBell(stack<int>& winGround, stack<int>& loseGround, deque<int>& Deque) {
    while (!winGround.empty()) {
        Deque.push_front(winGround.top());
        winGround.pop();
    }
    while (!loseGround.empty()) {
        Deque.push_back(loseGround.top());
        loseGround.pop();
    }
}

void HalliGalli(deque<int>& doDeque, deque<int>& suDeque, int M) {
    stack<int> doGround; // 도도의 그라운드 스택
    stack<int> suGround; // 수연이의 그라운드 스택

    int rounds = min(M, min(static_cast<int>(doDeque.size()), static_cast<int>(suDeque.size())));

    for(int i = 0; i < rounds; ++i) {
        doGround.push(doDeque.front()); // 도도 그라운드에 카드 내려놓기
        doDeque.pop_front(); // 도도 덱에서 카드 삭제하기
        suGround.push(suDeque.front()); // 수연이 그라운드에 카드 내려놓기
        suDeque.pop_front(); // 수연이 덱에서 카드 삭제하기

        if (!doGround.empty() && !suGround.empty()) {
            if (doGround.top() + suGround.top() == 5) { // 수연이가 종 칠 때
                RingTheBell(suGround, doGround, suDeque);
            } else if (doGround.top() == 5 || suGround.top() == 5) { // 도도가 종 칠 때
                RingTheBell(doGround, suGround, doDeque);
            }
        }
    }

    int doRemaining = doDeque.size(); // 남은 도도의 카드 수
    int suRemaining = suDeque.size(); // 남은 수연의 카드 수

    if (doRemaining == 0 && suRemaining == 0) { // 둘 다 비었을 경우
        cout << "dosu" << "\n";
    } else if (doRemaining == 0) { // 도도의 덱만 비었을 경우
        cout << "su" << "\n";
    } else if (suRemaining == 0) { // 수연의 덱만 비었을 경우
        cout << "do" << "\n";
    } else if (doRemaining > suRemaining) { // 게임 진행 후 도도의 덱에 카드가 더 많을 경우
        cout << "do" << "\n";
    } else if (doRemaining < suRemaining) { // 게임 진행 후 수연의 덱에 카드가 더 많을 경우
        cout << "su" << "\n";
    } else { // 덱의 크기가 같을 경우
        cout << "dosu" << "\n"; // 비긴 경우 "dosu" 출력
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    deque<int> doDeque; // 도도 덱
    deque<int> suDeque; // 수연이 덱

    for(int i = 0; i < N; ++i) {
        int dodo, suyeon;
        cin >> dodo >> suyeon;
        doDeque.push_back(dodo);
        suDeque.push_back(suyeon);
    }

    HalliGalli(doDeque, suDeque, M);

    return 0;
}
