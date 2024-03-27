#include <iostream>
using namespace std;

int apocalypse(int N){
    int cnt = 0;
    int num = 666;

    while (true) {
        int temp = num;
        int count = 0;

        while (temp > 0) {
            if (temp % 10 == 6) {
                count++;
                if (count == 3) {
                    cnt++;
                    break;
                }
            } else {
                count = 0;
            }
            temp /= 10;
        }

        if (cnt == N) {
            return num;
        }

        num++;
    }
}

int main() {
    int N;
    cin >> N;

    cout << apocalypse(N) << "\n";

    return 0;
}
