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
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
ll power(ll x, ll y, ll mod)
{
    if (!y) return 1 ;
    if (y == 1 ) return x % mod ;
    ll ans = power(x , y >> 1 , mod);
     ans = (ans % mod )* (ans % mod) % mod  ;
    if (y & 1) ans = ans * (x % mod) % mod ;
    return ans % mod ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll mod = 20122007 ;
    ll n ;
    ll ans = 1 ;
    cin >> n ;
    for(int i = 1 ; i <= sqrtl(n) ; ++i ){
        if (n % i == 0){
            ll k = n/i;
            ans *= (power( 3 , k , mod ) - 1);
            ans %= mod;
            ans *= (power( 3 , i , mod ) - 1);
            ans %= mod;
        }
    }
    cout << ans << endl;

    return 0;
}
