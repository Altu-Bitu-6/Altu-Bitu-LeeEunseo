#include <iostream>

using namespace std;

void Sort(string serial[], int size){
    for (int i = 0; i < size; ++i) {

    }
    cout << "/n";
}

int main(){
    int N;
    cin >> N;
    string* guitarSerial = new string[N];


    // 값을 입력받고 배열에 저장
    for (int i = 0; i < N; ++i) {
        cin >> guitarSerial[i];
    }

    Sort(guitarSerial, N);

    delete[] guitarSerial;

    return 0;
}