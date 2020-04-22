using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair <int,int> II ;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 5 ;
const int INF = 1e9 + 100 ;
vector < pair <int, int> > g[MAXN] ;
int d[MAXN] ;
int dist[MAXN][MAXN] ;
int trace[MAXN][MAXN] ;
int n , m  , k ;
void dijkstra (int S)
{
    for(int i = 1 ; i <= n ; ++i ) d[i] = INF ;
    d[S] = 0 ;
    priority_queue < II, vector <II>, greater <II> > Q ;
    Q.push(make_pair(0 , S)) ;
    while(!Q.empty())
    {
        int u = Q.top().nd;
        int du = Q.top().st ;
        Q.pop() ;
        if (du != d[u]) continue ;
        TR(g[u], it)
        {
            int v = it -> st ;
            int l = it -> nd ;
            if (d[v] > d[u] + l )
            {
                d[v] = d[u] + l ;
                trace[S][v] = u ;
                Q.push(make_pair(d[v], v)) ;
            }
        }
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d %d", &n, &m, &k) ;
    FORE(i, 1, m )
    {
        int u, v, c ;
        scanf("%d %d %d", &u, &v, &c) ;
        g[u].push_back(make_pair(v, c)) ;
        g[v].push_back(make_pair(u, c)) ;
    }
    FORE(i , 1 , n )
    {
        dijkstra (i) ;
        FORE(j , 1 , n) dist[i][j] = d[j] ;
    }
    FORE(i , 1 , k )
    {
        int type , u , v ;
        scanf("%d",&type) ;
        if (type == 0) {
            scanf("%d %d",&u ,&v) ;
            printf("%d\n", dist[u][v]) ;
        }
        else {
            scanf("%d %d", &u ,&v) ;
            vector <int> path ;
            for(int i = v ; i != 0 ; i = trace[u][i] ) path.push_back(i) ;
            reverse(path.begin() , path.end()) ;
            printf("%d ", path.size()) ;
            TR(path , it) printf("%d " ,*it) ; printf("\n") ;
        }
    }
    return 0;
}
