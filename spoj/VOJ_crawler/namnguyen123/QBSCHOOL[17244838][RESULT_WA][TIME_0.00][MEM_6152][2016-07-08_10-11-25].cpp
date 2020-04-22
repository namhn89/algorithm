using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef pair<ll,int> LLI;
const int MOD =123456789;
const int MAXN=1e5+5;
const ll INF = 1e15 ;
ll d[MAXN];
ll f[MAXN];
ll ans ;
int n,m;
vector< LLI > g[MAXN];
void dijkstra()
{
    priority_queue < LLI, vector<LLI>, greater<LLI> > qu;
    FORE(i, 1, n ) d[i] = INF;
    d[1] = 0;
    f[1] = 1 ;
    qu.push(LLI(0, 1));
    while (qu.size())
    {
        LLI top = qu.top();
        qu.pop();
        int u  = top.nd;
        ll du = top.st;
        if (du != d[u]) continue;
        if (u == n) break ;
        TR(g[u], it )
        {
            ll du1 = it->first;
            int  v = it->second;
            if (d[v] == d[u] + du1 )
            {
                f[v] += (f[u] );
            }
            if (d[v] > d[u] + du1)
            {
                d[v] = d[u] + du1;
                f[v] = (f[u]);
                qu.push(LLI(d[v], v));
            }
        }
        ans = d[n] ;
    }

}
int main()
{
  //  freopen("T1TRAFFI.inp","r",stdin);
    // freopen(".out","w",stdout);
    cin >> n >> m ;
    FORE(i, 1, n ) g[i].clear();
    FORE(i, 1, m )
    {
        int u,v,l;
        cin >> u >> v >> l ;
        g[u].push_back(make_pair(l,v));
        g[v].push_back(make_pair(l,u));
    }
    FORE(i, 1, n ) g[i].push_back(LLI());
    dijkstra();
    cout << ans  << endl;
    cout << f[n] << endl;




    return 0;
}
