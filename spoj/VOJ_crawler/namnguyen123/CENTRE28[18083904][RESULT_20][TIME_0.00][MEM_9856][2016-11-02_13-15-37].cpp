using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;
typedef pair<ll,int> LLI;

inline void read (int &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;

int n, m ;
vector <LLI> g[MAXN] ;
long long d1[MAXN], dn[MAXN], d[MAXN], f1[MAXN], fn[MAXN], f[MAXN] ;
void dijkstra(int s)
{
    priority_queue <LLI>q;
    FORE(i, 1, n )
    {
        d[i] = INF;
    }
    f[s] = 1 ;
    q.push(make_pair(d[s] = 0, s));
    while(!q.empty())
    {
        int u = q.top().nd ;
        int du = -q.top().st;
        q.pop();
        if(d[u] < du )continue;
        if(du == INF)break;
        FOR(i, 0, g[u].size() )
        {
            int v = g[u][i].st ;
            int l = g[u][i].nd ;
            if(d[v] == du + l )
            {
                f[v] += f[u] ;
                q.push(make_pair(-d[v],v));
            }
            if (d[v] > du + l )
            {
                d[v] = du + l ;
                f[v] = f[u] ;
                q.push(make_pair(-d[v],v));
            }
        }
    }
}

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m ;
    while(m--)
    {
        int u, v, l ;
        cin >> u >> v >> l ;
        g[u].push_back(II(v,l));
        g[v].push_back(II(u,l));
    }
    dijkstra(1) ;
    FORE(i, 1, n ) d1[i] = d[i], f1[i] = f[i] ;
    dijkstra(n) ;
    FORE(i, 1, n ) dn[i] = d[i], fn[i] = f[i] ;
   // FORE(i, 1, n ) cout << 1 << "->" << i << " : " << d1[i] << " " << f1[i] << endl;
   // FORE(i, 1, n ) cout << n << "->" << i << " : " << dn[i] << " " << fn[i] << endl;
    vector <int> ans ;
    FORE(i, 2, n - 1 )
    {
        if (d1[i] + dn[i] > d1[n] || (d1[i] + dn[i] == d1[n] && f1[i] * fn[i] < f1[n] ) ) ans.push_back(i) ;
    }
    cout << ans.size() << endl;
    TR(ans,it) cout << *it << endl;

    return 0;
}
