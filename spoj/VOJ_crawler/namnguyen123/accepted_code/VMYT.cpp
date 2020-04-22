using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

inline void read (long long &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const ll MOD = 1e9 + 7 ;
const ll mod = 1e9 + 6 ;
const int MAXN = 51 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
long long a[MAXN] ;
struct Matrix
{
    long long data[51][51] ;
    Matrix()
    {
        memset(data, 0, sizeof(data));
    }
    Matrix operator * (Matrix b)
    {
        Matrix res;
        Matrix a = *this;
        FORE (x, 1, 50)
        {
            FORE (y, 1, 50)
            {
                FORE (z, 1, 50)
                {
                    res.data[x][y] = (res.data[x][y] + a.data[x][z] * b.data[z][y]) % mod;
                    res.data[x][y] %= mod;
                }
            }
        }
        return res;
    }
    Matrix power(ll p)
    {
        Matrix t = *this;
        Matrix res = t;
        p--;
        while (p)
        {
            if (p & 1LL) res = (res * t);
            t = t * t;
            p >>= 1LL;
        }
        return res;
    }
};
long long n, k ;
ll power(ll a, ll n)
{
    ll r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % MOD ;
        a = ( a * a ) % MOD ;
        n >>= 1 ;
    }
    return r;
}
int main()
{
    // freopen("in", "r", stdin);
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    read(n), read(k) ;
    FORE(i, 1, k ) read(a[i]);
    if (n == k + 1)
    {
        ll ans = 1 ;
        FORE(i, 1, k)
        {
            ans *= a[i] ;
            ans %= MOD ;
        }
        printf("%lld\n",ans);
    }
    else
    {
        Matrix base ;
        Matrix res ;
        FORE(i, 1, k )
        {
            FORE(j, 1, k )
            {
                base.data[i][j] = 0 ;
            }
        }
        FORE(i, 1, k )
        {
            base.data[k][i] = 1;
            res.data[1][i] = 1 ;
        }
        FORE(i, 1, k - 1) base.data[i][i + 1] = 1 ;
        base = base.power(n - k - 1);
        /* FORE(i, 1, k )
         {
             FORE(j, 1, k ) cout << base.data[i][j] << " ";
             cout << endl;
         }
         cout << endl ;
         */
        res = res * base ;
        ll ans = 1 ;
        FORE(i, 1, k )
        {
            ans *= power(a[i], res.data[1][i]);
            ans %= MOD ;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
