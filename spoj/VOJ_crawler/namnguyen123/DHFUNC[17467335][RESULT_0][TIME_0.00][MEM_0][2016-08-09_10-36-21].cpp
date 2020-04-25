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
const int MAXN = 505 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll fib[MAXN];
ll f[MAXN][MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k ;
    cin >> k ;
    while(k--)
    {
        memset(f, 0,sizeof f);
        FORE(i, 0, 500 ) f[i][0] = i;
        FORE(i, 0, 500 ) f[0][i] = i;
        int x, y ;
        ll a, b, MOD ;
        cin >> x >> y >> a >> b >> MOD ;
        fib[1] = 1;
        fib[2] = 1;
        FORE(i, 3, 500 )
        {
            fib[i] = (fib[i-1] % MOD + fib[i-2] % MOD)% MOD ;
        }
        FORE(i, 1, x)
        {
            FORE(j, 1, y)
            {
                f[i][j] = (f[i-1][y] % MOD )*(a%MOD) + (f[i][j-1]%MOD)*(b%MOD) + fib[__gcd(x,y)]%MOD ;
            }
        }
        cout << f[x][y] << endl;
    }
    return 0;
}
