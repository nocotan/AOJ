#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int s, d;
    char c;
    double px = 0.0, py = 0.0;
    double dir = 90.0;

    while(cin >> s >> c >> d) {
        if(s == 0 && d == 0) break;
        px += cos(dir * M_PI / 180.0) * s;
        py += sin(dir * M_PI / 180.0) * s;
        dir -= d;
    }
    cout << static_cast<int>(px) << endl;
    cout << static_cast<int>(py) << endl;
    return 0;
}
