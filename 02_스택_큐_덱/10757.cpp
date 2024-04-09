#include <iostream> // 구현, 임의 정밀도 / 큰 수 연산, 사칙연산, 수학
#include <string>
#include <algorithm>

using namespace std;

string add(string a, string b) {
    string result;
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result += to_string(sum % 10);
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    string result = add(A, B);

    cout << result << endl;

    return 0;
}