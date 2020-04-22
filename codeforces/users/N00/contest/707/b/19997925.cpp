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
const int MAXN = 1e5 + 10 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
vector <LL> g[MAXN];
ll d[MAXN];
ll a[MAXN];
ll vis[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k ;
    FORE(i, 1, m )
    {
        ll u, v, l ;
        cin >> u >> v >> l ;
        g[u].push_back(LL(v,l));
        g[v].push_back(LL(u,l));
    }
    FORE(i , 1 , n ) d[i] = LNF ;
    FORE(i , 1 , k )
    {
        cin >> a[i];
        vis[a[i]] = 1;
        d[a[i]] = 0;
    }
    FORE(i, 1, k)
    {
        TR(g[a[i]],it)
        {
            d[it->first] = min( d[it->first] , d[a[i]] + it->second);
        }
    }
    //FOR(i, 1, n) cout << d[i] <<  " "; cout << endl;
    LL ans;
    ans.st = LNF;
    FORE(i, 1, n)
    {
        if(vis[i]) continue;
        ans = min(ans, LL(d[i], i));
    }
    if(ans.st == LNF) return cout << -1, 0;
    cout << ans.st;


    return 0;
}
