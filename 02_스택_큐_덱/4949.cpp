#include <iostream> // 자료 구조, 스택, 문자열
#include <stack>
#include <string>

using namespace std;

bool isBalanced(const string& s) {
    stack<char> par;

    for (char c : s) {
        if (c == '(' || c == '[') {
            par.push(c);
        } else if (c == ')' || c == ']') {
            if (par.empty()) {
                return false;
            }
            char top = par.top();
            if ((c == ')' && top == '(') || (c == ']' && top == '[')) {
                par.pop();
            } else {
                return false;
            }
        }
    }

    return par.empty();
}

int main() {
    string input;

    while (true) {
        getline(cin, input);
        if (input == ".") break;

        if (isBalanced(input)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}