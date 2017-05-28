//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int stage[21][21];
int dp[1000000];

void solve() {
    int to = (1<<n);
    for(int i=0; i<to+2; ++i) dp[i] = 1e+9;
    dp[0] = 0;

    for(int i=0; i<to; ++i) {
        if(dp[i]==1e+9) continue;
        for(int j=0; j<n; ++j) {
            if((i&(1<<j)) != 0) continue;
            int min_cost = stage[j][0];
            for(int k=0; k<n; ++k) {
                if((i&(1<<k)) != 0) min_cost = min(min_cost, stage[j][k+1]);
            }
        int bit = (i | (1<<j));
        dp[bit] = min(dp[bit], dp[i]+min_cost);
        }
    }
    cout << dp[to-1] << endl;
}

signed main()
{
    while(cin>>n, n) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n+1; ++j) cin >> stage[i][j];
        }
        solve();
    }
    return 0;
}

