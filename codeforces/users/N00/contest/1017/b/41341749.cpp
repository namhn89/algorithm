#include<bits/stdc++.h>
using namespace std ;

int n ;

char a[100010], b[100010] ;

int num[2][2] ;

int main(){
	#define NAME ""
	//freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

	scanf("%d", &n) ;

	scanf("%s", a + 1) ; scanf("%s",b + 1) ;

	long long ans = 0 ;

	for (int i = 1; i <= n; ++ i){
		int foo = a[i] - '0', bar = b[i] - '0' ;
		for (int j = 0; j <= 1; ++ j){
			for (int k = 0; k <= 1; ++ k){
				if(((foo | k) != (j | k)) || ((j | bar) != (foo | bar))) ans += 1ll * num[j][k] ;
			}
		}
		num[foo][bar] ++ ;
	}

	printf("%lld", ans) ;

	return 0 ;
}