//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, a, b, c, x;
    while(cin>>n>>a>>b>>c>>x, n) {
        int ans = 0;
        for(int i=0; i<n; ++i) {
            int m;
            cin >> m;
            while(true) {
                if(x==m) {
                    x = (a*x+b)%c;
                    if(i!=0) ans++;
                    break;
                }
                x = (a*x+b)%c;
                ans++;
                if(ans==10000) {
                    ans = -1;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

