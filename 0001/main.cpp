#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[10];
    for(int i=0; i<10; i++) cin >> a[i];
    sort(a, a+10);
    for(int i=9; i>6; i--) cout << a[i] << endl;
    return 0;
}
