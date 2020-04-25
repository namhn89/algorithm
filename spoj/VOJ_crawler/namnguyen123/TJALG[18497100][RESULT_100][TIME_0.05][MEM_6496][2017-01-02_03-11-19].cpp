using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
vector <int> g[MAXN] ;
int low[MAXN], num[MAXN], vis[MAXN], id[MAXN], nscc = 0, vtime = 0 ;
int n , m ;
stack <int> S ;
int DFS (int u)
{
    low[u] = num[u] = ++vtime ;
    vis[u] = 1 ;
    S.push(u) ;
    TR(g[u] , it)
    {
        int v = *it ;
        if (id[v] != -1) continue ; // Cung  cheo
        if (!vis[v])
        {
            low[u] = min(low[u] , DFS(v))  ; // Cung xuoi
        }
        else
        {
            low[u] = min(low[u] , num[v]) ; // Cung nguoc
        }
    }
    if (low[u] == num[u])
    {
        nscc++;
        //printf("%d :", nscc) ;
        while(1)
        {
            int v = S.top() ;
            S.pop() ;
           // printf("%d ", v) ;
            id[v] = nscc ;
            if (v == u) break ;
        }
        //printf("\n") ;
    }
    return low[u] ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    nscc = 0 ;
    vtime = 0 ;
    memset(id , -1 , sizeof (id) ) ;
    memset(vis , 0 , sizeof (vis) ) ;
    scanf("%d %d", &n , &m) ;
    FORE(i , 1 , m ) {
       int u , v ;
       scanf("%d %d", &u , &v) ;
       g[u].push_back(v) ;
    }
    FORE(i , 1 , n) if (!vis[i]) DFS(i) ;
    printf("%d\n", nscc) ;

    return 0;
}
