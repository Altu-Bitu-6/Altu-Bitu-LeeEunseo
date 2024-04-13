#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int M;
    cin >> M;

    int bitmask = 0; // 비트마스크로 집합을 표현 (0~20)

    for (int i = 0; i < M; ++i) {
        string command;
        int x;
        cin >> command;

        if (command == "add") {
            cin >> x;
            bitmask |= (1 << x);
        } else if (command == "remove") {
            cin >> x;
            bitmask &= ~(1 << x);
        } else if (command == "check") {
            cin >> x;
            cout << ((bitmask & (1 << x)) ? 1 : 0) << '\n';
        } else if (command == "toggle") {
            cin >> x;
            bitmask ^= (1 << x);
        } else if (command == "all") {
            bitmask = (1 << 21) - 1;
        } else if (command == "empty") {
            bitmask = 0;
        }
    }

    return 0;
}
