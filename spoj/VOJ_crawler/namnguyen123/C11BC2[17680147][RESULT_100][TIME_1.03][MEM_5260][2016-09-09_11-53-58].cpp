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
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
vector<int> g[MAXN];
int t[MAXN];
bool vis[MAXN];
int nscc = 0 ;
void DFS(int u )
{
    t[u] = nscc ;
    vis[u] = true ;
    TR(g[u],it)
    {
        if (vis[*it] == false )
        {
            DFS(*it);
        }
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m ;
    cin >> n >> m ;
    FORE(i, 2, n )
    {
        int u, k ;
        cin >> u >> k ;
        if (k == 1 )
        {
            g[i].push_back(u);
            g[u].push_back(i);
        }
    }
    FORE(i, 1, n )
    {
        if (vis[i] == false )
        {
            DFS(i);
            nscc++;
        }
    }
    while(m--)
    {
        int x, y ;
        cin >> x >> y ;
        if (t[x] != t[y] ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
