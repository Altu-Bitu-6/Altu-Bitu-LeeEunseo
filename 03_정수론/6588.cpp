#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes = sieveOfEratosthenes(n);

    bool found = false;
    for (size_t i = 0; i < primes.size(); ++i) {
        int a = primes[i];
        for (size_t j = 0; j < primes.size(); ++j) {
            int b = primes[j];
            if (a + b == n) {
                cout << n << " = " << a << " + " << b << "\n";
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        cout << "Goldbach's conjecture is wrong." << "\n";
    }

    return 0;
}