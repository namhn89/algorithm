using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e4 + 5 ;
int par[MAXN] ;
int n, m;
vector <int> g[MAXN] , neg_g[MAXN] ;
int anc (int u)
{
    if (par[u] == u ) return u ;
    else return par[u] = anc(par[u]) ;
}
void join (int p, int q)
{
    par[anc(p)] = anc(q) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d", &n) ;
    FORE(i , 1 , n) par[i] = i ;
    scanf("%d", &m) ;
    while(m--)
    {
        int u , v ;
        char c ;
        cin >> c >> u >> v ;
        if (c == 'F')
        {
            g[u].push_back(v) ;
            g[v].push_back(u) ;
            join(u , v) ;
        }
        else
        {
            neg_g[u].push_back(v) ;
            neg_g[v].push_back(u) ;
        }
    }
    FORE(u , 1 , n )
    {
        for(int i = 0 ; i < g[u].size() ; ++i )
        {
            for(int j = 0 ; j < g[u].size() ; ++j )
            {
                int x = g[u][i] ;
                int y = g[u][j] ;
                if (anc(x) == anc(y)) continue ;
                join(x , y) ;
            }
        }
        for(int i = 0 ; i < neg_g[u].size() ; ++i )
        {
            for(int j = 0 ; j < neg_g[u].size() ; ++j )
            {
                int x = g[u][i] ;
                int y = g[u][j] ;
                if (anc(x) == anc(y)) continue ;
                join(x , y) ;
            }
        }
    }
    set <int> S ;
    FORE(i , 1 , n ) S.insert(anc(i)) ;
    cout << S.size() << endl;
    return 0;
}
