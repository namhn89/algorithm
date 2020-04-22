#include<bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 ;

char s[N] ;

int cnt[3 * N] ;

int main(){
	#define NAME "sol" 
	//freopen(NAME".inp", "r", stdin) ; freopen(NAME".out", "w", stdout) ;

	int n ; scanf("%d", &n) ;

	int ans = 0 ;

	for (int i = 1; i <= n; ++ i) {
		scanf("%s", s + 1) ;
		int len = strlen(s + 1) ;
		int sum = 0, minvalue = 0;
		for (int j = 1; j <= len; ++ j) {
			if (s[j] == '(') sum ++ ;
			else sum -- ;
			minvalue = min(minvalue, sum) ;
 		}
 		if (sum == 0) {
 			if (minvalue < 0) continue ;
 			if (cnt[0]) ans ++ , cnt[0] -- ;
 			else cnt[0] ++ ; 
 		}
 		else if (sum > 0) {
 			if (minvalue < 0) continue ;
 			else {
 				if (cnt[-sum + N]) ans ++, cnt[-sum + N] -- ;
 				else cnt[sum + N] ++ ;
 			}
 		}
 		else {
 			if (minvalue < sum) continue ;
 			else {
 				if (cnt[-sum + N]) ans ++, cnt[-sum + N] -- ;
 				else cnt[sum + N] ++ ;
 			}
 		}
	}
	
	cout << ans << endl ;

	return 0 ;
}