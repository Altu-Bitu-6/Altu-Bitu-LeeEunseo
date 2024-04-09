#include <iostream>
using namespace std;

int omok[19][19];

// 네 방향에 대한 이동 (가로, 세로, 대각선 ↘, 대각선 ↗)
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

bool rowCheck(int x, int y) {
    int color = omok[x][y];
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x;
        int ny = y;
        int count = 1;

        // 현재 방향으로 연속된 돌을 탐색
        while (true) {
            nx += dx[dir];
            ny += dy[dir];
            if (nx < 0 || nx >= 19 || ny < 0 || ny >= 19 || omok[nx][ny] != color) break;
            ++count;
        }

        // 연속된 돌이 5개인 경우
        if (count == 5) {
            // 연속된 돌이 6개 이상인지 확인 (이전 위치 확인)
            int px = x - dx[dir];
            int py = y - dy[dir];
            if (px >= 0 && px < 19 && py >= 0 && py < 19 && omok[px][py] == color) continue;

            // 연속된 돌이 6개 이상인지 확인 (다음 위치 확인)
            nx += dx[dir] * 5;
            ny += dy[dir] * 5;
            if (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && omok[nx][ny] == color) continue;

            return true;
        }
    }
    return false;
}

int main() {
    // 입력받기 : 검1, 흰2
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            cin >> omok[i][j];
        }
    }

    // 결과출력 : 검/흰, 가장 왼위 바둑알 좌표
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 19; ++j) {
            if (omok[i][j] != 0 && rowCheck(i, j)) {
                cout << omok[i][j] << "\n";
                cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}
