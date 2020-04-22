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
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n ;
    cin >> n ;
    if (n == 1 )
    {
        cout << -1 << endl;
        return 0 ;
    }
    for (ll i = 1 ; i <= sqrt(n) ; ++i)
    {
        if (n % i == 0)
        {
            ll x = n*n/i;
            if (x % 2 == 0 && i % 2 == 0 )
            {
                cout << (x-i)/2 << " " << (x+i)/2 << endl;
                return 0;
            }
            if (x % 2 == 1 && i % 2 == 1 )
            {
                cout << (x-i)/2 << " " << (x+i)/2 << endl;
                return 0 ;
            }
        }
    }
    cout << -1 << endl;
    return 0 ;

    return 0;
}
