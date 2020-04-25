using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int MAXK = 6 ;
struct data
{
    int du, u, k ;
    data () {}
    data (int du , int u , int k ) : du(du), u(u), k(k) {} ;
    bool operator < (const data &other) const
    {
        if (du != other.du) return du < other.du ;
        else if (k != other.k ) return k < other.k ;
        else return u < other.u ;
    }
};
int n, m, k, S, T ;
const int oo = 1e9 + 100 ;
int d[MAXN][MAXK] ;
vector < pair <int,int> > g[MAXN] ;
void dijkstra ()
{
    memset(d , oo , sizeof(d)) ;
    d[S][0] = 0 ;
    priority_queue < data > Q ;
    Q.push(data (0 , S , 0)) ;
    while(!Q.empty())
    {
        int du = Q.top().du ;
        int u  = Q.top().u ;
        int k  = Q.top().k ;
        Q.pop() ;
        if (du != d[u][k]) continue ;
        if (u == T) continue ;
        TR(g[u] , it)
        {
            int v = it -> st ;
            int l = it -> nd ;
            if (d[v][k] > d[u][k] + l)
            {
                d[v][k] = d[u][k] + l ;
                Q.push(data(d[v][k] , v , k)) ;
            }
            if (k > 0) continue ;
            if (d[v][k + 1] > d[u][k] )
            {
                d[v][k + 1] = d[u][k] ;
                Q.push(data(d[v][k + 1] , v , k + 1)) ;
            }
        }
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d %d %d %d", &n, &m, &k, &S, &T) ;
    FORE(i, 1, m )
    {
        int u, v, l ;
        scanf("%d %d %d", &u , &v , &l ) ;
        g[u].push_back(make_pair(v , l)) ;
        g[v].push_back(make_pair(u , l)) ;
    }
    dijkstra() ;
    int ans = oo ;
    FORE(i , 0 , k ) ans = min(ans , d[T][i]) ;
    printf("%d\n",ans) ;
    return 0;
}
