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
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll power(ll a,ll b)
{
    ll res = 1 ;
    FORE(i, 1, b) res*=a ;
    return res ;
}
bool check(ll n)
{
    FORE(i, 2, sqrtl(n))
    {
        if (n % i == 0)
        {
            return false ;
        }
    }
    return true ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n ;
    cin >> n ;
    FORE(i, 2, 64)
    {
        ll x = floor(exp(log(n)/i));
        ll y = ceil(exp(log(n)/i));
        if (check(x))
        {
            if (power(x,i) == n)
            {
                cout << x << " " << i << endl;
                return  0 ;
            }
        }
        if (check(y)){
            if (power(y,i) == n){
                cout << y << " " << i << endl;
                return 0 ;
            }
        }
    }
    cout << 0 << endl;

    return 0;
}
