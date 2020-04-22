using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e7 + 5 ;
long long a[MAXN] ;
long long maxC = (1LL << 20), BASE, mul, seed, k, T, n ;

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
const int X = 1e6 ;
long long __mul (long long a , long long b , long long mod)
{
    long long b1 = b / X , b2 = b % X ;
    long long res = ( (a * b1) % mod * X + a * b2 ) % mod ;
    return res ;
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

int main()
{
#define TASK "VOSPOW"
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    scanf("%lld %lld %lld %lld", &n , &k , &T , &BASE) ;
    scanf("%lld %lld", &mul , &seed) ;
    long long phi_BASE = phi(BASE) ;
    long long Q = power(k , T , phi_BASE) ;
    a[1] = (1LL * mul * seed + seed) % maxC ;
    for(int i = 2 ; i <= n ; ++i ) a[i] = (1LL * a[i - 1] * mul + seed) % maxC ;
    for(int i = 1 ; i <= n ; ++i ) if (!f[a[i]] && a[i] != 0) f[a[i]] = power(a[i] , Q , BASE) ;
    long long ans = 0 ;
    for(int i = 1 ; i <= n ; ++i ) ans = (ans + f[a[i]] ) % BASE ;
    cout << ans << endl ;
    return 0;
}
// 986037504
