#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main(){
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > minHeap; // 최소 힙

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int num;
            cin >> num;
            minHeap.push(num);
            // 가장 작은 원소를 제거해서 "가장 큰 N개 숫자" 유지
            if (minHeap.size() > N) {
                minHeap.pop();
            }
        }
    }

    // N번째로 큰 수 출력
    cout << minHeap.top() << "\n";

    return 0;
}
