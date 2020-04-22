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
const int MOD=1e9+7;
const int MAXN=1e5+1;
int a[MAXN];
int n,m;
int vtime,nscc;
int low[MAXN],num[MAXN],id[MAXN],vis[MAXN];
vector< vector<int> > g;
stack<int> s;
int DFS(int u)
{
    int v;
    vis[u] = 1 ;
    low[u] = num[u] = ++vtime;
    s.push(u);
    TR(g[u],it)
    {
        v =*it;
        if(id[v]!=-1)continue;// bo qua cung cheo
        if(!vis[v])
        {
            low[u]=min(low[u],DFS(v)); //cung xuoi
        }
        else
        {
            low[u] =min(low[u],num[v]);// cung nguoc
        }
    }
    if (low[u]==num[u])
    {
      //  cout << endl << nscc + 1 << endl;
        while (1)
        {
            v = s.top();
            s.pop();
          //  cout << v+1 << " ";
            id[v] = nscc ;
            if(v==u) break;
        }
        nscc++;
    }
    return low[u];

}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n >> m;
    g.resize(n);
    memset(vis,0,sizeof vis);
    memset(id,-1,sizeof(id));
    vtime=0;
    nscc=0;
    for(int i=0; i<m; ++i)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
    }

    FOR(i, 0, n)if(!vis[i]) DFS(i);
    cout << nscc  << endl;

}
