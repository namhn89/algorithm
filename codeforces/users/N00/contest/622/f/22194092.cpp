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

inline void read (int &x)
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

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;

int a[MAXN];
int fac[MAXN];
int rfac[MAXN];
int pref[MAXN];
int suff[MAXN];

int power(int n, int k, int p = MOD)
{
    int r = 1;
    for (; k; k >>= 1)
    {
        if (k & 1) r = (long long) r * n % p;
        n = (long long) n * n % p;
    }
    return r;
}
void build()
{
    fac[0] = rfac[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fac[i] = (long long) fac[i - 1] * i % MOD;
        rfac[i] = power(fac[i], MOD - 2);
    }
}
int interpolation(int x, int k)
{
    pref[0] = suff[k + 1] = 1;
    for (int i = 1; i <= k; i++)
    {
        pref[i] = (long long) pref[i - 1] * (x - i + MOD) % MOD;
    }
    for (int i = k; i >= 1; i--)
    {
        suff[i] = (long long) suff[i + 1] * (x - i + MOD) % MOD;
    }
    int res = 0;
    for (int i = 1; i <= k; i++)
    {
        if (!((k - i) & 1))
        {
            res = (res + (long long) pref[i - 1] * suff[i + 1] % MOD * rfac[i - 1] % MOD * rfac[k - i] % MOD * a[i]) % MOD;
        }
        else
        {
            res = (res - (long long) pref[i - 1] * suff[i + 1] % MOD * rfac[i - 1] % MOD * rfac[k - i] % MOD * a[i] % MOD + MOD) % MOD;
        }
    }
    return res;
}

int main()
{
    build();
    int n,k;
    scanf("%d %d", &n , &k) ;
    for (int i = 1; i < MAXN ; i++) a[i] = (power(i,k) + a[i-1]) % MOD;

    printf("%d", interpolation(n , k + 2 ) ) ;

    return 0;
}
