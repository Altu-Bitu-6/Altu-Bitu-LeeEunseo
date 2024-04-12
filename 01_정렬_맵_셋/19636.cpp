#include <iostream>
#include <cmath>  // floor 함수 사용

using namespace std;

void calculateWeightAndBMR(int W0, int I0, int I, int A, int D, int T, int& final_weight, int& final_BMR, bool consider_BMR_change) {
    int weight = W0;
    int BMR = I0;

    for (int day = 0; day < D; ++day) {
        int daily_consumed = BMR + A;
        weight += I - daily_consumed;  // 체중 업데이트

        if (consider_BMR_change && abs(I - daily_consumed) > T) {
            int BMR_change = floor(float(I - daily_consumed) / 2.0);  // 음수 나눗셈 정확 처리
            BMR += BMR_change;
            if (BMR <= 0) {
                weight = 0;  // BMR이 0 이하로 떨어지면 weight도 0으로 처리
                break;
            }
        }

        if (weight <= 0) {  // 체중이 0 이하로 떨어진 경우
            weight = 0;
            break;
        }
    }

    final_weight = weight;
    final_BMR = BMR;
}

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T >> D >> I >> A;

    int weight1, BMR1, weight2, BMR2;
    calculateWeightAndBMR(W0, I0, I, A, D, T, weight1, BMR1, false); // 기초대사량 변화 고려 X
    calculateWeightAndBMR(W0, I0, I, A, D, T, weight2, BMR2, true);  // 기초대사량 변화 고려 O

    if (weight1 <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << weight1 << " " << I0 << "\n";  // 기초대사량 변화 고려 X
    }

    if (weight2 <= 0 || BMR2 <= 0) {
        cout << "Danger Diet\n";
    } else {
        cout << weight2 << " " << BMR2 << " ";
        if (I0 > BMR2) {
            cout << "YOYO\n";  // 요요 O
        } else {
            cout << "NO\n";    // 요요 X
        }
    }

    return 0;
}
