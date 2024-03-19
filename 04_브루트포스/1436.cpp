#include <iostream>
#include <string>
using namespace std;

int apocalypse(int N){
    int cnt = 0;
    int num = 666;

    while (true) {
        string str_num = to_string(num);
        if (str_num.find("666") != string::npos) {
            cnt++;
            if (cnt == num) {
                return num;
            }
        }
        num++;
    }
}


int main() {
    int N;
    cin >> N;

    int nth_apo = apocalypse(N);

    cout << N << "\n";

    return 0;
}