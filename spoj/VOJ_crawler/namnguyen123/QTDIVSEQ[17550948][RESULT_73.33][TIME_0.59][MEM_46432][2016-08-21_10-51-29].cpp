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
const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 1 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll f[MAXN];
ll s[MAXN];
ll fact[MAXN];
ll dp[MAXN];
ll z[MAXN];
int a[MAXN];
int n, k ;
ll pmod(int a, int b)
{
    ll r = 1;
    while (b)
    {
        if (b & 1) r = r * a % MOD;
        a =  a * a % MOD;
        b >>= 1;
    }
    return r;
}
ll nCk(int n, int k)
{
    return  fact[n] * pmod(fact[n - k] * fact[k] % MOD, MOD - 2) % MOD;
}

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    FORE(i, 1, n )
    {
        cin >> a[i] ;
        s[i] = s[i-1] + a[i] ;
    }
    ll ans = 0;
    if (s[n] % k == 0)
    {
        ll ss = s[n] / k;
        if (ss == 0)
        {
            int cnt = 0;
            FORE(i, 1, n)
            {
                cnt += s[i] == 0;
            }
            fact[0] = 1;
            for (int i = 1; i <= cnt - 1; ++i)
            {
                fact[i] = 1LL * fact[i - 1] * i % MOD;
            }
            ans = nCk(cnt - 1, k - 1);
        }
        else
        {
            dp[0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                if (s[i] % ss == 0)
                {
                    int id = s[i] / ss;
                    int v = dp[id - 1];
                    z[i] = v;
                    dp[id] = (dp[id] + v) % MOD;
                }
            }
            ans = z[n];
        }
    }
    cout << ans;
    return 0;
}
