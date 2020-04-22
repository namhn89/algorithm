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
const int MOD = 1e9 ;
const int MAXN = 1e2 + 10 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll f[MAXN][MAXN] ;
int a[MAXN][MAXN] ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ;
    cin >> m >> n ;
    FORE(i, 1, m )
    {
        FORE(j, 1, n )
        {
            cin >> a[i][j];
        }
    }
    FORE(i , 1 , m ) f[i][1] = 1 ;
    FORE(x1, 1 , m )
    {
        FORE(y1, 1, n )
        {
            FORE(x2, 1, x1 )
            {
                FORE(y2, 1, y1 )
                {
                    if(x1 + y1 > x2 + y2 && __gcd(a[x1][y1],a[x2][y2]) > 1 && y2 < n )
                    {
                        f[x1][y1] += (f[x2][y2]%MOD);
                        f[x1][y1] %= MOD ;
                    }
                }
            }
        }
    }
    ll ans = 0 ;
    FORE(i , 1 , m ) {ans += (f[i][n] % MOD); ans %= MOD ; }
    cout << ans << endl;


    return 0;
}
