using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 15 + 5 ;
int dp[(1 << MAXN)][MAXN] ;
int cost[MAXN][MAXN] ;
int n ;
const int oo = 1e9 + 100 ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n ;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j) cin >> cost[i][j] ;
    for(int mask = 0 ; mask <= (1 << n) ; ++mask )
         for(int i = 0 ; i < n ; ++i) dp[mask][i] = oo ;
    for(int mask = 0 ; mask < (1 << n) ; ++mask)
        for(int i = 0 ; i < n ; ++i ) if (mask & (1 << i)) {
            int cur = mask ^ (1 << i) ;
            if (cur) {
               for(int k = 0 ; k < n ; ++k )
                    if(cur & (1 << k)) dp[mask][i] = min(dp[cur][k] + cost[k][i] , dp[mask][i]) ;
            }
            else dp[mask][i] = 0 ;
    }
    int ans = oo ;
    for(int i = 0 ; i < n ; ++i) ans = min(ans , dp[(1 << n ) - 1][i]) ;
    cout << ans << endl;
    return 0;
}
