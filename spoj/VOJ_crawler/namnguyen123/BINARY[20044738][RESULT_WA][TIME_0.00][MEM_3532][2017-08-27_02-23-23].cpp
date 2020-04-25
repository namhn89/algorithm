using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e2 + 5 ;
const int Max = 50 ;
long long c[MAXN][MAXN], b[MAXN][MAXN] ;
int a[MAXN] ;
int main()
{
#define TASK "CZERO"
    //freopen(TASK".INP","r",stdin);
    //freopen(TASK".OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    c[0][0] = 1 ;
    for(int i = 1 ; i <= Max ; ++i )
        for(int j = 0 ; j <= Max ; ++j ) c[i][j] = c[i - 1][j] + c[i - 1][j - 1] ;
    int n , k ;
    while(cin >> n >> k )
    {
        int len = log2(n) + 1 ;
        long long ans = 0 ;
        int x = n ;
        int i = 0 ;
        while(x)
        {
            i++ ;
            a[i] = (x & 1) ;
            x >>= 1 ;
        }
        for(int i = k + 1 ; i < len ; ++i ) ans = ans + c[i - 1][k] ;
        int cnt0 = k ;
        for(int i = len - 1 ; i >= 1 ; --i )
        {
            if (a[i] == 1) ans = ans + c[i - 1][cnt0 - 1] ;
            else cnt0-- ;
            if (cnt0 < 0) break ;
        }
        int cnt = len - __builtin_popcount(n) ;
        if (cnt == k) ans ++ ;
        cout << ans << endl;
    }
    return 0;
}

