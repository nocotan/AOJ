//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

int d[1001][1001];
int V, E, r;

auto warshall_floyd() -> void {
    for(int k=0; k<V; ++k)
        for(int i=0; i<V; ++i)
            for(int j=0; j<V; ++j)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

auto main() -> signed {
    cin >> V >> E >> r;
    for(int i=0; i<E; ++i) {
        int s, t, e;
        cin >> s >> t >> e;
        d[s][t] = e;
    }
    warshall_floyd();
    for(int i=0; i<V; ++i) {
        cout << d[r][i] << endl;
    }
    return 0;
}

