#include <iostream>
#include <string>
using namespace std;

const int BOARD_SIZE = 8;

// 킹과 돌의 현재 위치
class Position {
public:
    int row, col;

    Position() : row(0), col(0) {}
    Position(int r, int c) : row(r), col(c) {}
};

void movePiece(Position& piece, char dir) {
    switch (dir) {
        case 'R': piece.col = min(piece.col + 1, BOARD_SIZE); break;
        case 'L': piece.col = max(piece.col - 1, 1); break;
        case 'B': piece.row = max(piece.row - 1, 1); break;
        case 'T': piece.row = min(piece.row + 1, BOARD_SIZE); break;
        case 'RT': piece.row = min(piece.row + 1, BOARD_SIZE); piece.col = min(piece.col + 1, BOARD_SIZE); break;
        case 'LT': piece.row = min(piece.row + 1, BOARD_SIZE); piece.col = max(piece.col - 1, 1); break;
        case 'RB': piece.row = max(piece.row - 1, 1); piece.col = min(piece.col + 1, BOARD_SIZE); break;
        case 'LB': piece.row = max(piece.row - 1, 1); piece.col = max(piece.col - 1, 1); break;
    }
}

// 열 번호 문자로 변환
char toColumnChar(int col) {
    return 'A' + col - 1;
}

// 문자열 좌표를 정수 좌표로 변환
Position stringToPosition(const string& str) {
    int col = str[0] - 'A' + 1;
    int row = stoi(str.substr(1));
    return Position(row, col);
}

int main() {
    Position king, stone;
    int N;
    string kingStr, stoneStr;
    cin >> kingStr >> stoneStr >> N;

    king = stringToPosition(kingStr);
    stone = stringToPosition(stoneStr);

    for (int i = 0; i < N; ++i) {
        string move;
        cin >> move;

        // 킹 이동
        Position prevKing = king;
        movePiece(king, move[0]);
        // 킹이 체스판 밖으로 나간 경우 원래 위치로 복구
        if (king.row < 1 || king.row > BOARD_SIZE || king.col < 1 || king.col > BOARD_SIZE) {
            king = prevKing;
            continue;
        }

        // 돌 이동
        if (king.row == stone.row && king.col == stone.col) {
            Position prevStone = stone;
            movePiece(stone, move[0]);
            // 돌이 체스판 밖으로 나간 경우 원래 위치로 복구
            if (stone.row < 1 || stone.row > BOARD_SIZE || stone.col < 1 || stone.col > BOARD_SIZE) {
                stone = prevStone;
                king = prevKing;
            }
        }
    }

    cout << toColumnChar(king.col) << king.row << "\n";
    cout << toColumnChar(stone.col) << stone.row << "\n";

    return 0;
}
