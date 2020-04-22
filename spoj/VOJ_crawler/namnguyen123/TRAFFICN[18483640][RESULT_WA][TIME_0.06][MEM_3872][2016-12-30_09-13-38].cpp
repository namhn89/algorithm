using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair <int,int> II ;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e4 + 5 ;
const int oo = 2e9 + 100 ;
int n, m, k, s, t ;
vector < pair <int, int> > g[MAXN] , G[MAXN] ;
int d1[MAXN] , d0[MAXN] ;
void dijkstra_1 (int S)
{
    FORE(i , 1 , n) d1[i] = oo ;
    d1[S] = 0 ;
    priority_queue < II, vector<II>, greater <II> > Q ;
    Q.push(make_pair(0 , S)) ;
    while(!Q.empty())
    {
        int du = Q.top().st ;
        int u = Q.top().nd ;
        Q.pop() ;
        if (du != d1[u]) continue ;
        TR(g[u], it)
        {
            int v = it -> st ;
            int l = it -> nd ;
            if (d1[v] > d1[u] + l)
            {
                d1[v] = d1[u] + l ;
                Q.push(make_pair(d1[v], v)) ;
            }
        }
    }
}
void dijkstra_2(int S){
FORE(i , 1 , n) d0[i] = oo ;
    d0[S] = 0 ;
    priority_queue < II, vector<II>, greater <II> > Q ;
    Q.push(make_pair(0 , S)) ;
    while(!Q.empty())
    {
        int du = Q.top().st ;
        int u = Q.top().nd ;
        Q.pop() ;
        if (du != d0[u]) continue ;
        TR(G[u], it)
        {
            int v = it -> st ;
            int l = it -> nd ;
            if (d0[v] > d0[u] + l)
            {
                d0[v] = d0[u] + l ;
                Q.push(make_pair(d0[v], v)) ;
            }
        }
    }
}
void Init () {
  FORE(i , 1 , n ) g[i].clear() , G[i].clear() ;
}
int main()
{
#define TASK "TRAFFICN"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int Test ;
    scanf("%d", &Test) ;
    while(Test--)
    {
        scanf("%d %d %d %d %d", &n , &m , &k , &s , &t ) ;
        Init () ;
        FORE(i, 1, m )
        {
            int u, v, l ;
            scanf("%d %d %d", &u , &v , &l) ;
            g[u].push_back(make_pair(v , l)) ;
            G[v].push_back(make_pair(u , l)) ;
        }
        dijkstra_1(s) ;
        int ans = d1[t] ;
        dijkstra_2(t) ;
        FORE(i , 1 , k )
        {
            int u, v, w ;
            scanf("%d %d %d", &u , &v , &w) ;
            ans = min(ans , d1[u] + w + d0[v]) ;
            ans = min(ans , d1[v] + w + d0[u]) ;
        }
        if (ans == oo) printf("-1\n") ;
        else printf("%d\n",ans) ;
    }
    return 0;
}
