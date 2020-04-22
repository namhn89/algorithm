using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
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
const int MAXN = 5e3 + 10 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
vector <int> topo;
int N, M, T;
int deg[MAXN];
int dp[MAXN][MAXN];
int trace[MAXN][MAXN];
int id_topo[MAXN];
int vex_has_topo[MAXN];
int vis[MAXN];
vector < pair <int, int> > g[MAXN], g_rev[MAXN];
int scan (int &a)
{
    bool minus = false;
    int res = 0;
    char c;
    c = getchar();
    while (true)
    {
        if (c == '-') break;
        if (c >= '0' && c <= '9') break;
        c = getchar();
    }
    if (c == '-') minus = true;
    else res = c - '0';
    while (true)
    {
        c = getchar();
        if (c < '0' || c > '9') break;
        res = res*10 + (c - '0');
    }
    if (minus) a = -res;
    else a = res;
}
void get_topo (int u)
{
    for (auto e : g[u])
    {
        int v = e.first;
        if (!vis[v])
        {
            vis[v] = 1;
            get_topo(v);
        }
    }
    topo.push_back(u);
}
int minimize (int &a, int b)
{
    if (a > b) a = b;
    else return false;
    return true;
}

void TR (int u, int n_vex)
{
    if (n_vex == 0) return;
    TR (trace[u][n_vex], n_vex - 1);
    cout << u << " ";
}

int main()
{
    scan(N);
    scan(M);
    scan(T);
    for (int i = 1; i <= M; i++)
    {
        int u, v, t;
        scan(u);
        scan(v);
        scan(t);
        g[u].push_back({v, t});
        g_rev[v].push_back({u, t});
        deg[v]++;
    }
    for (int i = 1; i <= N; i++) if (deg[i] == 0)
        {
            vis[i] = 1;
            get_topo(i);
        }
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < topo.size(); i++)
    {
        id_topo[topo[i]] = i + 1;
        vex_has_topo[i + 1] = topo[i];
    }
    for (int i = 0; i <= N; i++)
    {
        for (int n_vex = 0; n_vex <= N; n_vex++)
        {
            dp[i][n_vex] = INF ;
        }
    }
    dp[id_topo[1]][1] = 0;
    for (int i = id_topo[1]; i <= N; i++)
    {
        for (int n_vex = 1 ; n_vex <= N; n_vex++)
        {
            for (auto e : g_rev[vex_has_topo[i]])
            {
                int l = e.second;
                int v = e.first;
                if ((long)dp[id_topo[v]][n_vex - 1] + (long)l > T) continue;
                if(minimize(dp[i][n_vex], dp[id_topo[v]][n_vex - 1] + l))
                {
                    trace[vex_has_topo[i]][n_vex] = v;
                }
            }
        }
    }
    int res = 0;
    for (int n_vex = 0; n_vex <= N; n_vex++)
    {
        if (dp[id_topo[N]][n_vex] <= T)
        {
            res = max (res, n_vex);
        }
    }
    cout << res << endl;
    TR(N, res);
}
