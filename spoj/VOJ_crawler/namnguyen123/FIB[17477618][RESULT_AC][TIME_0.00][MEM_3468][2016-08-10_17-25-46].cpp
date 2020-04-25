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
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
map<ll,ll>f ;
ll fib(ll n,ll MOD)
{
    if (f.count(n)) return f[n];
    else
    {
        ll k = n/2;
        if (n % 2 == 0) return f[n] = (fib(k,MOD)*fib(k,MOD)%MOD + fib(k-1,MOD)*fib(k-1,MOD)%MOD)%MOD;
        else return f[n] = (fib(k,MOD)*fib(k+1,MOD)%MOD + fib(k,MOD)*fib(k-1,MOD)%MOD)%MOD;
    }
}
int main()
{
    // freopen("in.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T ;
    cin >> T ;
    while(T--)
    {
        ll x, MOD ;
        cin >> x >> MOD ;
        if (x == 0 ) cout << 0 << endl;
        f.clear();
        f[0] = 1 ;
        f[1] = 1 ;
       cout << fib(x-1,MOD)%MOD << endl;
    }

    return 0;
}
