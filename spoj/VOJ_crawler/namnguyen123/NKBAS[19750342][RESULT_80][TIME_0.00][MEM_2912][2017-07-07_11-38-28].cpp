using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e3 + 5 ;
set <int> g[MAXN] ;
int deg[MAXN] , n , m , ok[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m ;
    for(int i = 1 ; i <= m ; ++i)
    {
        int u, v ;
        cin >> u >> v ;
        g[u].insert(v) ;
        g[v].insert(u) ;
    }
    for(int u = 1 ; u <= n ; ++u) g[u].insert(u) ;
    for(int u = 1 ; u <= n ; ++u) deg[u] = g[u].size() ;
    int ans = 0 ;
    priority_queue < pair <int , int > > Q ;
    for(int u = 1 ; u <= n ; ++u ) Q.push( make_pair(deg[u] , u) ) ;
    for(int u = 1 ; u <= n ; ++u ) ok[u] = 0 ;
    while(Q.size())
    {
        int du = Q.top().st , u = Q.top().nd ;
        Q.pop() ;
        if (du == 0) break ;
        if (du != deg[u]) continue ;
        ans++ , ok[u] = 1 ;
        TR(g[u] , it) ok[*it] = 1 ;
        for(int v = 1 ; v <= n ; ++v )
        {
            deg[v] = 0 ;
            TR(g[v] , it) if(ok[*it] == 0) deg[v]++ ;
            Q.push(make_pair(deg[v] , v)) ;
        }
    }
    cout << ans << endl ;
    return 0;
}
