using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXM = (1 << 19) + 1 ;
const int MAXMOD = 1e2 + 10 ;
string S ;
int M ;
long long dp[MAXM][MAXMOD] ;
int a[25] ;
long long fact[25] ;
int cnt[25] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> S >> M ;
    int n = S.size() ;
    fact[0] = 1 ;
    for(int i = 1 ; i <= 19 ; ++i ) fact[i] = fact[i - 1] * i ;
    FOR( i, 0, n ) a[i] = S[i] - '0' ;
    FOR( i, 0, n ) cnt[a[i]] ++ ;
    dp[(1 << n) - 1][0] = 1 ;
    for(int mask = (1 << n) - 2 ; mask >= 0 ; mask-- )
    {
        for(int mod = 0 ; mod < M ; ++ mod )
        {
            for(int j = 0 ; j < n ; ++j )
            {
                if (! (mask & (1 << j) ) ) dp[mask][mod] += dp[mask | (1 << j) ][ (mod * 10 + a[j]) % M ] ;
            }
        }
    }
    long long ans = 0 ;
    for(int i = 0 ; i < n ; ++i )
    {
        if (a[i]) ans += dp[(1 << i)][a[i] % M] ;
    }
    for(int i = 0 ; i <= 9 ; ++i ) ans /= fact[cnt[i]] ;
    printf("%lld\n", ans ) ;
    return 0;
}

