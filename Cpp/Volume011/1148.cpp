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


signed main()
{
    int N, M;
    while(cin>>N>>M, N) {
        vector<pair<int, int> > members[10001];
        int r;
        cin >> r;
        for(int i=0; i<r; ++i) {
            int t, n, m, s;
            cin >> t >> n >> m >> s;
            members[m].push_back(pair<int,int>(t,s));
        }
        for(int i=1; i<=M; ++i) sort(members[i].begin(), members[i].end());
        int q;
        cin >> q;
        for(int i=0; i<q; ++i) {
            int s, e, m;
            cin >> s >> e >> m;
            int pc_count = 0;
            int current_time = s;
            int ans = 0;
            vector<pair<int, int> > member = members[m];
            for(int i=0; i<member.size(); ++i) {
                pair<int, int> p = member[i];
                if(current_time <= p.first && pc_count > 0)
                    ans += min(e, p.first) - current_time;

                current_time = max(s, min(e, p.first));
                pc_count += p.second ? 1 : -1;

                if(current_time == e) break;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

