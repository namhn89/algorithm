using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair <long long,int> LI ;
const int MOD = 1e9 + 7 ;
const int MAXN = 5e4 + 1;
long long lcm (long long a, long long b)
{
    return  (a / __gcd(a, b) * b );
}
vector <LI> fact (long long n)
{
    vector <LI> res ;
    for(long long i = 2 ; i * i <= n ; ++i )
    {
        if (n % i == 0)
        {
            int num = 0 ;
            while(n % i == 0)
            {
                n /= i ;
                num++;
            }
            res.push_back(make_pair(i, num));
        }
    }
    if (n != 1) res.push_back(make_pair(n, 1)) ;
    return res;
}
long long power (long long a, long long n )
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = res * a ;
        a = (a * a) ;
        n >>= 1 ;
    }
    return res ;
}
int n ;
long long a[MAXN] ;
long long k ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int Test ;
    scanf("%d",&Test) ;
    while(Test--)
    {
        scanf("%d",&n) ;
        FORE(i, 1, n ) scanf("%lld", &a[i]) ;
        scanf("%lld",&k) ;
        if(k == 1)
        {
            long long ans = a[1] ;
            FORE(i, 2, n ) ans = __gcd(ans, a[i]) ;
            if (ans == k) printf("YES\n") ;
            else printf("NO\n") ;
        }
        else
        {
            vector <LI> prime = fact(k) ;
            bool ok = true ;
            vector <long long> f ;
            for(int i = 0 ; i < prime.size() ; ++i )
            {
                long long test = power(prime[i].st, prime[i].nd) ;
                vector <long long> b ;
                for(int j = 1 ; j <= n ; ++j )
                {
                    if (a[j] % test == 0) b.push_back(a[j]) ;
                }
                if (b.size() == 0)
                {
                    ok = false ;
                    break ;
                }
                else
                {
                    long long val = b[0] ;
                    for(int k = 1 ; k < b.size() ; ++k ) val = __gcd(val, b[k]) ;
                    f.push_back(val) ;
                }
            }
            if (ok == false )
            {
                printf("NO\n") ;
            }
            else
            {
                long long ans = f[0] ;
                for(int i = 0 ; i < f.size() ; ++i ) ans = lcm(ans, f[1]) ;
                if (ans == k ) printf("YES\n") ;
                else printf("NO\n");
            }
        }
    }
    return 0;
}
