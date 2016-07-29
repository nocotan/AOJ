//#define _GRIBCXX_DEBUG
#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <string>
#include <utility>
#include <vector>
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

#pragma region TYPE_DEF
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long> vl;
typedef vector<long long> vll;
#pragma endregion


// Effective std
#pragma region ESTD
template<typename C, typename T>
constexpr int count(C& c, T t) { return count(ALL(c), t); }
template<typename C, typename F>
constexpr int count_if(C& c, F f) { return count_if(ALL(c), f); }
template<typename C, typename T, typename U>
constexpr void replace(C& c, T t, U u) { replace(ALL(c), t, u); }
template<typename C, typename F, typename U>
constexpr void replace_if(C& c, F f, U u) { (ALL(c), f, u); }
template<typename C>
constexpr void sort(C& c) { sort(ALL(c)); }
template<typename C, typename Pred>
constexpr void sort(C& c, Pred p) { sort(ALL(c), p); }
template<typename C>
constexpr void reverse(C& c) { reverse(ALL(c)); }

#pragma endregion


// グラフテンプレート
#pragma region GRAPH

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) {}
};

bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight :
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#pragma endregion

// 素数
#pragma region PRIME
bool is_prime(unsigned n) {
  switch(n) {
    case 0:
    case 1: return false;
    case 2: return true;
  }
  if (n%2==0) return false;
  for (unsigned i=3; i*i<=n; i+=2)
    if (n%i==0) return false;
  return true;
}
#pragma endregion

// 大文字/小文字変換
void mutal_tr(string &s) {
  for(int i=s.size(); i--;) {
    if(islower(s[i])) s[i] = toupper(s[i]);
    else if (isupper(s[i])) s[i] = tolower(s[i]);
  }
}

// 定数
#pragma region CONST_VAL
#define PI (2*acos(0.0))
#define EPS (1e-9)
#define MOD (int)(1e9+7)
#pragma endregion

int main() {
  char ch;
  int counter[26] = {0};
  while(cin>>ch) {
    if(isupper(ch)) ch = tolower(ch);
    int tmp = ch - 'a';
    counter[tmp]++;
  }
  rep(i,26) printf("%c : %d\n", 'a'+i, counter[i]);
  return 0;
}

