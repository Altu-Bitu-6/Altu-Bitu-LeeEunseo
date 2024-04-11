#include <iostream>

using namespace std;

int GCD(int d1, int d2){
    int r = d1 % d2;
    if (r==0)
        return d2;
    else {
        return GCD(d2,r);
    }
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int lcm;

    if (b > d)
        lcm = b*d / GCD(b,d);
    else
        lcm = b*d / GCD(d, b);

    cout << a*(lcm/b)+c*(lcm/d) << " " << lcm << "\n";

    return 0;
}