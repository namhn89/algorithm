using namespace std;
#include<bits/stdc++.h>
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

const ll MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
ll n, m ;
ll mul (ll n, ll m )
{
    return ( (n % MOD ) * (m % MOD) ) % MOD ;
}
ll calc(ll st, ll ed, ll i )
{
    ll result = (ed - st  ) % MOD * ( (i % MOD) * (st + ed + 1) % MOD ) % MOD;
    if (result % 2 == 0 ) return result / 2;
    else return (result + MOD ) / 2;
}
ll solve(ll n, ll m )
{
    ll res = mul(n,m) ;
    ll min_value = min(n , m) ;
    for(ll i = 1 ; i * i <= n ; ++i )
    {
        ll  st = n / (i + 1) ;
        ll  ed = min(m , n / i );
        if (st < ed)
        {
            min_value = st ;
            res = res - calc(st , ed , i ) ;
            res %= MOD ;
        }
    }
    for(ll i = 1 ; i <= min_value ; ++i )
    {
        res = res - mul(n/i , i ) ;
        res %= MOD ;
    }
    res = ( res % MOD + MOD ) % MOD ;
    return res ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    printf("%lld",solve(n,m));

    return 0;
}
