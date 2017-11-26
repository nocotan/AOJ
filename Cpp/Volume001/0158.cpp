#include <bits/stdc++.h>
using namespace std;

#define int long long

int clz(int n) {
    if(n%2==0) return n / 2;
    else return n * 3 + 1;
}

signed main() {
    int n;
    while(cin>>n, n!=0) {
        int ans = 0;
        while(n!=1) {
            n = clz(n);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

