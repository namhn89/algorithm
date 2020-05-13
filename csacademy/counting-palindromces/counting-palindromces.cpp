#include<bits/stdc++.h>
using namespace std; 

const int MOD = 1e9 + 7; 
const int N = 1e3 + 5; 
const int K = 26; 

int dp[N][N]; 
string s; 
void calc(int l, int r) {
	if (l == r) {
		dp[l][r] = 1; 
	}
	else if (s[l] != s[r]) {
		dp[l][r] = (dp[l][r] + dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1]); 
	}
	else if (s[l] == s[r]) {
		dp[l][r] = 1 + dp[l + 1][r] + dp[l][r - 1]; 
	}
}

int main() {
    cin >> s; 
    int n = s.size(); 
    s = " " + s; 
	for (int l = n; l > 0; --l) {
		for (int r = l; r <= n; ++r) {
			calc(l, r); 
		}
	}
	cout << dp[1][n] << endl; 
	
    return 0; 
}