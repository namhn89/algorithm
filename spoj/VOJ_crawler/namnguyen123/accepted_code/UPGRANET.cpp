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
const long long oo = 9e9 ;
int logN = 0 ;

vector < pair <int, long long > > g[MAXN] ;
vector < pair <long long, pair <int , int> > > Edeges, New ;

int n , m , par[MAXN] , level[MAXN] ;

long long dad[MAXLOG][MAXN] , Min[MAXLOG][MAXN] ;

int findSet(int p)
{
    if(par[p] == p) return p ;
    else return par[p] = findSet(par[p]) ;
}
void join (int u, int v)
{
    int x = findSet(u), y = findSet(v) ;
    par[y] = x ;
}
void DFS (int u , int parent )
{
    TR(g[u], it)
    {
        int v = it -> st ;
        int w = it -> nd ;
        if(v == parent) continue ;
        Min[0][v] = w ;
        dad[0][v] = u ;
        level[v] = level[u] + 1  ;
        DFS(v , u) ;
    }
}
void init ()
{
    for(int i = 1 ; i <= n ; ++i) par[i] = i ;
    for(logN = 0 ; (1LL << logN) <= n ; ++logN) ;
    for(int i = 0 ; i <= logN ; ++i)
        for(int j = 1 ; j <= n ; ++j) Min[i][j] = oo ;
}
void make_lca()
{
    for(int i = 1 ; i <= logN ; ++i )
    {
        for(int u = 1 ; u <= n ; ++u )
        {
            dad[i][u] = dad[i - 1][dad[i - 1][u]] ;
            if (dad[i][u]) Min[i][u] = min(Min[i - 1][dad[i - 1][u]] , Min[i - 1][u]) ;
        }
    }
}
long long LCA (int x , int y)
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
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n, &m ) ;
    init() ;
    for(int i = 1 ; i <= m ; ++i)
    {
        int u, v, w ;
        scanf("%d %d %d", &u, &v, &w) ;
        Edeges.push_back(make_pair(w, make_pair(u, v))) ;
    }
    sort(Edeges.begin() , Edeges.end()) ;
    reverse(Edeges.begin() , Edeges.end()) ;
    TR(Edeges, it)
    {
        int w = it -> st ;
        int u = (it -> nd).st ;
        int v = (it -> nd).nd ;
        if (findSet(u) != findSet(v))
        {
            join(u, v) ;
            g[u].push_back(make_pair(v , w)) ;
            g[v].push_back(make_pair(u , w)) ;
        }
        else New.push_back(make_pair(w , make_pair(u , v))) ;
    }
    DFS(1, 0 ) ;
    make_lca() ;
    long long ans = 0 ;
    TR(New, it)
    {
        int w = it -> st ;
        int u = (it -> nd).st ;
        int v = (it -> nd).nd ;
        long long res = LCA(u , v) ;
        ans += res - w ;
    }
    printf("%lld\n" , ans) ;
    return 0;
}
