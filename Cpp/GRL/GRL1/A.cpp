//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long

int V;
int E;
int r;

struct edge {
    int to;
    int cost;
    edge(int to, int cost)
        : to(to), cost(cost) { }
};

vector<edge> G[100001];
int d[100001];

using p = pair<int, int>;

void dijkstra(int s) {
    priority_queue<p, vector<p>, greater<p> > que;
    fill(d, d+V, 1e+9);
    d[s] = 0;
    que.push(p(0,s));
    while(!que.empty()) {
        p pi = que.top();
        que.pop();
        int v = pi.second;
        if(d[v]<pi.first) continue;
        for(int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(p(d[e.to], e.to));
            }
        }
    }
}

auto main() -> signed {
    cin >> V >> E >> r;
    int s, t, w;
    for(int i=0; i<E; ++i) {
        cin >> s >> t >> w;
        G[s].push_back(edge(t,w));
    }
    dijkstra(r);
    for(int i=0; i<V; ++i) {
        if(d[i]==1e+9) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}

