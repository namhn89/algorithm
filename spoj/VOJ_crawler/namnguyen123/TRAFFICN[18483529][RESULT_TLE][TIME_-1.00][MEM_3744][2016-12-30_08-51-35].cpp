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
vector <pair <int, int> > g[MAXN] ;
int d[MAXN] ;
int dijkstra (int S, int T)
{
    FORE(i, 1, n) d[i] = oo ;
    d[S] = 0 ;
    priority_queue < II, vector<II>, greater <II> > Q ;
    Q.push(make_pair(0, S)) ;
    while(!Q.empty())
    {
        int du = Q.top().st ;
        int u = Q.top().nd ;
        Q.pop() ;
        if (du != d[u]) continue ;
        if (u == T) break ;
        TR(g[u], it)
        {
            int v = it -> st ;
            int l = it -> nd ;
            if (d[v] > d[u] + l)
            {
                d[v] = d[u] + l ;
                Q.push(make_pair(d[v], v)) ;
            }
        }
    }
    return d[T] ;
}
void Init () {
  FORE(i , 1 , n ) g[i].clear() ;
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
        }
        int ans = dijkstra(s, t) ;
        FORE(i, 1, k )
        {
            int u, v, w ;
            scanf("%d %d %d", &u, &v, &w) ;
            g[u].push_back(make_pair(v , w)) ;
            g[v].push_back(make_pair(u , w)) ;
            ans = min(ans , dijkstra(s , t)) ;
            g[u].pop_back() ;
            g[v].pop_back() ;
        }
        printf("%d\n",ans) ;
    }
    return 0;
}
