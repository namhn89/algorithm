#include<bits/stdc++.h>
using namespace std ;

int n, m, q ;

char s[15] ;

int w[15] ;

pair < int , int > sum[5010] ;

int num[5010] ;

int dp[5010][5010] ;

int main(){
	#define NAME "Cezar"
	//freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

	scanf("%d %d %d", &n, &m, &q) ;

	for (int i = 1; i <= n; ++ i) scanf("%d", &w[i]) ;

	for (int mask = 0; mask < (1 << n); ++ mask){
		for (int i = 0; i < n; ++ i){
			if((mask & (1 << i))) sum[mask].first += w[i + 1] ;
		}
		sum[mask].second = mask ;
	}

	sort(sum, sum + (1 << n)) ;

	for (int i = 1; i <= m; ++ i){
		scanf("%s", s) ;
		int foo = 0 ;
		for (int j = 0; j < n; ++ j){
			if(s[j] == '1') foo += (1 << j) ;
		}
		num[foo] ++ ;
	}

	for (int foo = 0; foo < (1 << n); ++ foo){
		for (int bar = 0; bar < (1 << n); ++ bar){
			int magic = num[foo ^ ((1 << n) - 1 - sum[bar].second)] ;
			dp[foo][bar] = magic ;
			if(bar) dp[foo][bar] += dp[foo][bar - 1] ;
		}
	}

	while(q --){
		int k ;
		scanf("%s %d", s, &k) ;
		int foo = 0 ;
		for (int i = 0; i < n; ++ i){
			if(s[i] == '1') foo += (1 << i) ;
		}
		int l = 0, r = (1 << n) - 1 ;
		while(l < r){
			int mid = (l + r + 1) / 2 ;
			if(sum[mid].first <= k) l = mid ;
			else r = mid - 1 ;
		}
		printf("%d\n", dp[foo][l]) ;
	}

	return 0 ;
}
