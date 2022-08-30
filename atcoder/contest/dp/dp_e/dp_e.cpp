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
const int W = 2e5 + 1;
const int MOD = 1e9 + 7; 
const long long INF = 2e16 + 1; 
long long dp[W]; 

 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, w; 
	cin >> n >> w; 
	long long v = 1000 * n + 1; 
	vector <long long> weights(n + 1), values(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> weights[i] >> values[i]; 
	}
	// for (int i = 0; i <= n; ++i) {
	// 	for (int j = 0; j <= v; ++j) dp[i][j] = INF; 
	// }
	for (int i = 0; i <= v; ++i) dp[i] = INF; 
	dp[0] = 0; 
	for (int i = 1; i <= n; ++i) {
		for(int j = v ; j >= values[i]; --j) {
			dp[j] = min(dp[j], dp[j - values[i]] + weights[i]); 
		}
	}
	// cout << dp[0] << endl; 
	for (int i = v; i >= 0; --i) {
		// cout << dp[i] << endl; 
		if (dp[i] <= w){
			cout << i << endl; 
			return 0; 
		}
	}
  	return 0;
}