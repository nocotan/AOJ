//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int, int>;

struct edge {
    int to;
    int cost;
    edge(int to, int cost) : to(to), cost(cost) { }
};

int V, E, r;

vector<edge> G[100001];
int d[100001];

auto dijkstra(int s) -> void {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, 1e+9);
    d[s] = 0;
    que.push(P(0,s));
    while(!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v]<p.first) continue;
        for(int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if(d[e.to]>d[v]+e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}

auto main() -> signed {
    cin >> V >> E >> r;
    int s, t, di;
    for(int i=0; i<E; ++i) {
        cin >> s >> t >> di;
        G[s].push_back(edge(t,di));
    }
    dijkstra(r);
    for(int i=0; i<V; ++i) {
        if(d[i]==1e+9) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
    return 0;
}

