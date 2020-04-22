using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e7 + 5 ;
long long dp[MAXN] , n , x , y ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> x >> y ;
    dp[1] = x ;
    for (int i = 2 ; i <= n ; i++) {
		dp[i] = dp[i - 1] + x;
		if (i % 2 == 0)
			dp[i] = min(dp[i] , dp[i / 2] + y);
		if (i % 2)
			dp[i] = min(dp[i] , min(dp[(i - 1) / 2] , dp[(i + 1) / 2]) + x + y);
	}
	cout << dp[n] << endl;
    return 0;
}
