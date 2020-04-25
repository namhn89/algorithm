using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int MAXLOG = 21 ;
const long long oo = 1e18 ;
int logN = 0 ;
vector < pair <int , long long > > g[MAXN] ;
int n , m , q ;
long long Max[MAXLOG][MAXN] , Min[MAXLOG][MAXN] , dad[MAXLOG][MAXN] , level[MAXN] ;

void DFS (int u , int parent )
{
    TR(g[u], it)
    {
        int v = it -> st ;
        int w = it -> nd ;
        if(v == parent) continue ;
        Max[0][v] = w ;
        Min[0][v] = w ;
        dad[0][v] = u ;
        level[v] = level[u] + 1  ;
        DFS(v , u) ;
    }
}
void init ()
{
    for(logN = 0 ; (1LL << logN) <= n ; ++logN) ;
    for(int i = 0 ; i <= logN ; ++i)
        for(int j = 1 ; j <= n ; ++j) Max[i][j] = oo , Max[i][j] = -oo ;
}
void make_lca()
{
    for(int i = 1 ; i <= logN ; ++i )
    {
        for(int u = 1 ; u <= n ; ++u )
        {
            dad[i][u] = dad[i - 1][dad[i - 1][u]] ;
            if (dad[i][u]) Min[i][u] = min(Min[i - 1][dad[i - 1][u]] , Min[i - 1][u]) ;
            if (dad[i][u]) Max[i][u] = max(Max[i - 1][dad[i - 1][u]] , Max[i - 1][u]) ;
        }
    }
}
long long LCA_max (int x , int y)
{
    long long res = -oo ;
    if (level[y] > level[x] ) swap(x , y) ;
    int delta = level[x] - level[y] ;
    for(int i = logN ; i >= 0 ; --i )
    {
        if ( (delta >> i) & 1 )
        {
            res = max(res , Max[i][x]) ;
            x = dad[i][x] ;
        }
    }
    if (x == y) return res ;
    for(int i = logN ; i >= 0 ; --i)
    {
        if (dad[i][x] != dad[i][y])
        {
            res = max(res , Max[i][x]) ;
            res = max(res , Max[i][y]) ;
            x = dad[i][x] ;
            y = dad[i][y] ;
        }
    }
    res = max(res , Max[0][x]) ;
    res = max(res , Max[0][y]) ;
    return res ;
}
long long LCA_min (int x , int y)
{
    long long res = oo ;
    if (level[y] > level[x] ) swap(x , y) ;
    int delta = level[x] - level[y] ;
    for(int i = logN ; i >= 0 ; --i )
    {
        if ( (delta >> i) & 1 )
        {
            res = min(res , Min[i][x]) ;
            x = dad[i][x] ;
        }
    }
    if (x == y) return res ;
    for(int i = logN ; i >= 0 ; --i)
    {
        if (dad[i][x] != dad[i][y])
        {
            res = min(res , Min[i][x]) ;
            res = min(res , Min[i][y]) ;
            x = dad[i][x] ;
            y = dad[i][y] ;
        }
    }
    res = min(res , Min[0][x]) ;
    res = min(res , Min[0][y]) ;
    return res ;
}


int main()
{
#define TASK "test"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d" ,&n) ;
    init() ;
    for(int i = 1 ; i < n ; ++i){
        int u , v , w ;
        scanf("%d %d %d", &u , &v , &w) ;
        g[u].push_back(make_pair(v , w)) ;
        g[v].push_back(make_pair(u , w)) ;
    }
    DFS(1 , 0) ;
    make_lca() ;
    scanf("%d",&q) ;
    while(q--){
        int u , v ;
        scanf("%d %d",&u ,&v) ;
        cout << LCA_min(u , v) << " " << LCA_max(u , v) << endl;
    }





    return 0;
}
