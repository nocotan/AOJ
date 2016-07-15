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
#define FOR(i,c) for(__typeof((c).begin())!=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), c.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<double> vd;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<long, long> pil;


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


int main() {
  int n;
  cin >> n;

  bool card[4][13] = {false};
  for(int i=0; i<n; ++i) {
    char mark;
    int markN;
    int number;

    cin >> mark >> number;
    if (mark=='S') markN = 0;
    else if (mark=='H') markN = 1;
    else if(mark=='C') markN = 2;
    else if(mark=='D') markN = 3;

    card[markN][number-1] = true;
  }
  char m[4] = {'S', 'H', 'C', 'D'};
  rep(i, 4) {
    rep(j, 13) {
      if(card[i][j] == false) printf("%c %d\n", m[i], j+1);
    }
  }
  return 0;
}

