using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
const int MAXN = 1e5 + 1 ;
int n , m ;
int vtime , nscc;
int low[MAXN] , num[MAXN] , id[MAXN] , vis[MAXN];
vector< int > g[MAXN] ;
stack < int > s;
int DFS(int u)
{
    int v;
    vis[u] = 1 ;
    low[u] = num[u] = ++vtime;
    s.push(u);
    TR(g[u],it)
    {
        v = *it ;
        if(id[v] != - 1 )continue;// bo qua cung cheo
        if(!vis[v])
        {
            low[u] = min(low[u] , DFS(v)); //cung xuoi
        }
        else
        {
            low[u] = min(low[u] , num[v]);// cung nguoc
        }
    }
    if (low[u] == num[u])
    {
       // cout << nscc + 1 << endl;
        while (1)
        {
            v = s.top();
            s.pop();
          //  cout << v << " ";
            id[v] = nscc ;
            if(v == u) break;
        }
        //cout << endl;
        nscc++;
    }
    return low[u];
}

main()
{
    scanf("%d %d",&n ,&m) ;
    memset(vis , 0 , sizeof (vis) );
    memset(id , -1 , sizeof (id) );
    vtime = 0 ;
    nscc = 0 ;
    for(int i = 0 ; i < m ; ++i)
    {
        int u , v;
        scanf("%d %d", &u , &v) ;
        g[u].push_back(v);
    }
    FORE(i , 1 , n ) if(!vis[i]) DFS(i);
    printf("%d\n", nscc) ;

}
