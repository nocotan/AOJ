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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int w, h, res;
string a[55];
bool is_while = false;
bool is_black = false;

int dfs(int y, int x) {
    a[y][x] = '#';
    res++;
    for(int i=0; i<4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0&&nx<w&&ny>=0&&ny<h) {
            if(a[ny][nx]=='.') dfs(ny, nx);
            if(a[ny][nx]=='W') is_while = true;
            if(a[ny][nx]=='B') is_black = true;
        }
    }

    return res;
}

signed main()
{
    while(cin>>w>>h, w) {
        for(int i=0; i<h; ++i) cin >> a[i];
        int nw = 0;
        int nb = 0;
        for(int i=0; i<h; ++i) {
            for(int j=0; j<w; ++j) {
                if(a[i][j]=='.') {
                    is_while = false;
                    is_black = false;
                    res = 0;
                    dfs(i, j);
                    if(is_while&&!is_black) nw += res;
                    else if(!is_while&&is_black) nb += res;
                }
            }
        }
        cout << nb << " " << nw << endl;
    }
    return 0;
}

