#include<bits/stdc++.h>
using namespace std ;

const int N = 3e5 + 10 ;

int n, m ;

int a[N] ;

int dp[N] ;

bool check(int value) {

	for (int i = 1; i <= n; ++ i) {
		int foo = (a[i] + value) ;
		if (foo >= m) {
			dp[i] = max(dp[i - 1], a[i]) ;
			foo %= m ;
			if (foo >= dp[i - 1]) dp[i] = dp[i - 1] ;
		}
		else {
			if (dp[i - 1] > foo) return false ;
			dp[i] = max(dp[i - 1], a[i]) ;
		}
	}

	return true ;

}
 
int main(){

	cin >> n >> m ;

	for (int i = 1; i <= n; ++ i) cin >> a[i] ;

	int l = 0, r = m ;	
	
	while (l < r) {
		int mid = (l + r) / 2 ;
		if (check(mid)) r = mid ;
		else l = mid + 1 ;
	}

	cout << l << endl ;

	return 0 ;
}