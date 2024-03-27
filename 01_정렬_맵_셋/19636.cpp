#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T >> D >> I >> A;

    int weight = W0, BMR = I0;
    bool danger_diet = false;

    for (int i = 0; i < D; ++i) {
        int energy_consumption = BMR + A;
        weight += I - energy_consumption;

        if (weight <= 0 || BMR <= 0) {
            danger_diet = true;
            break;
        }

        if (abs(I - energy_consumption) > T) {
            int BMR_change = (I - energy_consumption) / 2;
            if (BMR + BMR_change <= 0) {
                danger_diet = true;
                break;
            }
            BMR += BMR_change;
        }
    }

    if (danger_diet) {
        cout << "Danger Diet" << endl;
    } else {
        cout << weight << " " << BMR << endl;
        // 다이어트가 끝난 후 체중이 증가하는 경우에 대한 출력
        if (BMR > I0) {
            // 다이어트가 끝난 후 원래의 일일 에너지 섭취량과 일일 활동 대사량
            cout << W0 - weight + W0 << " " << I0 << " YOYO" << endl;
        } else {
            // 다이어트가 끝난 후에도 체중이 감소하지 않는 경우
            cout << weight << " " << BMR << " NO" << endl;
        }
    }

    return 0;
}
