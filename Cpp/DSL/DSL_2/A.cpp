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

// Range Minimum Query
template<typename T>
class RMQ {
    private:
        unsigned size_;
        std::vector<T> dat;

        T query(unsigned a, unsigned b, unsigned k, unsigned l, unsigned r) {
            if (r <= a || b <= l) return std::numeric_limits<T>::max();
            if (a <= l && r <= b) return dat[k];
            T lc = query(a, b, (k << 1), l, (l + r) >> 1);
            T rc = query(a, b, (k << 1) + 1, (l + r) >> 1, r);
            return std::min(lc, rc);
        }

    public:
        RMQ() : size_(0), dat(std::vector<T>()) { }
        RMQ(int n) {
            for (size_=1; size_<n;) size_ <<= 1;
            dat.resize(size_ << 1, std::numeric_limits<T>::max());
        }

        template<typename U>
            RMQ(U begin, U end) {
                unsigned n = (end - begin);
                for (size=1; size<n;) size <<= 1;
                dat.resize(size<<1, std::numeric_limits<T>::max());
                for (unsigned i=0; i<n; ++i) dat[i+size] = *(begin+i);
                for (unsigned i=size-1; i>0; --i) dat[i] = std::min(dat[i<<1], dat[(i<<1)+1]);
            }

        unsigned size() { return size_; }

        void update(unsigned i, T x) {
            i += size_;
            dat[i] = x;
            while (i > 1) {
                i >>= 1;
                dat[i] = std::min(dat[i << 1], dat[(i << 1) + 1]);
            }
        }

        T query(unsigned l, unsigned r) {
            return query(l, r, 1, 0, size_);
        }
};

int main()
{
    int n, q;
    cin >> n >> q;
    RMQ<int> rmq(n);
    for(int i=0; i<q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c==0) rmq.update(x, y);
        else cout << rmq.query(x, y+1) << endl;
    }
    return 0;
}

