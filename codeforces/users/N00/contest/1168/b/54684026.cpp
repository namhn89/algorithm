#include<bits/stdc++.h>
using namespace std ;

string s ;

vector < pair < int , int > > lis ;

int main(){

	cin >> s ;

	int len = s.size() ;

	for (int i = 0; i < len; ++ i) {
		for (int j = 1; j <= 15; ++ j) {
			if (i - j < 0) continue ;
			if (i + j >= len) continue ;
			if (s[i - j] == s[i] && s[i] == s[i + j]) lis.push_back(make_pair(i - j, i + j)) ;
		}
	}

	sort(lis.begin(), lis.end()) ;

	int cur = len ;

	long long ans = 0 ;

	for (int i = len - 1; i >= 0; -- i) {
		while (!lis.empty() && lis.back().first >= i) cur = min(cur, lis.back().second), lis.pop_back() ;
		ans += 1ll * (len - cur) ;
	}

	cout << ans << endl ;

	return 0 ;
}
