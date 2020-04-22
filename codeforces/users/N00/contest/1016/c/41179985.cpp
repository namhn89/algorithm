#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

const long long N = 3e5 + 10; 
long long n ;
long long a[N], b[N] ;
long long dp[N][2];
long long preAB[N];
long long sufAB[N];
void build () { 
	for (long long i = n; i >= 1; i--) {
		sufAB[i] += a[i] + b[i] + sufAB[i + 1];
	}
	for (long long i = 1; i <= n; i++) {
		preAB[i] = preAB[i - 1] + 2 * (i - 1) * (a[i] + b[i]);
		if(i & 1) preAB[i] += b[i];
		else preAB[i] += a[i];
	}
}
int main(){
	#define file "C"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
	cin >> n ;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	for (long long i = 1; i <= n; i++) cin >> b[i];
	build();
	long long ans = preAB[n];

	for (long long i = n; i >= 1; i--){
		dp[i][0] = dp[i + 1][0] + 2 * (i - 1) * a[i] + (2 * n - 1) * b[i] - sufAB[i + 1];  
		dp[i][1] = dp[i + 1][1] + 2 * (i - 1) * b[i] + (2 * n - 1) * a[i] - sufAB[i + 1];  
		ans = max(ans, preAB[i - 1] + dp[i][(1 - (i & 1))]);
	}

	cout << ans << endl ;

	return 0 ;
}