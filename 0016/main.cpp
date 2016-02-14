#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 0;
    double y = 0;
    double const pi = acos(-1.0);
    int theta = 90;
    int d, t;
    char c;

    for(cin >> d >> c >> t; d != 0 || t != 0; cin >> d >> c >> t) {
        x += d * cos(pi * theta / 180);
        y += d * sin(pi * theta / 180);
        if(theta < 0) {
            theta += 360;
        } else {
            theta %= 360;
        }
    }
    cout << x << endl;
    cout << y << endl;
    return 0;
}
