#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> relations; // 각 사람들 간의 관계를 나타내는 그래프
vector<bool> visited; // 방문 여부 확인
vector<int> dst; // 각 사람까지의 촌수 (거리)

// 촌수 계산 함수
int calculateKinship(int start, int target, int n) {
    fill(visited.begin(), visited.end(), false);
    fill(dst.begin(), dst.end(), -1);

    queue<int> q;
    visited[start] = true;
    dst[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : relations[current]) {
            if (!visited[next]) {
                visited[next] = true;
                dst[next] = dst[current] + 1;
                q.push(next);
            }
        }
    }

    return dst[target]; // 목표 사람까지의 촌수 반환
}

int main() {
    int people, p_1, p_2, r_num;
    cin >> people >> p_1 >> p_2 >> r_num; // 사람 수, 계산할 두 사람, 관계 수 입력받기

    relations.resize(people + 1);
    visited.resize(people + 1, false);
    dst.resize(people + 1, -1);

    // 관계 입력 받기
    for (int i = 0; i < r_num; ++i) {
        int x, y;
        cin >> x >> y;
        relations[x].push_back(y);
        relations[y].push_back(x);
    }

    // 촌수 계산
    int kinship = calculateKinship(p_1, p_2, people);

    cout << kinship << endl; // 촌수 출력

    return 0;
}
