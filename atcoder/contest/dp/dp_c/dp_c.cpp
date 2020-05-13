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


 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; 
	cin >> n ; 
	vector <int> a(n + 1), b(n + 1), c(n + 1), dp(n + 1), dp1(n + 1), dp2(n + 1); 
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i] >> c[i]; 
	for (int i = 1; i <= n; ++i) {
		dp[i] = max(dp[i], max(dp1[i - 1] + a[i], dp2[i - 1] + a[i]));
		dp1[i] = max(dp1[i], max(dp[i - 1] + b[i], dp2[i - 1] + b[i])); 
		dp2[i] = max(dp2[i], max(dp1[i - 1] + c[i], dp[i - 1] + c[i])); 
	}
	cout << max(max(dp[n], dp2[n]), dp1[n]) << endl; 
     
  	return 0;
}