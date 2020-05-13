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

int largestSquare(const vector<vector<int>>& A) {
	int n = A.size(); 
	vector <vector<int>> a(n + 1, vector<int>(n + 1)); 
	vector <vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = A[i - 1][j - 1];  
			dp[i][j] = 1; 
		}
	}
	int ans = 0;  
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j ) {
			if (a[i - 1][j] == a[i][j] && a[i - 1][j - 1] == a[i][j] && a[i][j - 1] == a[i][j]) {
				dp[i][j] = max(dp[i][j], min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1); 
				ans = max(ans, dp[i][j]); 
			}
		}
	}
	return ans; 
}

 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; 
	cin >> n; 
	vector <vector<int>> a(n + 1, vector<int>(n + 1)); 
	vector <vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j]; 
			dp[i][j] = 1; 
		}
	}
	int ans = 0;  
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j ) {
			if (a[i - 1][j] == a[i][j] && a[i - 1][j - 1] == a[i][j] && a[i][j - 1] == a[i][j]) {
				dp[i][j] = max(dp[i][j], min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1); 
				ans = max(ans, dp[i][j]); 
			}
		}
	}
	cout << ans; 


     
  	return 0;
}