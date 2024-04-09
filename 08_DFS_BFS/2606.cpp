#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj_list; // 인접 리스트
vector<bool> visited_bfs; // 방문 여부를 확인하는 벡터

// BFS 함수 선언
int bfs(int start) {
    queue<int> q;
    q.push(start);
    visited_bfs[start] = true; // 시작 노드를 방문한 것으로 표시
    int infected = 0; // 웜 바이러스에 걸린 컴퓨터 수

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        // 현재 노드와 연결된 모든 노드를 확인
        for(int i = 0; i < adj_list[current].size(); i++) {
            int next = adj_list[current][i];
            if(!visited_bfs[next]) { // 아직 방문하지 않았다면
                visited_bfs[next] = true; // 방문한 것으로 표시
                q.push(next); // 큐에 추가
                infected++; // 감염된 컴퓨터 수 증가
            }
        }
    }

    return infected;
}

int main() {
    int c_num, p_num;
    cin >> c_num >> p_num;

    adj_list.resize(c_num + 1);
    visited_bfs.assign(c_num + 1, false); // 방문 여부를 확인하는 벡터 초기화

    // 연결 정보 입력받기
    for(int i = 0; i < p_num; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // 무방향 그래프이므로 양쪽 모두에 추가
    }

    // 1번 컴퓨터를 시작점으로 BFS 실행
    cout << bfs(1) << "\n"; // 웜 바이러스에 걸린 컴퓨터 수 출력

    return 0;
}
