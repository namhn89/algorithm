using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e7 + 5 ;
int a[MAXN] ;
long long maxC = (1LL << 20) , BASE , mul , seed , k , T , n ;

long long phi(long long n)
{
    long long res = n;
    for (long long i = 2 ; i * i <= n ; ++i)
        if (n % i == 0)
        {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    if (n > 1) res -= res / n;
    return res;
}

long long __mul (long long a , long long p , long long mod)
{
    a %= mod ;
    long long res = 0;
    while (p)
    {
        if (p & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        p >>= 1;
    }
    return res;
}
long long power (long long a , long long n , long long mod)
{
    long long r = 1 ;
    while(n)
    {
        if(n & 1) r = __mul(r , a , mod);
        a = __mul(a , a , mod);
        n >>= 1 ;
    }
    return r;
}
const int MAXM = (1LL << 21) + 10 ;
long long f[MAXM] ;
int Max = 0 ;

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%lld %lld %lld %lld", &n , &k , &T , &BASE) ;
    scanf("%lld %lld", &mul , &seed) ;
    a[1] = (1LL * mul * seed + seed) % maxC ;
    Max = a[1] ;
    for(int i = 2 ; i <= n ; ++i ) a[i] = (1LL * a[i - 1] * mul + seed) % maxC , Max = max(Max , a[i]) ;
    long long phi_BASE = phi(BASE) ;
    long long Q = power(k , T , phi_BASE) ;
    f[1] = 1 % BASE ;
    for(int i = 2 ; i <= Max ; ++i ) f[i] = power(i , Q , BASE) ;
    long long ans = 0 ;
    for(int i = 1 ; i <= n ; ++i ) ans = (ans + f[a[i]] ) % BASE ;
    cout << ans << endl ;
    return 0;
}
