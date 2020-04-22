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

vector< vector<long long> > dp ; 
int n, m; 

void calc (int x, int y, int mask, int next_mask) {
  if (x == n) {
    return; 
  }
  if (y >= m) {
    dp[x + 1][next_mask] += dp[x][mask]; 
  }
  else {
    int my_mask = 1 << y; 
    if (mask & my_mask) {
      calc(x, y + 1, mask, next_mask); 
    }
    else
    {
      calc(x, y + 1, mask, next_mask | my_mask); 
      if (y + 1 < m && ! (my_mask & mask) && ! (mask & (my_mask << 1)) ) {
        calc(x, y + 2, mask, next_mask); 
      }
    }
  }
} 

void solve() {
  cin >> n >> m;
  dp.clear(); 
  dp.resize(n + 1, vector<long long> (1 << m));  
  dp[0][0] = 1; 
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 <<m); ++mask) {
      calc(i, 0, mask, 0); 
    }
  }
  cout << dp[n][0] << endl; 
  cout << dp[n - 1][(1 << m) - 1] << endl; 
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T; 
  cin >> T; 
  for (int i = 0; i < T; ++i) {
    solve(); 
  }
     
  return 0;
}