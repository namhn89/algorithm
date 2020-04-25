using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 5 ;
vector <int> g[MAXN] ;
int deg[MAXN], n, m, ok[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; ++i) deg[i] = 1 ;
    for(int i = 1 ; i <= m ; ++i)
    {
        int u, v ;
        cin >> u >> v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
        deg[u] ++ ; deg[v] ++ ;
    }
    for(int u = 1 ; u <= n ; ++u) g[u].push_back(u) ;
    int ans = 0 ;
    priority_queue < pair <int, int > > Q ;
    for(int i = 1 ; i <= n ; ++i ) Q.push(make_pair(deg[i] , i)) ;
    for(int u = 1 ; u <= n ; ++u ) ok[u] = 0 ;
    while(Q.size())
    {
        int du = Q.top().st ;
        int u = Q.top().nd ;
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
