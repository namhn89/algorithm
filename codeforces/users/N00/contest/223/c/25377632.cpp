using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e4 + 5 ;
const int N = 1e4 + 10 ;
long long power (long long a, long long n)
{
    long long res = 1;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
long long F[MAXN] , ans[MAXN] ;
int n, k, a[MAXN] ;
void Init ()
{
    F[0] = 1;
    for(int i = 1 ; i <= n ; ++i )
    {
        F[i] = (F[i - 1] * (k + i - 1)) % MOD ;
        F[i] = (F[i] * power(i , MOD - 2) ) % MOD ;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i] ;
    Init() ;
    for(int i = 1 ; i <= n ; ++i ) {
         for(int j = 1 ; j <= i ; ++j ) ans[i] = (ans[i] + ( a[j] * F[i - j] ) % MOD ) % MOD ;
    }
    for(int i = 1 ; i <= n ; ++i ) cout << ans[i] << " ";
    return 0;
}
