using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int Low[MAXN], Num[MAXN], vtime = 0, n, m , Mark[MAXN] ;
vector <int> g[MAXN] ;
vector < pair <int , int> > bridges ;
vector <int> cuts ;
void DFS (int u , int parent )
{
    Low[u] = Num[u] = ++vtime ;
    int nChild = 0 ;
    TR(g[u] , it )
    {
        if (*it == parent) continue  ;
        if (Num[*it] != 0)
        {
            Low[u] = min(Low[u] , Num[*it]) ;
            continue ;
        }
        DFS(*it , u) ;
        nChild++;
        Low[u] = min(Low[u] , Low[*it]) ;
        if (Low[*it] > Num[u]) bridges.push_back(make_pair(u , *it));
        if (u == parent) {
           if (nChild >= 2) Mark[u] = 1 ;
        }
        else if (Low[*it] >= Num[u]) Mark[u] = 1 ;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d",&n, &m) ;
    FORE(i, 1, m )
    {
        int u, v ;
        scanf("%d %d",&u, &v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    FORE(i , 1 , n ) if (!Num[i]) DFS(i , i) ;
    FORE(i , 1 , n ) if (Mark[i]) cuts.push_back(i) ;
    printf("%d %d\n", cuts.size() , bridges.size()) ;
    return 0;
}
