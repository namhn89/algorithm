using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair < long long, int > LLI  ;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const long long INF = 1e18 + 100 ;
vector <pair <int, int> > g[MAXN] ;
long long d[MAXN] ;
long long f[MAXN] ;
int a[MAXN] ;
int n, m ;
void dijkstra()
{
    priority_queue < LLI, vector<LLI>, greater<LLI> > qu;
    FORE(i , 1 , n ) d[i] = INF;
    FORE(i , 1 , n ) f[i] = a[i] ;
    d[1] = 0 ;
    qu.push(LLI(0, 1));
    while (qu.size())
    {
        LLI top = qu.top();
        qu.pop();
        int u  = top.nd;
        long long du = top.st;
        if (du != d[u]) continue;
        if (u == n) break ;
        TR(g[u], it )
        {
            long long l = it -> nd ;
            int  v = it -> st ;
            if(d[v] == d[u] + l)
            {
                f[v] = max(f[v], f[u] + a[v]) ;
            }
            if (d[v] > d[u] + l)
            {
                d[v] = d[u] + l;
                f[v] = f[u] + a[v] ;
                qu.push(LLI(d[v] , v));
            }
        }
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d", &n ) ;
    FORE(i, 1, n ) scanf("%d",&a[i]) ;
    scanf("%d", &m ) ;
    FORE(i, 1, m )
    {
        int u, v, c ;
        scanf("%d %d %d", &u, &v, &c) ;
        g[u].push_back(make_pair(v , c)) ;
        g[v].push_back(make_pair(u , c)) ;
    }
    dijkstra() ;
    if (d[n] == INF) printf("impossible\n") ;
    else
    {
        printf("%lld %lld\n", d[n], f[n]) ;
    }
    return 0;
}
