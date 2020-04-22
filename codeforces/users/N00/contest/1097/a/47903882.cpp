#include<bits/stdc++.h>
using namespace std ;

string foo, bar  ;

int main(){
	#define NAME "sol" 
	//freopen(NAME".inp", "r", stdin) ; freopen(NAME".out", "w", stdout) ;

	cin >> foo ;

	for (int i = 1; i <= 5; ++ i) {
		 cin >> bar ;
		 if (foo[0] == bar[0] || foo[1] == bar[1]) return cout << "YES", 0; 
	}

	cout << "NO" ;

	return 0 ;
}