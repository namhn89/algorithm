using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
const int MAXN = 505 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll fib[MAXN];
ll f[MAXN][MAXN];
ll mul(ll a ,ll b ,ll mod)
{
    ll t = a, r = 0 ;
    while(b)
    {
        if(b%2 == 1 ) r = (r + t ) % mod;
        t = (t+t) %mod;
        b/=2;
    }
    return r;
}
int main()
{
     //freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int k ;
    scanf("%d",&k);
    while(k--)
    {
        ll x, y ;
        ll a, b, MOD ;
        scanf("%lld %lld %lld %lld %lld" , &x ,&y,&a,&b,&MOD);
        FORE(i , 1 ,max(x,y))
        {
            f[i][0] = i ;
            f[0][i] = i ;
        }
        fib[1] = 1;
        fib[2] = 1;
        FORE(i, 3, max(x,y) )
        {
            fib[i] = (fib[i-1] + fib[i-2] )% MOD ;
        }
        FORE(i, 1, x)
        {
            FORE(j, 1, y)
            {
                f[i][j] = mul(f[i-1][j], a, MOD) + mul(f[i][j-1], b, MOD) + fib[__gcd(i,j)]%MOD ;
            }
        }
        printf("%lld\n",f[x][y]);
    }
    return 0;
}
