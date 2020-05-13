#include<bits/stdc++.h>
using namespace std; 

const int MOD = 1e9 + 7; 
const int N = 1e3 + 5; 
const int K = 26; 

int dp[N][N][K]; 
string s; 

void solve(int l, int r, int c) {
    if (l > r) {
        dp[l][r][c] = 0; 
    }
    else if (l == r && int(s[l] - 'a') == c)  {
        dp[l][r][c] = 1; 
    }
    else if (int(s[l] - 'a') != c or int(s[r] - 'a') != c) {
        dp[l][r][c] = (dp[l][r][c] + dp[l][r - 1][c]) % MOD; 
        dp[l][r][c] = (dp[l][r][c] + dp[l + 1][r][c]) % MOD; 
        dp[l][r][c] = (dp[l][r][c] - dp[l + 1][r - 1][c] + MOD) % MOD; 
    }
    else if (int(s[l] - 'a') == c and int(s[r] - 'a') == c) {
        dp[l][r][c] = 2;
        for (int k = 0; k < 26; ++k) {
            dp[l][r][c] = (dp[l][r][c] + dp[l + 1][r - 1][k]) % MOD; 
        }
    }
}

int main() {
    cin >> s; 
    int n = s.size(); 
    s = " " + s; 
    for (int l = n; l > 0; --l) {
        for (int r = l; r <= n; ++r) {
            for (int c = 0; c < 26; ++c) {
                solve(l, r, c); 
            }
        }
    }
    int ans = 0; 
    for (int c = 0; c < 26; ++c) {
        ans = (ans + dp[1][n][c]) % MOD; 
    }
    cout << ans << endl; 
    return 0; 
}