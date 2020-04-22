using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int n ;
int cnt[MAXN] ;
int pw[MAXN] ;
int a[MAXN] ;
int dp[71][(1LL << 19)] ;
int prime[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67};
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d", &n) ;
    for(int i = 1 ; i <= n ; ++i ) {
        int x ;
        scanf("%d",&x) ;
        cnt[x] ++ ;
    }
    pw[0] = 1 ;
    for(int i = 1 ; i <= n ; ++i ) pw[i] = (pw[i - 1] * 2LL) % MOD ;
    for(int i = 1 ; i <= 70 ; ++i ) {
            int p = i ;
            for(int j = 0 ; j < 19 ; ++j ) {
                int k = 0 ;
                while(p % prime[j] == 0) k++ , p /= prime[j] ;
                if (k & 1) a[i] ^= (1 << j) ;
            }
    }
    dp[0][0] = 1 ;
    for(int i = 0 ; i <= 69 ; ++i ) {
        int newState = i + 1 ;
        int curState = i ;
        if(cnt[i + 1])
        {
            for(int mask = 0 ; mask < (1 << 19) ; ++ mask )
            {
                dp[newState][mask ^ a[i + 1]] += (1LL * dp[curState][mask] * (pw[cnt[i + 1] - 1]) % MOD );
                dp[newState][mask ^ a[i + 1]] %= MOD ;
                dp[newState][mask] += (1LL * dp[curState][mask] * (pw[cnt[i + 1] - 1]) % MOD) ;
                dp[newState][mask] %= MOD ;
            }
        }
        else for(int mask = 0 ; mask < (1 << 19) ; ++ mask) { dp[newState][mask] += dp[curState][mask] ; dp[newState][mask] %= MOD ; }
    }
    dp[70][0] += (MOD - 1) ;
    dp[70][0] %= MOD ;
    printf("%d\n" , dp[70][0]) ;




    return 0;
}
