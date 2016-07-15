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
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define REP(i,x,n) for(int i=x; i<(int)n; ++i)
#define repi(i,n) for(int i=0; i<=(int)n; ++i)
#define REPI(i,x,n) for(int i=x; i<=(int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin())!=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<long, long> pil;


// Effective std
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


// グラフテンプレート
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

int main(void){
    int r,c;
    cin >> r >> c;
    int **a = new int*[r+1];
    for(int i = 0; i < r+1; i++ ){
        a[i] = new int[c+1];
    }
    for(int i = 0; i < r; i++ ){
        for(int j = 0; j < c; j++ ){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < r; i++ ){
        for(int j = 0; j < c; j++ ){
            a[i][c] += a[i][j];
        }
    }
    for(int j = 0; j < c; j++ ){
        for(int i = 0; i < r; i++ ){
            a[r][j] += a[i][j];
        }
    }
    for(int i = 0; i < r; i++ ){
        a[r][c] += a[i][c];
    }
    for(int i = 0; i < r+1; i++ ){
        for(int j = 0; j < c+1; j++ ){
            cout << a[i][j];
            if( j != c ) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}
