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


// Binary Indexed Tree
template <typename T>
class BIT {
    private:
        unsigned size_;
        std::vector<T> v;

        T sum(unsigned r) {
            T ret = 0;
            while (r > 0) {
                ret += v[r];
                r -= r & (-r);
            }
            return ret;
        }
    public:
        BIT() { }
        BIT(unsigned n) {
            for (size_=1; size_<n;) size_ <<= 1;
            v.resize(size_+1, 0);
        }
        inline void add(unsigned i, T x) {
            ++i;
            while (i <= size_) {
                v[i] += x;
                i += i & -i;
            }
        }
        inline T sum(unsigned l, unsigned r) { return sum(r) - sum(l); }
        bool operator[](unsigned x) { return sum(x, x+1); }
};

int main()
{
    int n, q;
    cin >> n >>q;
    BIT<int> Q(n);
    while(q--) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c==0) Q.add(x-1, y);
        else cout << Q.sum(x-1, y) << endl;
    }
    return 0;
}

