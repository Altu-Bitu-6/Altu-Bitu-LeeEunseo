#include <iostream> // 자료 구조, 구현, 큐
#include <queue>
#include <vector>

using namespace std;

vector<int> josephus(int N, int K) {
    vector<int> result;
    queue<int> jq;

    // 큐에 1부터 N까지의 수를 넣음
    for (int i = 1; i <= N; ++i)
        jq.push(i);

    int cnt = 1;
    while (!jq.empty()) {
        // K번째 사람을 큐에서 뽑아 결과에 추가
        if (cnt == K) {
            result.push_back(jq.front());
            jq.pop();
            cnt = 1;
        } else {
            // K번째 사람이 아니면 큐의 맨 뒤로 이동
            jq.push(jq.front());
            jq.pop();
            ++cnt;
        }
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;    // 왜 무한루프?????

    vector<int> result = josephus(N, K);

    // 결과 출력
    cout << "<";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << ">" << "\n";

    return 0;
}
