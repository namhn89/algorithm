using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int MAXK = 20 ;
const long long oo = 1e18 ;
long long dp[MAXN][MAXK] ;
int a[MAXN][10], n ;
int getbit (int x, int u)
{
    return  ( (x >> u) & 1 );
}
bool check (int x , int y)
{
    for(int i = 0 ; i <= 3 ; ++i ) if (getbit(x , i) == getbit(y , i) && getbit(x , i) == 1) return false ;
    return true ;
}
int calc (int v) {
   if (v == 3 || v == 6 || v == 7 || v == 11 || v == 12 || v == 13 || v == 14 || v == 15) return 0 ;
   return 1 ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d", &n) ;
    int Max = 0 ;
    for(int i = 0 ; i <= 3 ; ++i )
        for(int u = 1 ; u <= n ; ++u)
        {
            scanf("%d", &a[u][i]) , Max = max(Max, a[u][i]) ;
        }
    if (Max < 0)
    {
        cout << Max << endl ;
        return 0 ;
    }
    for(int u = 1 ; u <= n ; ++u)
    {
        for(int mask_u = 0 ; mask_u < (1 << 4) ; ++ mask_u )
        {
            for(int mask = 0 ; mask < (1 << 4) ; ++ mask )
            {
                if (check (mask , mask_u) && calc (mask) && calc (mask_u) )
                {
                    int val = 0 ;
                    for(int j = 0 ; j <= 3 ; ++j ) if ( (mask >> j) & 1 ) val += a[u][j] ;
                    dp[u][mask] = max(dp[u][mask] , dp[u - 1][mask_u] + val) ;
                }
            }
        }
    }
    long long ans = -oo ;
    for(int mask = 0 ; mask < (1 << 4) ; ++mask) ans = max(ans , dp[n][mask]) ;
    printf("%lld\n",ans) ;
    return 0;
}
