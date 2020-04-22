using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e5 + 2;
const int MOD = 1e9 + 7; 
const int P = 7 + 1; 

long long dp[N][1 << P];
long long s[N][P]; 
long long n, p, k;  
pair<long long, int> a[N]; 

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> p >> k; 
  for (int i = 1; i <= n; ++i) cin >> a[i].st, a[i].nd = i; 
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < p; ++j) cin >> s[i][j]; 
  }
  sort(a + 1, a + n + 1); 
  reverse(a + 1, a + n + 1); 
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= (1 << p); ++j) dp[i][j] = -1; 
  }
  dp[0][0] = 0; 
  for (int i = 1; i <= n; ++i) {
    for (int mask = 0; mask < (1 << p); ++mask) {
      int nposition = __builtin_popcount(mask); 
      if (i - 1 < nposition + k) {
        if (dp[i - 1][mask] != -1) {
          dp[i][mask] = dp[i - 1][mask] + a[i].st;
        } 
      }
      else {
        if (dp[i - 1][mask] != -1) {
          dp[i][mask] = dp[i - 1][mask];
        } 
      }
      for (int j = 0; j < p; ++j) {
        if ((mask & (1 << j)) && dp[i - 1][mask ^ (1 << j)] != -1) {
          dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + s[a[i].nd][j]); 
        }
      }
    }
  }
  cout << dp[n][(1 << p) - 1] << endl; 
     
  return 0;
}