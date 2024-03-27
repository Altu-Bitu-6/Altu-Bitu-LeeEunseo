#include <iostream>

using namespace std;

int gcd(int d1, int d2){
    int r = d1 % d2;
    if (r==0)
        return d2;
    else
        return gcd(d2,r);
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int lcm;

    if (b > d)
        lcm = b*d / gcd(b,d);
    else
        lcm = b*d / gcd(d, b);

    cout << a*(lcm/b)+c*(lcm/d) << " " << lcm << "\n";

    return 0;
}