#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool areCharactersSame(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

// 하나의 문자만 다른지 확인
bool isOneCharDifferent(const string& str1, const string& str2) {
    if (str1.length() != str2.length())  {
        return false;
    }

    int diffCnt = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) diffCnt++;
        if (diffCnt > 1) return false;
    }
    return diffCnt == 1;
}

// 하나의 문자를 빼면 같아지는지 확인
bool isOneCharMissing(const string& longer, const string& shorter) {
    if (longer.length() != shorter.length() + 1) return false;

    int diffIndex = 0;
    while (diffIndex < shorter.length() && longer[diffIndex] == shorter[diffIndex]) {
        diffIndex++;
    }

    // longer에서 한 문자를 뺀 나머지가 shorter와 같은지 확인
    string longerModified = longer.substr(0, diffIndex) + longer.substr(diffIndex + 1);
    return longerModified == shorter;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    vector<string> strings(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, strings[i]);
    }

    int similar = 0;
    string baseString = strings[0];

    for (int i = 1; i < N; ++i) {
        if (areCharactersSame(baseString, strings[i])) {
            similar++;
        } else if (isOneCharDifferent(baseString, strings[i])) {
            similar++;
        } else if (isOneCharMissing(baseString, strings[i]) || isOneCharMissing(strings[i], baseString)) {
            similar++;
        }
    }

    cout << similar << "\n"; // 비슷한 단어 수 출력

    return 0;
}
