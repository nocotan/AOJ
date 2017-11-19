#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    while(cin>>n, n!=0) {
        int memo[4000] = {0};
        bool F[4000] = {false};
        bool f = true;
        for(int i=0; i<n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            memo[a] += (b*c);
            if(memo[a]>=1000000 && !F[a]) {
                f = false;
                F[a] = true;
                cout << a << endl;
            }
        }
        if(f) cout << "NA" << endl;
    }
    return 0;
}

