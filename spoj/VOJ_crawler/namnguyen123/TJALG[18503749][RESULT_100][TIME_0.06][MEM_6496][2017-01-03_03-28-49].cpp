#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1 ;
int m, n, vtime, nscc ;
int low[MAXN], num[MAXN], vis[MAXN], id[MAXN] ;
vector <int> g[MAXN] ;
stack <int> S ;
int DFS (int u)
{
    low[u] = num[u] = vtime ++ ;
    vis[u] = 1 ;
    S.push(u) ;
    for(int i = 0 ; i < g[u].size() ; ++i )
    {
        int v = g[u][i] ;
        if (id[v] != -1 ) continue ;
        if (!vis[v])
        {
            low[u] = min(low[u], DFS(v)) ;
        }
        else
        {
            low[u] = min(low[u], num[v]) ;
        }
    }
    if (low[u] == num[u])
    {
        nscc ++ ;
       // printf("%d :", nscc) ;
        while(1)
        {
            int v = S.top() ;
            S.pop() ;
            //printf("%d ",v) ;
            id[v] = nscc ;
            if(v == u ) break ;
        }
        //printf("\n");
    }
    return low[u] ;
}
int main()
{
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    scanf("%d %d", &n , &m) ;
    memset(id , -1 , sizeof (id)) ;
    memset(vis , 0 ,sizeof (vis)) ;
    for(int i = 1 ; i <= m ; ++i )
    {
        int u, v ;
        scanf("%d %d", &u , &v) ;
        g[u].push_back(v) ;
    }
    for(int i = 1 ; i <= n ; ++i ) if(!vis[i]) DFS(i) ;
    printf("%d\n",nscc) ;
}
