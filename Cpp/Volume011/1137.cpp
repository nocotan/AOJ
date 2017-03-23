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

int solve(string s) {
    int res = 0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i]=='m') {
            if(i==0||!isdigit(s[i-1])) res += 1000;
            else res += 1000 * (s[i-1]-'0');
        }
        else if(s[i]=='c') {
            if(i==0||!isdigit(s[i-1])) res += 100;
            else res += 100 * (s[i-1]-'0');
        }
        else if(s[i]=='x') {
            if(i==0||!isdigit(s[i-1])) res += 10;
            else res += 10 * (s[i-1]-'0');
        }
        else if(s[i]=='i') {
            if(i==0||!isdigit(s[i-1])) res += 1;
            else res += 1 * (s[i-1]-'0');
        }
    }
    return res;
}

string to_mcxi(int n) {
    string res = "";
    if(n>=1000) {
        if(n/1000==1) res += "m";
        else res += to_string(n/1000) + "m";
        n %= 1000;
    }
    if(n>=100) {
        if(n/100==1) res += "c";
        else res += to_string(n/100) + "c";
        n %= 100;
    }
    if(n>=10) {
        if(n/10==1) res += "x";
        else res += to_string(n/10) + "x";
        n %= 10;
    }
    if(n>=1) {
        if(n==1) res += "i";
        else res += to_string(n) + "i";
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << to_mcxi(solve(s1) + solve(s2)) << endl;
    }
    return 0;
}

