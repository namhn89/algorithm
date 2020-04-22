using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

long long power (long long a, long long n, long long mod )
{
    a %= mod ;
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        n >>= 1 ;
    }
    return res ;
}
long long power2(long long x, long long n, long long p)  // (x ^ (2 ^ n)) mod p
{
    if(x % p == 0) return 0;
    long long tmp = power(2, n, p - 1);
    return power(x, tmp, p );
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Test ;
    scanf("%d",&Test) ;
    while(Test --)
    {
        long long k, l, r, p ;
        scanf("%lld %lld %lld %lld", &k, &l,&r, &p ) ;
        if (p == 2)
        {
            if (k % 2 == 1) cout << 0 << endl;
            else cout << 1 << endl;
        }
        else
        {
            if (k == 1) cout << 2 % p<< endl;
            else
            {
                long long denominator = power2 (k, r + 1, p ) - 1 + p ;
                long long numerator = power2(k, l, p ) - 1 + p ;
                denominator %= p ;
                numerator %= p ;
                long long res ;
                if (numerator == 0 )
                {
                    res = power(2 , r - l + 1 , p ) ;
                }
                else
                {
                    res = power(numerator, p - 2, p ) ;
                    res = (res * denominator) % p ;
                }
                if (k & 1) {
                    res *= power( power(2 , r - l , p) , p - 2 , p) ;
                    res %= p ;
                }
                cout << res << endl;
            }
        }
    }

    return 0;
}
