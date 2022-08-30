using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 5e3 + 100;
const int MOD = 1e9 + 7; 
int dp[N][N]; 

 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s, t;
	cin >> s >> t; 
	int n =  s.size(), m = t.size(); 
	s = " " + s; 
	t = " " + t; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i] == t[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1; 
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
			}
		}
	}
	string ans = ""; 
	int x = n, y = m; 
	while(x > 0 && y > 0){
		if (s[x] == t[y] and dp[x][y] > dp[x - 1][y] and dp[x][y] > dp[x][y - 1]) {
			ans = ans + s[x]; 
			x--;
			y--; 
		}
		else {
			if (dp[x - 1][y] > dp[x][y - 1]){
				x--; 
			}
			else {
				y--; 
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans; 
	
	
     
  	return 0;
}