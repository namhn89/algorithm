using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 3e5 + 1;
const int MOD = 1e9 + 7; 
vector <int> g[N]; 
int dp[N][27]; 
string s;
int deg[N], vis[N], cycle = 0; 
vector <int> topoSort; 

void dfs(int u) {
	vis[u] = 2; 
	if (cycle) return; 
	for (int v: g[u]) {
		if (vis[v] == 1) continue; 
		if (vis[v] == 2) {
			cycle = 1; 
			return; 
		}
		dfs(v); 
	}
	vis[u] = 1; 
	topoSort.push_back(u); 
}



 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; 
	cycle = 0; 
	cin >> n >> m; 
	cin >> s; 
	for (int i = 0; i < m; ++i) {
		int u,v ;
		cin >> u >> v;
		u--, v--; 
		g[u].push_back(v);  
		deg[v] += 1; 
	}
	for (int i = 0; i < n; ++i) {
		vis[i] = 0; 
	}
	for (int i = 0; i < n; ++i) {
		if (cycle) break; 
		if (!vis[i]) dfs(i); 
	}

	if (cycle) {
		cout << -1; 
		return 0; 
	}
	reverse(topoSort.begin(), topoSort.end()); 
	// for (int v: topoSort) cout << v << " "; cout << endl; 
	int ans = 0; 
	for (int u: topoSort) {
		dp[u][s[u] - 'a'] += 1; 
		for (int v: g[u]) {
			for (int j = 0; j < 26; ++j) {
				dp[v][j] = max(dp[v][j], dp[u][j]); 
			}
		}
	}
	for (int i = 0; i < n; ++i) ans = max(ans, dp[i][s[i] - 'a']); 
	cout << ans; 
  	return 0;
}