#include <iostream> // 그리디 알고리즘, 수학
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> planet(n);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> planet[i]; // 각 행성으로 이동하는데 필요한 최소 속도 입력
    }


    int earthSpeed=0;
    for(int i = n-1; i >= 0; i--){
        if(earthSpeed<planet[i]){
            earthSpeed = planet[i];
        }else if (earthSpeed == planet[i]) {  //변경 필요없음
        }else if (earthSpeed%planet[i]!=0){
            int tmpSpeed = planet[i];
            while(tmpSpeed<earthSpeed) {
                tmpSpeed+=planet[i];
            }
            earthSpeed=tmpSpeed;
        }
    }

    cout << earthSpeed << "\n";

    return 0;
}