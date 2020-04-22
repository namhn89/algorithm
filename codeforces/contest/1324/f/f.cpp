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

vector<int> g[N]; 
int n; 
int dp[N], a[N], ans[N];  

void dfs (int u, int parent) {
  dp[u] = a[u]; 
  for (int v: g[u]) {
    if (v == parent) continue; 
    dfs(v, u); 
    dp[u] += max(0, dp[v]); 
  }
}

void dfs_reverse(int u, int parent) {
  ans[u] = dp[u]; 
  for (int v: g[u]) {
    if (v == parent) continue; 
    dp[u] -= max(0, dp[v]);
    dp[v] += max(0, dp[u]);
    dfs_reverse(v, u); 
    dp[v] -= max(0, dp[u]); 
    dp[u] += max(0, dp[v]);  
  }
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n; 
  for (int i = 0; i < n; ++i) {
    cin >> a[i]; 
    if (a[i] == 0) a[i] = -1;
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v; 
    u--, v--; 
    g[u].push_back(v);
    g[v].push_back(u); 
  }
  dfs(0, -1); 
  // for (int i = 0; i < n; ++i) cout << dp[i] << " "; 
  dfs_reverse(0, -1); 
  for (int i = 0; i < n; ++i) cout << ans[i] << " "; 
  
     
  return 0;
}