using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
 
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
vector < int > g[MAXN] ;
int vis[MAXN] , n ;
int edge (int w )
{
    while(w)
    {
        if (w % 10 != 4 && w % 10 != 7) return 0 ;
        w /= 10 ;
    }
    return 1 ;
}
int DFS (int u )
{
    vis[u] = 1 ;
    int res = 1 ;
    TR(g[u] , it)
    {
        int v = *it ;
        if (!vis[v]) res += DFS(v) ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    memset(vis , 0 , sizeof(vis) ) ;
    scanf("%d",&n) ;
    for(int i = 1 ; i < n ; ++i )
    {
        int u, v, w ;
        scanf("%d %d %d", &u , &v , &w ) ;
        if(edge(w)) continue ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    long long ans = 0 ;
    for(int i = 1 ; i <= n ; ++i ) {
        if (!vis[i]) {
            long long n_node = DFS(i) ;
            ans += n_node * (n - n_node - 1) * (n - n_node) ;
        }
    }
    printf("%lld\n",ans) ;
    return 0;
}