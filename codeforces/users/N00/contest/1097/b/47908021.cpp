#include<bits/stdc++.h>
using namespace std ;

int n ;

int a[20] ;

int main(){
	#define NAME "" 
	//freopen(NAME".inp", "r", stdin) ; freopen(NAME".out", "w", stdout) ;

	cin >> n ;

	int total = 0 ;

	for (int i = 0; i < n; ++ i) cin >> a[i], total += a[i] ;

	for (int mask = 0; mask < (1 << n); ++ mask) {
		int sum = 0 ;
		for (int i = 0; i < n; ++ i) {
			if ((mask & (1 << i))) sum += a[i] ;
		}
		if (abs (total - 2 * sum) % 360 == 0) return cout << "YES", 0 ;
	}

	cout << "NO" << endl ;

	return 0 ;
}