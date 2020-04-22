using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
int n, m, dp[MAXN], trace[MAXN], F[MAXN] ;
vector <int> divisor[MAXN] , g[MAXN] ;
void sieve ()
{
    for(int i = 1 ; i <= m ; ++i )
        for(int j = 2 * i ; j <= m ; j += i) divisor[j].push_back(i) ;
}
long long phi(long long n)
{
    long long result = n;
    for (long long i = 2 ; i * i <= n ; ++i)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}
long long power (long long a , long long n , long long mod)
{
    long long res = 1 ;
    while(n)
    {
        if(n & 1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        n >>= 1 ;
    }
    return res ;
}
long long Inverse (long long x , long long mod )
{
    return power(x , phi(mod) - 1 , mod) % mod ;
}
long long moduloInverse(long long a , long long m)
{
    long long q , r , y0 = 0 , y1 = 1 , y , mod = m  ;
    while (a > 0)
    {
        q = m / a ;
        r = m % a ;
        if (!r) return (y % mod + mod) % mod;
        y = y0 - y1 * q ;
        y0 = y1 ;
        y1 =  y;
        m = a;
        a = r ;
    }
}
long long solve (long long u , long long v , long long mod ) {
   long long res = v * Inverse(u , mod) ;
   res %= mod ;
   return res ;
}
int main()
{
#define TASK "801E"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &m) ;
    sieve() ;
    for(int i = 0 ; i < n ; ++i )
    {
        int x ;
        scanf("%d",&x) ;
        F[x] = 1 ;
    }
    for(int u = 0 ; u < m ; ++u )
    {
        if (!F[u])
        {
            int v = __gcd(m, u) ;
            g[v].push_back(u) ;
        }
    }

    for(int u = 1 ; u <= m ; ++u )
    {
        dp[u] = g[u].size() ;
        TR(divisor[u], it)
        {
            if (dp[*it] + g[u].size() > dp[u])
            {
                dp[u] = dp[*it] + g[u].size() ;
                trace[u] = *it ;
            }
        }
    }
    vector <int> ans ;
    int u = m ;
    while (u != 0)
    {
        TR(g[u], it) ans.push_back(*it) ;
        u = trace[u] ;
    }
    ans.push_back(1) ;
    reverse(ans.begin() , ans.end() ) ;
    //for(int i = 0 ; i < ans.size() ; ++ i) cout << ans[i] << " "; cout << endl ;
    cout << ans.size() - 1 << endl ;
    for(int i = 0 ; i < ans.size() - 1 ; ++i )
    {
        long long u = ans[i] , v = ans[i + 1] ;
        long long d = __gcd(u , (long long)m ) ;
        cout << solve(u / d , v / d , m / d) << " ";
    }
    return 0;
}
