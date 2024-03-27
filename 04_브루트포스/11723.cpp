#include <iostream>
#include <set>
using namespace std;

int main(){
    int M;
    cin >> M;
    int lcm;

    set<int> S; // 집합 S 선언

    for (int i = 0; i < M; ++i) {
        string command;
        int x;
        cin >> command;

        if (command == "add") {
            cin >> x;
            S.insert(x);
        } else if (command == "remove") {
            cin >> x;
            S.erase(x);
        } else if (command == "check") {
            cin >> x;
            cout << (S.find(x) != S.end() ? 1 : 0) << '\n';
        } else if (command == "toggle") {
            cin >> x;
            if (S.find(x) != S.end()) {
                S.erase(x);
            } else {
                S.insert(x);
            }
        } else if (command == "all") {
            S.clear();
            for (int j = 1; j <= 20; ++j) {
                S.insert(j);
            }
        } else if (command == "empty") {
            S.clear();
        }
    }

    return 0;
}
