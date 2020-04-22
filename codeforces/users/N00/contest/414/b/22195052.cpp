using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
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

inline void read (int &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e9 + 7 ;
const int MAXN = 2e3 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
vector <int> f[MAXN] ;
long long dp[MAXN][MAXN] ;
int n , k ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k ;
    long long ans = 0 ;
    for(int i = 1 ; i <= n ; ++i ) dp[1][i] = 1 ;
    for(int i = 1 ; i <= n ; ++i )
    {
        for(int j = i ; j <= n ; j += i ) f[j].push_back(i) ;
    }
    for(int i = 2 ; i <= k ; ++i )
    {
        for (int j = 1 ; j <= n ; ++j )
        {
            for(int k = 0 ; k < f[j].size() ; ++k )
            {
                dp[i][j] = dp[i][j] + dp[i - 1][f[j][k]] ;
                dp[i][j] %= MOD ;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++ i) ans = (ans + dp[k][i]) % MOD ;
    cout << ans << endl;

    return 0;
}
