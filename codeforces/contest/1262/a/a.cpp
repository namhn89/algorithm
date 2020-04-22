using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e5 + 1;
const int MOD = 1e9 + 7; 
const int INF = 1e9 + 7; 
void solve() {
  int n; 
  cin >> n; 
  int lmax = -INF, rmin = INF; 
  for (int  i = 0; i < n; ++i) {
    int l, r; 
    cin >> l >> r;
    lmax = max(lmax, l); 
    rmin = min(rmin, r);  
  }
  cout << max(0, lmax - rmin) << endl; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t;
  cin >> t; 
  while (t-- ) {
    solve();
  }
 
  return 0;
}