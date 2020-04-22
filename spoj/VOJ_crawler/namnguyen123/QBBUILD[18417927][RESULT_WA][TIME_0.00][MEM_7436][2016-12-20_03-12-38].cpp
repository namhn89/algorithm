using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair<int , int> II ;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e3 + 5 ;
const int oo = 1e9 + 10 ;
int d[MAXN] ;
int dist[MAXN][MAXN] ;
int n , m , k ;
int S , T ;
int a , b , c , z ;
vector <II> g[MAXN] ;
void dijkstra (int S)
{
    FORE(i, 1, n) d[i] = oo ;
    d[S] = 0 ;
    priority_queue < II, vector <II>, greater <II> > Q ;
    Q.push(make_pair(0, S)) ;
    while(!Q.empty())
    {
        int du = Q.top().st ;
        int u = Q.top().nd ;
        Q.pop() ;
        if (du > d[u]) continue ;
        TR(g[u], it)
        {
            int v = it -> st ;
            int l = it -> nd ;
            if (d[v] > du + l)
            {
                d[v] = du + l  ;
                Q.push(make_pair(d[v], v)) ;
            }
        }
    }
}
int main()
{
#define TASK "QBBUILD"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d", &n) ;
    scanf("%d %d %d %d", &a, &b, &c, &z) ;
    int u, v, l ;
    while(~scanf("%d %d %d", &u, &v, &l ) )
    {
        g[u].push_back(make_pair(v, l)) ;
        g[v].push_back(make_pair(u, l)) ;
    }
    FORE(i, 1, n )
    {
        dijkstra(i) ;
        FORE(j, 1, n ) dist[i][j] = d[j] ;
    }
    int ans = oo ;
    FORE(i, 1, n )
    {
        FORE(j, 1, n )
        {
            ans = min(ans, dist[i][a] + dist[i][b] + dist[i][j] + dist[j][c] + dist[j][z]) ;
        }
    }
    printf("%d\n", ans) ;
    return 0;
}
