#include <bits/stdc++.h>
using namespace std;

#define int long long

// クラスカル法
struct kruskal {
    struct edge {
        int u;
        int v;
        int cost;
        edge() { }
        edge(int u, int v, int cost) : u(u), v(v), cost(cost) { }
    };
    struct union_find {
        vector<int> data;
        union_find() { }
        union_find(int size) : data(size, -1) { }
        bool union_set(int x, int y) {
            x = root(x);
            y = root(y);
            if(x != y) {
                if(data[y] < data[x]) swap(x, y);
                data[x] += data[y];
                data[y] = x;
            }
            return x != y;
        }
        bool find_set(int x, int y) { return root(x) == root(y); }
        int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
        int size(int x) { return data[root(x)]; }
    };

    vector<edge> edges;
    int V, E;
    union_find uf;
    kruskal(int V, int E) : V(V), E(E) {
        uf = union_find(V);
    }
    void add_edge(int s, int t, int cost) {
        edges.push_back(edge(s, t, cost));
    }
    static bool comp(const edge& e1, const edge e2) {
        return e1.cost < e2.cost;
    }
    int run() {
        sort(edges.begin(), edges.end(), comp);
        int res = 0;
        for(int i=0; i<E; ++i) {
            edge e = edges[i];
            if(e.u != e.v) {
                uf.union_set(e.u, e.v);
                res += e.cost;
            }
        }
        return res;
    }
};

signed main() {
    int V, E;
    cin >> V >> E;
    kruskal kr(V, E);
    for(int i=0; i<E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        kr.add_edge(s, t, w);
        kr.add_edge(t, s, w);
    }
    cout << kr.run() << endl;
    return 0;
}

