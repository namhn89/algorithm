using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 500 + 10;
const int M = 1500 + 10; 
const int MOD = 1e9 + 7;

long long n, k, p; 
long long a[N][M];
long long dp[N][M]; 

void solve() {
  cin >> n >> k >> p; 
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      cin >> a[i][j]; 
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i * k; j++) {
      if (dp[i][j] == -1) continue; 
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]); 
      long long value = dp[i][j]; 
      for (int h = 1; h <= k; h++) {
        value += a[i + 1][h]; 
        dp[i + 1][j + h] = max(dp[i + 1][j + h], value); 
      }
    }
  }
  cout << dp[n][p] << '\n';
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int nTest;
  cin >> nTest; 
  for (int iTest = 1; iTest <= nTest; ++iTest) {
    cout << "Case #" << iTest << ": ";
    solve(); 
  }
     
  return 0;
}