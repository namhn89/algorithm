using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e3 + 1;
const int MOD = 1e9 + 7;

int dp[N][3]; 

int minTyping(std::string s) {
    int n = s.length();

    dp[0][0] = 0; dp[0][1] = 2;

    for (int i = 1; i <= n; ++i) {
        if ('A' <= s[i - 1] && s[i - 1] <= 'Z') {
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
            dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1]);
        } else if ('a' <= s[i - 1] && s[i - 1] <= 'z') {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 2);
            dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 4);
        }
        else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
        }
    }

    return dp[n][0];
} 

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  return 0;
}