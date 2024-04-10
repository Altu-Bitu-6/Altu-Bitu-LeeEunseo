#include <iostream>
#include <deque>

using namespace std;

// 승자를 판단하여 결과를 출력하는 함수
void Judge(const deque<int>& doDeque, const deque<int>& suDeque) {
    if (doDeque.size() > suDeque.size()) cout << "do\n"; // 도도의 승리
    else if (doDeque.size() < suDeque.size()) cout << "su\n"; // 수연의 승리
    else cout << "dosu\n"; // 무승부
}


void RingTheBell(deque<int>& winGround, deque<int>& loseGround, deque<int>& winDeque) {
    while (!loseGround.empty()) { // 진 사람 덱을 먼저 합치기
        winDeque.push_back(loseGround.back());
        loseGround.pop_back();
    }
    while (!winGround.empty()) { // 남은 자기 덱(이긴 사람 덱)을 뒤에 합치기
        winDeque.push_back(winGround.back());
        winGround.pop_back();
    }
}

void HalliGalli(deque<int>& doDeque, deque<int>& suDeque, int M) {
    deque<int> doGround;
    deque<int> suGround;

    // 카드 순서대로 각자 그라운드에 내려놓기
    for (int i = 0; i < M; ++i) {
        if (i % 2 == 0) { // 도도의 차례
            doGround.push_front(doDeque.front());
            doDeque.pop_front();
            if(doDeque.empty()) {
                break;
            }
        } else { // 수연이의 차례
            suGround.push_front(suDeque.front());
            suDeque.pop_front();
            if(suDeque.empty()) {
                break;
            }
        }

        // 종을 치는 조건
        if ((!doGround.empty() && doGround.front() == 5) || (!suGround.empty() && suGround.front() == 5)) {
            RingTheBell(doGround, suGround, doDeque);  // 도도: 그라운드에 나와 있는 각각의 카드 더미 중 가장 위에 위치한 카드의 숫자가 5가 나오는 순간
        }else if (!doGround.empty() && !suGround.empty() && (doGround.front() + suGround.front() == 5)) {
            RingTheBell(suGround, doGround, suDeque); // 수연이: 양쪽 그라운드 모두에 카드가 있고 + 그라운드에 나와 있는 각각의 카드 더미에서 가장 위에 위치한 카드의 숫자 합이 5가 되는 순간
        }
    }
    Judge(doDeque, suDeque);
}


int main() {
    int N, M;
    cin >> N >> M;

    deque<int> doDeque, suDeque;

    for (int i = 0; i < N; ++i) {
        int dodo, suyeon;
        cin >> dodo >> suyeon;
        doDeque.push_front(dodo);
        suDeque.push_front(suyeon);
    }

    HalliGalli(doDeque, suDeque, M);

    return 0;
}

// && (!doDeque.empty() || !suDeque.empty())