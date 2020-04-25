
#include <bits/stdc++.h>
#define FORE(i, c) for (__typeof ((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPD(i, n) for (int i = (int) (n) - 1; i >= 0; --i)
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define __ cerr <<
#define _ << " " <<
#define NL endl
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef double DD;
typedef long double LD;
const LL LLINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-7;
inline const int &INT() { static int x; scanf("%d", &x); return x; }
inline const LL &LONG() { static LL x; scanf("%lld", &x); return x; }
template<class T> inline void MIN(T &a, const T &b) { if (b < a) a = b; }
template<class T> inline void MAX(T &a, const T &b) { if (b > a) a = b; }
// ---------------------------------------------------------------- //

const int NN = 1e5 + 5;
pair<DD, DD> pt[NN];
int N;

DD sqr(DD x) { return x * x; }

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  N = INT();
  REP(i, N) scanf("%lf%lf", &pt[i].fi, &pt[i].se);

  sort(pt, pt + N);
  set<pair<DD, int> > asdf;
  DD best = INF;
  int j = 0;
  REP(i, N) {
    while (pt[i].fi - pt[j].fi > best) {
      asdf.erase(pair<DD, int>(pt[j].se, j));
      ++j;
    }
    set<pair<DD, int> >::iterator low, high;
    low = asdf.lower_bound(pair<DD, int>(pt[i].se - best, -INF));
    high = asdf.upper_bound(pair<DD, int>(pt[i].se + best, INF));
    while (low != high) {
      int k = low->se;
      MIN(best, sqrt(sqr(pt[i].fi - pt[k].fi) + sqr(pt[i].se - pt[k].se)));
      ++low;
    }
    asdf.insert(pair<DD, int>(pt[i].se, i));
  }
  printf("%.3lf\n", best);
  return 0;
}
