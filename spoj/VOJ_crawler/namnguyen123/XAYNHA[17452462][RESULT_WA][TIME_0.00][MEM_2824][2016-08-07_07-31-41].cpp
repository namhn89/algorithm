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
    int T ;
    cin >> T ;
    while(T--)
    {
        ld n ;
        cin >> n ;
        if (n == 0)
        {
            cout << "0 1 1 " << endl;
        }
        else
        {
            ld x = sqrt(sqrt(4*n));
            ll a = floor(x);
            ll b = ceil(x);
            ll c = a - 1 ;
            /*cout << x << endl;
            cout << a << endl;
            cout << b << endl;
            cout << c << endl;*/
            ll t = ((a+1)*a)*((a+1)*a)/4 ;
            ll d = ((b+1)*b)*((b+1)*b)/4;
            ll f = ((c+1)*c)*((c+1)*c)/4;
            ll m = n - t ;
            ll z = d - n ;
            ll k = n - f ;
           /* cout << m << endl;
            cout << z << endl;
            cout << k << endl;*/
            if (m == 0 )
            {
                cout << 1 << " " << a << endl;
            }
            else if (z == 0)
            {
                cout << 1 << " " << b << endl;
            }
            else
            {
                ll p = min(m,min(z,k));
                if (p == k) cout << 0 << " " << -p << " " << c << endl;
                if (p == m) cout << 0 << " " << -m << " " << a << endl;
                if (p == z) cout << 0 << " " << z << " " << b << endl;
            }
        }
    }
        return 0;
    }
