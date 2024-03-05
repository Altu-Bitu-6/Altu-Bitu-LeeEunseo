#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K, S;
    cin >> N >> K >> S;

    char* wheel = new char[N];
    fill(wheel, wheel + N, '?');

    bool unlucky=false;
    for (int i = 0; i < K; ++i) {
        int j;
        char c;
        cin >> j >> c;

        if (wheel[j % N] != '?')
            unlucky = true;
        else
            wheel[j % N] = c;
    }

    if (!unlucky){
        for (int i = S; i < S + N; ++i) {
            cout << wheel[i % N] << "\n";
        }
    }
    else
        cout << "!\n";

    delete[] wheel;

    return 0;
}