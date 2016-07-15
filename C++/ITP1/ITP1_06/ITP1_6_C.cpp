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

int arr[4][3][10];
int main() {
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    arr[a-1][b-1][c-1]+=d;
    }
   for(int i=0; i<4; i++){
       for(int j=0; j<3; j++){
           for(int k=0; k<10; k++){
             cout<<" "<<arr[i][j][k];
        }
             cout<<endl;
      }
      if(i==3){
        continue;
      }cout<<"####################"<<endl;
    }
}
