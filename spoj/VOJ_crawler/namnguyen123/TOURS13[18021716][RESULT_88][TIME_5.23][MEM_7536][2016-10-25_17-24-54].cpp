using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e3 + 1 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
vector < II > g[MAXN];
int d[MAXN] ;
int dist[MAXN][MAXN];
int n, m ;
void dijkstra(int s)
{
    priority_queue <II>q;
    FORE(i , 1 , n )
    {
        d[i] = INF;
    }
    q.push(make_pair(d[s] = 0, s));
    while(!q.empty())
    {
        int u = q.top().nd ;
        int du = -q.top().st;
        q.pop();
        if(d[u] < du )continue;
        if(du == INF)break;
        FOR(i , 0 , g[u].size() )
        {
            int v = g[u][i].st ;
            int l = g[u][i].nd ;
            if(d[v] > du + l )
            {
                d[v] = du + l ;
                q.push(make_pair(-d[v],v));
            }

        }
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Test ;
    scanf("%d",&Test);
    while(Test--){
    scanf("%d %d",&n,&m);
    FORE(i , 1 , n ) g[i].clear() ;
    while(m--)
    {
        int u, v, l ;
        scanf("%d %d %d",&u,&v,&l);
        g[u].push_back(make_pair(v,l));
    }
    FORE(i, 1, n )
    {
        dijkstra(i);
        FORE(j , 1 , n )
        {
            if (d[j] == INF ) dist[i][j] = -1 ;
            else
            {
                dist[i][j] = d[j];
            }
        }
    }
    FORE(i, 1, n )
    {
        int ans = INF ;
        FORE(j, 1, n )
        {
            if(dist[i][j] > 0 && dist[j][i] > 0 && i != j ) ans = min(ans , dist[i][j] + dist[j][i]);
        }
        if(ans == INF ) printf("-1\n");
        else printf("%d\n",ans);
    }
    }


    return 0;
}
