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
const int INF = 1e9 + 10; 

 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k; 
	vector <int> h(n + 1); 
	vector <int> dp(n + 1, INF);
	for (int i = 1; i <= n; ++i) cin >> h[i]; 
	dp[1] = 0;  
	for (int i = 2; i <= n; ++i) {
		for (int j = i - 1; j >= max(1, i - k); --j) {
			dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i])); 
		}
	}
	cout << dp[n] << endl; 
     
  	return 0;
}