using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 998244353 ;
const int MAXN = 1e3 + 5 ;

int dp[MAXN][2 * MAXN][4] ;
int n , k ;
void add (int a , int &b) {
    b += a ;
    if (b >= MOD) b -= MOD ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k ;
    dp[1][1][0] = dp[1][1][3] = 1 ;
    dp[1][2][1] = dp[1][2][2] = 1 ;
    for (int i = 1 ; i <= n - 1 ; i++ )
        for (int j = 1 ; j <= 2 * n ; ++j )
            for(int mask = 0 ; mask < 4 ; ++ mask)
                for (int newmask = 0 ; newmask < 4 ; ++ newmask) {
                        int block1 = mask & 1 ; int block3 = newmask & 1 ;
                        int block2 = (mask >> 1) & 1 ; int block4 = (newmask >> 1) & 1 ;
                        int cnt = 0 ;
                        if (block1 == block3) {
                            if (block4 != block2 && block4 != block3 ) cnt++ ;
                        }
                        else {
                            if (block4 != block3) cnt++ ;
                            if (block4 != block2) cnt++ ;
                        }
                        dp[i + 1][j + cnt][newmask] = (dp[i + 1][j + cnt][newmask] + dp[i][j][mask]) % MOD ;
    }
    int ans = 0 ;
    for (int mask = 0 ; mask < 4 ; ++ mask) ans = (ans + dp[n][k][mask]) % MOD ;
    cout << ans ;

    return 0;
}
