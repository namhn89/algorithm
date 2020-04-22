using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long dp[MAXN][20] ;
int a[20] ;
int n, k ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k ;
    for(int i = 0 ; i < n ; ++i) cin >> a[i] ;
    for(int i = 0 ; i < n ; ++i) dp[0][i] = 1 ;
    for (int mask = 0; mask < 1 << n; ++mask)
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i))
            {
                int cur = mask ^ (1 << i);
                if (cur)
                {
                    for (int j = 0; j < n; ++j)
                        if (cur & (1 << j))
                            if (abs(a[i] - a[j]) > k)
                                dp[mask][i] += dp[cur][j];
                }
                else dp[mask][i]++ ;

            }
    long long ans = 0 ;
    for(int i = 0 ; i < n ; ++i) ans += dp[(1 << n ) - 1][i] ;
    cout << ans << endl ;

    return 0;
}
