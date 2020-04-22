using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int dad[MAXN], low[MAXN], num[MAXN], tick = 0, bridges = 0, cnt, c1 = 0, nChild[MAXN] ;
int n, m ;
int vis[MAXN] ;
vector <int> g[MAXN] ;
void DFS (int u, int parent)
{
    dad[u] = parent;
    low[u] = num[u] = ++tick ;
    TR (g[u], it)
    {
        if (*it == parent) continue;
        if (num[*it] != 0)
        {
            low[u] = min( low[u], num[*it]);
            continue;
        }
        DFS (*it, u);
        low[u] = min(low[u], low[*it]);
        if (low[*it] > num[u]) bridges++;
    }
}
void DFS2 (int u)
{
    if (cnt == 0 ) c1++;
    vis[u] = 1 ;
    TR(g[u], it)
    {
        if (vis[*it] == 0 ) DFS2(*it) ;
        nChild[u] += nChild[*it] ;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m ;
    FORE(i, 1, m )
    {
        int u, v ;
        cin >> u >> v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    cnt = 0 ;
    memset(num, 0, sizeof (num)) ;
    memset(vis, 0, sizeof (vis)) ;
    memset(nChild, 1, sizeof(nChild)) ;
    FORE(i, 1, n ) if(num[i] == 0 ) DFS(i, 0);
    FORE(i, 1, n ) if(vis[i] == 0 )
    {
        cnt++;
        DFS2(i);
    }
    if (cnt > 2)
    {
        printf("0\n") ;
        return 0 ;
    }
    long long ans = 0 ;
    if (cnt == 2 )
    {
        ans = 1ll * (m - bridges) * c1 * (n - c1) ;
    }
    if (cnt == 1 )
    {
        ans = 1ll * (m - bridges) *  (1ll * (n) * (n - 1) / 2 - m ) ;
        FORE(i, 2, n ) if (num[i] == low[i])
        {
            ans += (n - nChild[i]) * nChild[i] - 1 ;
        }
    }
    cout << ans << endl;


    return 0;
}
