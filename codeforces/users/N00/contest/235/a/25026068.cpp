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
ll lcm1 (ll a, ll b)
{
    return a*b/__gcd(a,b);
}
ll lcm2 (ll a, ll b, ll c )
{
    return lcm1(c,lcm1(a,b));
}

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ll res = 0 ;
    ll n ;
    cin >> n ;
    FORE (i, 0, 10 )
    {
        FORE( j, 0, 10 )
        {
            FORE (k, 0, 10 )
            {
                res = max(lcm2( max(1ll,n - i) , max(1ll,n - j) , max(1ll,n - k)),res);
            }
        }
    }
    cout << res << endl;
    return 0;
}
