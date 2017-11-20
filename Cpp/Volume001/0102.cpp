#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    while(cin>>n, n!=0) {
        int G[n+1][n+1] = {0};
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                cin >> G[i][j];
                G[i][n]+=G[i][j];
                G[n][j]+=G[i][j];
                G[n][n]+=G[i][j];
            }
        }
        for(int i=0; i<n+1; ++i) {
            for(int j=0; j<n+1; ++j) {
                printf("%5d", G[i][j]);
            }
            cout << endl;
        }
    }
    return 0;
}

