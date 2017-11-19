#include <bits/stdc++.h>
using namespace std;

#define int long long

// ダイクストラ法
int V, E;
struct edge {
    int to;
    int cost;
    edge(int to, int cost)
        : to(to), cost(cost) { }
};

vector<edge> G[100001];
int d[100001];

void dijkstra(int s) {
    using p = pair<int, int>;
    priority_queue<p, vector<p>, greater<p>> que;
    fill(d, d+V, 1e+9);
    d[s] = 0;
    que.push(p(0, s));
    while(!que.empty()) {
        p pi = que.top(); que.pop();
        int v = pi.second;
        if(d[v] < pi.first) continue;
        for(int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(p(d[e.to], e.to));
            }
        }
    }
}

signed main() {
    int r;
    cin >> V >> E >> r;
    for(int i=0; i<E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back(edge(t, d));
    }
    dijkstra(r);
    for(int i=0; i<V; ++i) {
        if(d[i]==1e+9) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}

