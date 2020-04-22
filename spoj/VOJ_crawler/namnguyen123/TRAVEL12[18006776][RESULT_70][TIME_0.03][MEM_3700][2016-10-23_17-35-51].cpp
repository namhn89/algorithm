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
vector< vector<int> > g ;
bool vis[MAXN] ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ;
    cin >> n >> m ;
    g.resize(n+1) ;
    while (m--)
    {
        int u, v ;
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1 ; i <= n ; ++i )
    {
        TR(g[i],it)
        {
            TR(g[*it],it1)
            {
                if(*it1 != i)
                {
                    TR(g[*it1],it2)
                    {
                        if(*it2 != i && *it2 != *it )
                        {
                            TR(g[*it2],it3)
                            {
                                if(*it3 == i)
                                {
                                    printf("%d %d %d %d \n",i,*it,*it1,*it2);
                                    return 0 ;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("-1");
    return 0;
}
