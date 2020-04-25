using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int MAXLOG = 20 ;
int dad[MAXLOG][MAXN], n, m, ntest, level[MAXN] ;
vector <int> g[MAXN] ;
int logN = 0 ;
void DFS (int u , int parent )
{
    dad[0][u] = parent ;
    TR(g[u] , it)
    {
        int  v = *it ;
        if (v == parent) continue ;
        level[v] = level[u] + 1 ;
        DFS(v , u) ;
    }
}
void make_lca ()
{
    for(int i = 1 ; i <= logN ; ++i )
        for(int u = 1 ; u <= n ; ++u ) dad[i][u] = dad[i - 1][dad[i - 1][u]] ;
}
int LCA (int x, int y)
{
    if (level[y] > level[x]) swap(x, y) ;
    int delta = level[x] - level[y] ;
    for(int i = logN ; i >= 0 ; --i ) if ( (delta >> i) & 1 ) x = dad[i][x] ;
    if (x == y) return x ;
    for(int i = logN ; i >= 0 ; --i )
    {
        if (dad[i][x] != dad[i][y])
        {
            x = dad[i][x] ;
            y = dad[i][y] ;
        }
    }
    return dad[0][x] ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d", &ntest) ;
    for(int itest = 1 ; itest <= ntest ; ++itest)
    {
        printf("Case %d:\n", itest) ;
        scanf("%d", &n) ;
        for(logN = 0 ; (1 << logN) <= n ; ++logN) ;
        for(int u = 1 ; u <= n ; ++u)
        {
            int sz ;
            scanf("%d", &sz) ;
            for(int i = 1 ; i <= sz ; ++i)
            {
                int v ;
                scanf("%d",&v) ;
                g[u].push_back(v) ;
            }
        }
        DFS(1 , 0) ;
        make_lca() ;
        int q ;
        scanf("%d", &q);
        while(q--)
        {
            int u, v ;
            scanf("%d %d", &u, &v) ;
            printf("%d\n", LCA(u , v)) ;
        }
    }
    return 0;
}
