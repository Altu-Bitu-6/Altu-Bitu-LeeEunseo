#include <iostream> // 그리디 알고리즘, 구현, 문자열
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void palindrome(string name) {
    vector<int> charCount(26, 0); // 알파벳 대문자 A-Z까지의 등장 횟수를 저장할 벡터
    for (char c : name) {
        charCount[c - 'A']++; // 각 문자의 등장 횟수를 계산
    }

    int oddCount = 0; // 홀수 횟수로 등장하는 문자의 개수
    char oddChar; // 홀수 횟수로 등장하는 문자
    for (int i = 0; i < 26; i++) {
        if (charCount[i] % 2 != 0) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    if (oddCount > 1 || (oddCount == 1 && name.length() % 2 == 0)) {
        cout << "I'm Sorry Hansoo" << "\n"; // 팰린드롬을 만들 수 없는 조건
        return;
    }

    string firstHalf="", secondHalf="";
    for (int i = 0; i < 26; i++) {
        if (charCount[i] > 0) {
            string temp(charCount[i] / 2, 'A' + i); // 각 문자의 절반을 각각의 반쪽에 추가
            firstHalf += temp;
            secondHalf = temp + secondHalf; // 두 번째 반쪽은 뒤집어서 추가
        }
    }

    // 홀수 횟수로 등장하는 문자가 있다면 가운데에 추가
    if (oddCount == 1) {
        firstHalf += oddChar;
    }

    cout << firstHalf + secondHalf << "\n"; // 최종 팰린드롬 출력
}

int main() {
    string name;
    cin >> name;

    palindrome(name);

    return 0;
}
