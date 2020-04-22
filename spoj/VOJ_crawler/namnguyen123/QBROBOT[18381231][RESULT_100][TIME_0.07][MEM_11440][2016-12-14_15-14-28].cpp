using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
const int oo = 1e9 + 10 ;
struct data
{
    int v, c, d ;
    // d time
    // c chi phi
    data () {};
    data (int v, int c, int d) : v(v), c(c), d(d) {}
};
int f[MAXN] ;
int dist[MAXN] ;
int trace[MAXN] ;
vector < data > g[MAXN], G[MAXN] ;
map < pair <int,int>, int> F ;
int n, m, k ;
void Dijkstra (int S)
{
    FORE(i, 1, n) dist[i] = oo ;
    dist[S] = 0 ;
    priority_queue < pair <int,int>, vector < pair<int,int> >, greater < pair <int,int> > >  Q ;
    Q.push(make_pair(0, S)) ;
    while(!Q.empty())
    {
        int du = Q.top().st ;
        int u = Q.top().nd ;
        Q.pop();
        if (du != dist[u]) continue ;
        TR(g[u], it)
        {
            int v = (*it).v ;
            int d = (*it).d ;// time
            if (dist[v] > du + d)
            {
                dist[v] = du + d ;
                Q.push(make_pair(dist[v], v) ) ;
            }
        }
    }
}
bool check (int limit, int S, int T)
{
    FORE(i, 1, n) dist[i] = -1 ;
    dist[S] = limit ;
    priority_queue < pair<int,int> > Q ;
    Q.push(make_pair(limit, S)) ;
    while(!Q.empty())
    {
        int du = Q.top().st ;
        int u = Q.top().nd ;
        Q.pop() ;
        if (du != dist[u]) continue ;
        if (f[u]) du = limit ;
        TR(G[u], it)
        {
            int v = (*it).v ;
            int t = du - (*it).c ;
            if (t >= 0 )
            {
                if(dist[v] < t || dist[v] == -1)
                {
                    dist[v] = t ;
                    Q.push(make_pair(dist[v], v)) ;
                }
            }
        }
    }
    if (dist[T] == -1) return false ;
    return true ;
}
void DFS(int limit, int S, int T)
{
    FORE(i, 1, n) dist[i] = -1 ;
    dist[S] = limit ;
    priority_queue < pair<int,int> > Q ;
    Q.push(make_pair(limit, S)) ;
    while(!Q.empty())
    {
        int du = Q.top().st ;
        int u = Q.top().nd ;
        Q.pop() ;
        if (du != dist[u]) continue ;
        if (f[u]) du = limit ;
        TR(G[u], it)
        {
            int v = (*it).v ;
            int t = du - (*it).c ;
            if (t >= 0 )
            {
                if(dist[v] < t || dist[v] == -1)
                {
                    dist[v] = t ;
                    trace[v] = u ;
                    Q.push(make_pair(dist[v], v)) ;
                }
            }
        }
    }
}
int main()
{
#define TASK "ETOUR"
     //freopen(TASK".inp","r",stdin);
     //freopen(TASK".out","w",stdout);
    //scanf("%d %d %d" , &n, &m, &k) ;
    scanf("%d",&n) ;
    FORE(i, 1, n)
    {
        int x ;
        scanf("%d", &f[i]) ;
        //f[x] = 1 ;
    }
    scanf("%d" , &m) ;
    FORE(i, 1, m )
    {
        int u, v, c, d ;
        scanf("%d %d %d %d", &u , &v, &c, &d) ;
        swap(c , d) ;
        F[make_pair(u, v)] = i ;
        F[make_pair(v, u)] = i ;
        g[u].push_back(data(v, c, d)) ;
        g[v].push_back(data(u, c, d)) ;
    }
    Dijkstra(1) ;
    int res = dist[n] ;
    FORE(i, 1, n)
    {
        TR(g[i], it)
        {
            int v = (*it).v ;
            int c = (*it).c ;
            int d = (*it).d ;
            if (dist[i] + d == dist[v]) G[i].push_back( data(v, c, d) ) ;
        }
    }
    int L = 1, R = oo, ans = -1 ;
    while(L <= R)
    {
        int mid = (L + R) / 2 ;
        if (check(mid, 1, n) )
        {
            ans = mid ;
            R = mid - 1 ;
        }
        else
        {
            L = mid + 1 ;
        }
    }
    cout << ans << endl;
    /*
    printf("%d %d\n", res, ans) ;
    if (ans != -1)
    {
        DFS(ans, 1, n) ;
        vector <int> path ;
        for(int i = n ; i != 0 ; i = trace[i] ) path.push_back(i) ;
        reverse(path.begin(), path.end());
        for(int i = 0 ; i < path.size() - 1 ; ++i ) printf("%d ", F[make_pair(path[i], path[i + 1])]) ;
    }
    */
    return 0;
}
