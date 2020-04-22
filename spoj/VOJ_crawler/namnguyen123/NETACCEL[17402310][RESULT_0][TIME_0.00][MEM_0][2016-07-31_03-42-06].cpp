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
const int MAXN=1e5+5;
int a[MAXN];
bool f[MAXN];
bool visit[MAXN];
vector < int > g[MAXN] ;
void DFS (int u)
{
    visit[u] = true ;
    TR(g[u] ,it)
    {
        if ( visit[*it]==false && f[*it] == false) DFS(*it);
    }
}
int main()
{
    freopen("netrace.inp","r",stdin);
    freopen("netrace.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k ;
    memset(visit, false, sizeof visit);
    memset(f , false , sizeof f );
    FORE(i, 1, m )
    {
        int u, v ;
        cin >> u >> v ;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    FORE(i , 1 , k )
    {
        int t ;
        cin >> t ;
        f[t] = true ;
        TR( g[t] , it ) f[*it] = true ;
        g[t].clear();
    }
    int ans = 0 ;
    if (f[1] == false ) DFS(1);
    FORE(i , 1 , n ) if (visit[i] == false ) ans ++ ;
    cout <<  ans << endl;


    return 0;
}
