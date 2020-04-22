using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long dp[1 << 20][20] , cost[21][21] , a[21] ;
int n , m , k ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k ;
    long long ans = 0 ;
    for(int i = 0 ; i < n ; ++i ) cin >> a[i] ;
    for(int i = 0 ; i < k ; ++i ) {
        long long u , v , w ;
        cin >> u >> v >> w ;
        u-- ; v --;
        cost[u][v] = max(cost[u][v] , w) ;
    }
    for(int i = 0 ; i < n ; ++i ) dp[1 << i][i] = a[i] ;
    for(int mask = 0 ; mask < (1 << n) ; ++mask) {
        for(int i = 0 ; i < n ; ++i ) {
            if (mask & (1 << i)) {
                for(int j = 0 ; j < n ; ++j ) {
                    if ((mask & (1 << j)) && i != j) {
                        dp[mask][i] = max(dp[mask][i] , dp[mask ^ (1 << i)][j] + a[i] + cost[j][i]);
                    }
                }
            }
        }
    }
    for(int mask = 0 ; mask < (1 << n) ; ++mask )
        for(int i = 0 ; i < n ; ++i ) if (__builtin_popcount(mask) == m) ans = max(ans , dp[mask][i]) ;
    cout << ans ;

    return 0;
}
