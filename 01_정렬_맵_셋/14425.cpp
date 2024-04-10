#include <iostream> // 자료 구조, 해시를 사용한 집합과 맵, 문자열, 트리를 사용한 집합과 맵
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 집합 S의 원소인지 검사
int cntIsInSet(const set<string>& S, const vector<string>& check) {
    int cnt = 0;
    // check의 원소를 하나씩 확인하며 S에 있는지 확인
    for (const string& element : check) {
        if (S.find(element) != S.end()) {
            cnt++;
        }
    }
    return cnt;
}


int main() {
    int N, M;
    cin >> N >> M;
    cin.ignore();

    set<string> S;
    vector<string> check;

    // S 집합 N개 입력받기
    for (int i = 0; i < N; ++i) {
        string str;
        getline(cin, str);
        S.insert(str);
    }

    // 검사 문자열 M개 입력받기
    for (int i = 0; i < M; ++i) {
        string str;
        getline(cin, str);
        check.push_back(str);
    }

    //
    cout << cntIsInSet(S, check) << "\n";

    return 0;
}
