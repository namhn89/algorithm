using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef long long ll ;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int low[MAXN], num[MAXN], tick = 0, bridges , cnt, c1, nChild[MAXN] ;
int n , m ;
int vis[MAXN] ;
vector <int> g[MAXN] ;
void DFS (int u , int parent)
{
    if(cnt == 1) c1 ++;
    low[u] = num[u] = ++tick ;
    nChild[u] = 1;
    TR (g[u] , it)
    {
        if (*it == parent) continue;
        if (num[*it] != 0)
        {
            low[u] = min( low[u] , num[*it]); continue ;
        }
        DFS (*it , u);
        nChild[u] += nChild[*it] ;
        low[u] = min(low[u] , low[*it]);
        if (low[*it] > num[u]) bridges++;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d",&n ,&m ) ;
    FORE(i, 1, m )
    {
        int u, v ;
        scanf("%d %d", &u , &v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    cnt = 0 ;
    bridges = 0 ;
    c1 = 0 ;
    memset(num , 0 , sizeof (num) ) ;
    memset(vis , 0 , sizeof (vis) ) ;
    FORE(i , 1 , n ) if( num[i] == 0 ) { cnt++ ; DFS(i , 0);}
    if (cnt > 2)
    {
        printf("0\n") ; return 0 ;
    }
    long long ans = 0 ;
    if (cnt == 2 ) ans = 1ll * (m - bridges) * c1 * (n - c1) ;
    else
    {
        ans = 1ll * (m - bridges) *  (1ll * n * (n - 1) / 2 - m ) ;
        FORE(i , 2 , n ) if (num[i] == low[i]) ans += 1ll * ( n - nChild[i] ) * nChild[i] - 1 ;
    }
    printf("%lld\n", ans) ;
    return 0;
}
