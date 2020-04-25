using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair < pair <int, int>, int> III ;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
vector <int> g[MAXN] ;
III Edge [MAXN] ;
int nChild[MAXN] ;
bool vis[MAXN] ;
void DFS (int u)
{
    vis[u] = 1 ;
    TR(g[u], it)
    if (vis[*it] == 0)
    {
        DFS(*it) ;
        nChild[u] += nChild[*it] ;

    }
}
int main()
{
#define TASK "NTTREE"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    FOR(i , 0 , n - 1 )
    {
        int u, v, w ;
        scanf("%d %d %d",&u, &v, &w) ;
        Edge[i].st.st = u ;
        Edge[i].st.nd = v ;
        Edge[i].nd = w ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    FOR(i , 0 , n ) nChild[i] = 1 ;
    DFS(0) ;
    long long ans = 0 ;
    FOR(i , 0 , n - 1){
       int u = Edge[i].st.st ;
       int v = Edge[i].st.nd ;
       int w = Edge[i].nd ;
       ans += 1ll * w * (n - min(nChild[u] , nChild[v])) * min(nChild[u] , nChild[v]) ;
    }
    printf("%lld\n",ans);



    return 0;
}
