using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e2 + 1;
const int W = 1e5 + 1; 
const int MOD = 1e9 + 7; 
const int INF =  1e9 + 100; 
long long dp[N][W]; 
 
 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, w; 
	cin >> n >> w ; 
 
	vector <int> weights(n + 1), values(n + 1);
 
	for (int i = 1; i <= n; ++i) {
		cin >> weights[i] >> values[i]; 
	}
	for(int i = 0; i <= n; ++i) dp[i][0] = 0; 
	for(int i = 0; i <= w; ++i) dp[0][i] = 0;  
	for (int i = 1; i <= n; ++i) {
		for(int j = 0; j <= w; ++j) {
			if (j >= weights[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]); 
			}
			else {
				dp[i][j] = dp[i - 1][j]; 
			}
		}
	}
	cout << dp[n][w] << endl; 
 
 
     
  	return 0;
}