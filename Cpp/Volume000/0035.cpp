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

struct Point {
    double x;
    double y;
};

double Abs(double x) {
    return x >=0 ? x : -x;
};

double Square(const Point& P, const Point& Q, const Point& R) {
    Point A = {Q.x-P.x, Q.y-P.y};
    Point B = {R.x-P.x, R.y-P.y};
    return Abs(A.x*B.y-A.y*B.x);
};

bool solve(const Point& P, const Point& Q, const Point R, const Point O) {
    return (Square(P,Q,R) > Square(O,P,Q) + Square(Q, R, O));
}

int main()
{
    Point A, B, C, D;
    char c;
    while(cin>>A.x>>c>>A.y>>c>>B.x>>c>>B.y>>c>>C.x>>c>>C.y>>c>>D.x>>c>>D.y) {
        if(solve(A,B,C,D) || solve(B,C,D,A) || solve(C,D,A,B) || solve(D,A,B,C))
            P("NO");
        else
            P("YES");

    }
    return 0;
}

