using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 7e4 + 5 ;
const int MAXLOG = 21 ;
int dad[MAXLOG][MAXN], level[MAXN], logN, N, Q , a[MAXN] ;
vector <int> g[MAXN] ;
int Tree[MAXN * 4] ;
void DFS (int u, int parent )
{
    dad[0][u] = parent ;
    TR(g[u], it)
    {
        int v = *it ;
        if (v == parent ) continue  ;
        level[v] = level[u] + 1;
        DFS(v, u) ;
    }
}
void make_lca()
{
    for(int i = 1 ; i <= logN ; ++i )
    {
        for(int u = 1 ; u <= N ; ++u ) dad[i][u] = dad[i - 1][dad[i - 1][u]] ;
    }
}
int LCA(int x, int y)
{
    if (x == 0 || y == 0) return max(x, y) ;
    if (level[x] < level[y]) swap(x, y) ;
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
void build (int node , int l , int r )
{
    if (l == r) Tree[node] = a[l] ;
    else
    {
        int mid = (l + r) / 2 ;
        build (node * 2, l, mid) ;
        build (node * 2 + 1, mid + 1, r ) ;
        Tree[node] = LCA(Tree[node * 2], Tree[node * 2  + 1]) ;
    }
}
int Query (int node, int l, int r, int u, int v)
{
    if (v < l || u > r) return 0 ;
    if (u <= l && r <= v) return Tree[node] ;
    int mid = (l + r) / 2 ;
    return LCA ( Query(node * 2, l, mid, u, v), Query(node * 2 + 1, mid + 1, r, u, v )) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d",&N, &Q) ;
    for(logN = 0 ; ( 1 << logN ) <= N ; logN ++) ;
    FORE(i, 1, N - 1)
    {
        int u, v ;
        scanf("%d %d",&u,&v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    DFS(1 , 0) ;
    make_lca() ;
    FORE(i , 1 , N) a[i] = i ;
    build(1 , 1 , N) ;
    while(Q--)
    {
        int u, v ;
        scanf("%d %d",&u, &v) ;
        printf("%d\n", Query(1 , 1 , N, u, v)) ;
    }
    return 0;
}
