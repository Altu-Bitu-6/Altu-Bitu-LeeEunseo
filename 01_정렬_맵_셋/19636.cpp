#include <iostream> // 구현
#include <cmath>

using namespace std;

int main() {
    int W0, I0, T, D, I, A;
    cin >> W0 >> I0 >> T >> D >> I >> A;

    // 다이어트 기간 동안 체중과 일일 기초 대사량을 계산
    int weight = W0, BMR = I0;
    for (int i = 0; i < D; ++i) {
        // 일일 에너지 소비량 계산
        int energy_consumption = BMR + A;

        // 체중 변화 계산
        weight += I - energy_consumption;

        // 체중이 0 이하이거나 일일 기초 대사량이 0 이하이면 Danger Diet
        if (weight <= 0 || BMR <= 0) {
            cout << "Danger Diet" << endl;
            return 0;
        }

        // 일일 에너지 섭취량과 일일 활동 대사량이 일일 기초 대사량 변화 역치를 초과하는 경우
        if (abs(I - energy_consumption) > T) {
            // 일일 기초 대사량 변화 계산
            BMR += (I - energy_consumption) / 2;

            // 일일 기초 대사량이 0 이하이면 "Danger Diet" 출력 후 종료
            if (BMR <= 0) {
                cout << "Danger Diet" << "\n";
                return 0;
            }
        }
    }

    // 다이어트 후의 체중과 일일 기초 대사량 출력
    cout << weight << " " << BMR << "\n";

    // 요요 현상 여부 출력
    if (BMR > I0) {
        cout << "YOYO" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
