#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 팰린드롬을 생성하는 함수
string createPalindrome(string name) {
    vector<int> charCount(26, 0); // 알파벳 대문자 A-Z까지의 등장 횟수를 저장할 벡터
    for (char c : name) {
        charCount[c - 'A']++; // 각 문자의 등장 횟수를 계산
    }

    int oddCount = 0; // 홀수 횟수로 등장하는 문자의 개수
    char oddChar = '\0'; // 홀수 횟수로 등장하는 문자
    for (int i = 0; i < 26; i++) {
        if (charCount[i] % 2 != 0) {
            oddCount++;
            oddChar = 'A' + i;
        }
    }

    // 팰린드롬을 만들 수 없는 경우
    if (oddCount > 1 || (oddCount == 1 && name.length() % 2 == 0)) {
        return "I'm Sorry Hansoo";
    }

    string firstHalf = "", secondHalf = "";
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

    return firstHalf + secondHalf; // 최종 팰린드롬 반환
}

int main() {
    string name;
    cin >> name;

    string result = createPalindrome(name); // 입력 문자열에 대한 팰린드롬 생성
    cout << result << "\n"; // 생성된 팰린드롬 출력

    return 0;
}
