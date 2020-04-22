using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e3 + 12;
const int MOD = 1e9 + 7; 

int dp[N][N]; 
int a[N]; 
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, h, l, r;
  cin >> n >> h >> l >> r; 
  vector <int> a(n); 
  for (int i = 1; i <= n; ++i) cin >> a[i]; 
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= h; ++j) dp[i][j] = -1; 
  }
  dp[0][0] = 0; 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= h; ++j) {
      if (dp[i][j] < 0) continue; 
      int nxt = (j + a[i + 1]) % h;
      int cur = dp[i][j]; 
      if (nxt >= l && nxt <= r) cur += 1; 
      dp[i + 1][nxt] = max(dp[i + 1][nxt], cur);  
      nxt = (j + a[i + 1] - 1) % h; 
      cur = dp[i][j];
      if (nxt >= l && nxt <= r) cur += 1;
      dp[i + 1][nxt] = max(dp[i + 1][nxt], cur); 
    }
  }
  int ans = 0; 
  for (int i = 0; i <= h; ++i) ans = max(ans, dp[n][i]); 
  cout << ans; 

     
  return 0;
}