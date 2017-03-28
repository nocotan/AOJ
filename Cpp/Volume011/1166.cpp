//#define _GRIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

// 基本テンプレート
#pragma region MACRO
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define PED cout << "\n"
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define REP(i,x,n) for(int i=x; i<(int)n; ++i)
#define repi(i,n) for(int i=0; i<=(int)n; ++i)
#define REPI(i,x,n) for(int i=x; i<=(int)n; ++i)
#define ILP while(true)
#define FOR(i,c) for(__typeof((c).begin())!=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#pragma endregion

// 型
#pragma region TYPE_DEF
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long double> vld;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<string> vs;
#pragma endregion

// Effective std
#pragma region ESTD
template<typename C, typename T> int count(C& c, T t) { return count(ALL(c), t); }
template<typename C, typename F> int count_if(C& c, F f) { return count_if(ALL(c), f); }
template<typename C, typename T> void erase(C& c, T t) { remove(ALL(c), t), c.end(); }
template<typename C> void remove(vector<C>& c, unsigned int index) { c.erase(c.begin()+index); }
template<typename C, typename T, typename U> void replace(C& c, T t, U u) { replace(ALL(c), t, u); }
template<typename C, typename F, typename U> void replace_if(C& c, F f, U u) { (ALL(c), f, u); }
template<typename C> void reverse(C& c) { reverse(ALL(c)); }
template<typename C> void sort(C& c) { sort(ALL(c)); }
template<typename C, typename Pred> void sort(C& c, Pred p) { sort(ALL(c), p); }
#pragma endregion

// 定数
#pragma region CONST_VAL
constexpr int PI = (2*acos(0.0));
constexpr int EPS = (1e-9);
constexpr int MOD = (int)(1e9+7);
constexpr int INF = 100000000;
#pragma endregion

#define int long long

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

signed main()
{
    int h, w;
    while(cin>>w>>h, h||w) {
        // 座標(i, j)にいる時、方向kに動けるかどうか
        bool board[40][40][4];
        for(int i=0; i<h; ++i)
            for(int j=0; j<w; ++j)
                for(int k=0; k<4; ++k) board[i][j][k] = true;

        // 左端
        for(int i=0; i<h; ++i) board[i][0][3] = false;
        // 右端
        for(int i=0; i<h; ++i) board[i][w-1][2] = false;
        // 上端
        for(int i=0; i<w; ++i) board[0][i][1] = false;
        // 下端
        for(int i=0; i<w; ++i) board[h-1][i][0] = false;

        int a;
        for(int i=0; i<2*h-1; ++i) {
            int l = (i%2==0) ? w-1 : w;
            for(int j=0; j<l; ++j) {
                cin >> a;
                if(a==1) {
                    // 左右の情報
                    if(i%2==0) {
                        board[i/2][j][2] = false;
                        board[i/2][j+1][3] = false;
                    }
                    else {
                        board[i/2][j][0] = false;
                        board[i/2+1][j][1] = false;
                    }
                }
            }
        }

        int dist[40][40];
        for(int i=0; i<h; ++i)
            for(int j=0; j<w; ++j) dist[i][j] = INF;
        dist[0][0] = 1;
        queue<pair<int, int> > que;
        que.push(pair<int, int>(0,0));
        while(!que.empty()) {
            pair<int, int> t = que.front();
            que.pop();

            for(int i=0; i<4; ++i) {
                // 通れない場合
                if(!board[t.first][t.second][i]) continue;

                // 通れる場合は移動する
                int x = t.first + dx[i];
                int y = t.second + dy[i];

                // 現在の最小手数より手数がかかっている場合はスキップ
                if(dist[x][y] <= dist[t.first][t.second]+1) continue;

                dist[x][y] = dist[t.first][t.second] + 1;
                que.push(pair<int, int>(x,y));
            }
        }

        if(dist[h-1][w-1] == INF) cout << 0 << endl;
        else cout << dist[h-1][w-1] << endl;
    }
    return 0;
}

