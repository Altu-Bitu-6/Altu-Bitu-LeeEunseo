#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * 2; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p); // 소수를 찾으면 바로 푸시
        }
    }

    return primes;
}

int main() {
    int n, max_n = 0;
    vector<int> inputs;

    while (true) {
        cin >> n;

        if (n == 0) {   // 0이 입력되면 프로그램 종료
            break;
        }
        inputs.push_back(n);
        if (n > max_n) max_n = n; // 입력된 수 중 최대값 갱신
    }
    vector<int> primes = sieveOfEratosthenes(max_n); // 모든 소수를 찾는 함수 호출
    vector<bool> is_prime(max_n + 1, false); // 소수 여부 배열

    for (int prime : primes) {
        is_prime[prime] = true; // 소수 인덱스를 true로 설정
    }

    for(int num : inputs) {
        bool found = false;
        for (int prime : primes) {
            int a = prime;
            int b = num - a; // 두 번째 소수

            if (b >= a && is_prime[b]) { // 두 수가 소수이며, b가 a보다 크거나 같은 경우
                cout << num << " = " << a << " + " << b << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong." << "\n";
        }
    }

    return 0;
}