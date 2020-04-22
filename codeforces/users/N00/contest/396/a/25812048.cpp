using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 10 ;
const int N = 1e6 ;
map <int, int> f ;
long long fact[MAXN], infact[MAXN] ;
long long nCr (int n, int r)
{
    if (r > n) return 0 ;
    long long res = (fact[n] * infact[n - r] % MOD) * infact[r] % MOD ;
    res %= MOD ;
    return res ;
}
long long power (long long a, long long n)
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
int n ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    fact[0] = infact[0] = 1 ;
    for(int i = 1 ; i <= N ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    for(int i = 1 ; i <= N ; ++i ) infact[i] =  power(fact[i] , MOD - 2) ;
    scanf("%d", &n) ;
    FORE(i, 1, n )
    {
        int value ;
        scanf("%d",&value) ;
        for(int i = 2 ; i * i <= value ; ++i )
        {
            while(value % i == 0)
            {
                value /= i ;
                f[i]++;
            }
        }
        if ( value != 1 ) f[value]++;
    }
    map <int, int> ::iterator it ;
    long long ans = 1 ;
    for(it = f.begin() ; it != f.end() ; ++it)
    {
        int k = it -> nd;
        ans *= nCr(n + k - 1, n - 1) ;
        ans %= MOD ;
    }
    printf("%lld\n", ans );


    return 0;
}
