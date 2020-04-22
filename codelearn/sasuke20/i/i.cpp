using namespace std;
#include<bits/stdc++.h>

const int MAXN = 5e3 + 1;
int dp[MAXN][MAXN];

string convertString(string a, string b) {
    int n = max(a.size(), b.size());
    if (a.size() < b.size()) return "NO";
    int nA = a.size();
    int nB = b.size();
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= nA; ++i) {
        if (a[i - 1] >= 'A' && a[i - 1] <= 'Z') break;
        dp[i][0] = 1;
    }
    for(int i = 1; i <= nA; ++i) {
        for(int j = 1; j <= nB; ++j) {
            if (j > i) {
                dp[i][j] = false;
                continue;
            }
            if (a[i - 1] >= 'A' && a[i - 1] <= 'Z') {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else dp[i][j] = false;
            }
            else {
                dp[i][j] = dp[i - 1][j] | dp[i][j] ;
                if (int(a[i - 1]) - 32 == int(b[j - 1])) {
                    dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                }
            }
        }
    }
    if (dp[nA][nB]) return "YES";
    return "NO";
}