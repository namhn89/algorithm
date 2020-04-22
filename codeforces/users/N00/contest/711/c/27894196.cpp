using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 5 ;
const long long oo = 1e18 ;
int n , m , z ;
int cost[MAXN][MAXN] ;
int color[MAXN] ;
long long f[MAXN][MAXN][MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> z ;
    for(int i = 1 ; i <= n ; ++i ) cin >> color[i] ;
    for(int i = 1 ; i <= n ; ++i )
        for(int j = 1 ; j <= m ; ++j ) cin >> cost[i][j] ;
    for(int i = 0 ; i <= n ; ++i)
        for(int j = 0 ; j <= n ; ++ j)
           for(int k = 0 ; k <= m ; ++k ) f[i][j][k] = oo ;
    for(int i = 0 ; i <= m ; ++i ) f[0][0][i] = 0 ;
    for(int i = 1 ; i <= n ; ++i )
        for(int j = 1 ; j <= n ; ++j ) {
        if (color[i] == 0)
        {
            for(int k = 1 ; k <= m ; ++k )
            {
                if (color[i - 1] == 0)
                {
                    for(int t = 0 ; t <= m ; ++t )
                        if (k == t) f[i][j][k] = min(f[i - 1][j][t] + cost[i][k] , f[i][j][k]) ;
                        else f[i][j][k] = min(f[i - 1][j - 1][t] + cost[i][k] , f[i][j][k]) ;
                }
                else
                {
                    if (color[i - 1] == k) f[i][j][k] = min(f[i - 1][j][color[i - 1]] + cost[i][k], f[i][j][k]) ;
                    else f[i][j][k] = min(f[i - 1][j - 1][color[i - 1]] + cost[i][k], f[i][j][k]) ;
                }
            }
        }
        else {
            if (color[i - 1]) f[i][j][color[i]] = min(f[i - 1][j - 1 + (color[i] == color[i - 1]) ][color[i - 1]], f[i][j][color[i]]) ;
            else {
                for(int t = 0 ; t <= m ; t++)
                    f[i][j][color[i]] = min(f[i - 1][j - 1 + (color[i] == t) ][t], f[i][j][color[i]]) ;
            }
        }
        }
    long long ans = oo ;
    for(int i = 1 ; i <= m ;++i ) ans = min(ans , f[n][z][i]) ;
    if (ans == oo) cout << -1 << endl ;
    else cout << ans << endl;
    return 0;
}
