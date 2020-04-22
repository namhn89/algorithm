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
double logfact[N]; 
double ways (int r, int c) {
  return logfact[r + c] - logfact[r] - logfact[c]; 
}
void solve() {
  for (int i = 2; i < N; ++i) {
    logfact[i] = logfact[i - 1] + log(i); 
  }

  int w, h, l, u, r, d; 
  cin >> w >> h >> l >> u >> r >> d;
  l--; u--; r--; d--; 
  double ans = 0.0;
  for (int i = 0; i < u and r + 1 < w; ++i) {
    double p2 = log(2.0) * (i + r + 1); 
    ans += exp(ways(i, r) - p2); 
  }

  for (int j = 0; j < l and d + 1 < h; ++j) {
    double p2 = log(2.0) * (j + d + 1); 
    ans += exp(ways(j, d) - p2); 
  }

  cout << ans << endl; 
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  cin >> t; 
  for(int iTest = 0; iTest < t; ++iTest) { 
    cout <<"Case #"<< iTest + 1 <<": ";
    solve(); 
  }
     
  return 0;
}