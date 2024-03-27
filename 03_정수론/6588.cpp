#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p); // 소수를 찾으면 바로 푸시
            for (int i = p * 2; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    return primes;
}

int main() {
    int n;
    cin >> n;

    if (n < 4) {
        cout << "Goldbach's conjecture is wrong." << endl;
        return 0;
    }

    vector<int> primes = sieveOfEratosthenes(n);
    vector<bool> isPrime(n + 1, false); // 수정된 부분: 소수 여부 배열 추가

    for (int prime : primes) {
        isPrime[prime] = true; // 수정된 부분: 소수 여부 배열 업데이트
    }

    bool found = false;
    for (int prime : primes) {
        int a = prime;
        int b = n - a; // a와 더해서 n이 되는 수

        // b가 소수이고, b가 a보다 크거나 같은 경우에만 출력하고 반복문 종료
        if (b >= 2 && isPrime[b]) {
            cout << n << " = " << a << " + " << b << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Goldbach's conjecture is wrong." << "\n";
    }

    return 0;
}
