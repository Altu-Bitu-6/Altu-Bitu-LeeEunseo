#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 문자열 내의 숫자들의 합을 계산하는 함수
int calculateSumOfDigits(const string& str) {
    int sum = 0;
    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}

// A와 B의 비교 함수
bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length(); // 길이가 다르면 짧은 것이 먼저
    }

    int sum_a = calculateSumOfDigits(a);
    int sum_b = calculateSumOfDigits(b);

    if (sum_a != sum_b) {
        return sum_a < sum_b; // 합이 다르면 작은 합을 가지는 것이 먼저
    }

    return a < b; // 사전순으로 비교
}

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);

    for (int i = 0; i < strings.size(); ++i) {
        getline(cin, strings[i]);
    }

    // A와 B의 비교 함수를 이용하여 정렬
    sort(strings.begin(), strings.end(), compare);

    for (int i = 0; i < strings.size(); ++i) {
        const string& str = strings[i];
        cout << str << "\n";
    }

    return 0;
}
