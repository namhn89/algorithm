using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
vector < pair <int , int> > g[MAXN] ;
int dad[MAXN][20] , Min[MAXN][20] , Max[MAXN][20] , level[MAXN] ;
const int oo = 1e9 ;
int logN , n , Q ;
void DFS (int u , int parent ) {
    TR(g[u] , it) {
       int v = it -> st ;
       int w = it -> nd ;
       if (v == parent) continue ;
       level[v] = level[u] + 1 ;
       dad[v][0] = u ;
       Min[v][0] = Max[v][0] = w ;
       DFS(v , u) ;
    }
}
void make_lca () {
    for(int u = 1 ; u <= logN ; ++u )
        for(int i = 1 ; i <= n ; ++i ) dad[i][u] = dad[dad[i][u - 1]][u - 1] ;
    for(int u = 1 ; u <= logN ; ++u )
        for(int i = 1 ; i <= n ; ++i ) Min[i][u] = min(Min[i][u - 1] , Min[dad[i][u - 1]][u - 1]) ;
    for(int u = 1 ; u <= logN ; ++u )
        for(int i = 1 ; i <= n ; ++i ) Max[i][u] = max(Max[i][u - 1] , Max[dad[i][u - 1]][u - 1]) ;
}
pair <int , int> query (int u , int v) {
    int res_Min = oo , res_Max = 0 ;
    if (level[v] > level[u]) swap(u , v) ;
    int delta = level[u] - level[v] ;
    for(int i = logN ; i >= 0 ; --i ) if ((delta >> i) & 1) {
        res_Min = min(res_Min , Min[u][i]) ;
        res_Max = max(res_Max , Max[u][i]) ;
        u = dad[u][i] ;
    }
    if (u == v) return make_pair(res_Min , res_Max) ;
    for(int i = logN ; i >= 0 ; --i ) {
        if (dad[u][i] != dad[v][i]) {
             res_Min = min(res_Min , Min[u][i]) ;
             res_Min = min(res_Min , Min[v][i]) ;
             res_Max = max(res_Max , Max[u][i]) ;
             res_Max = max(res_Max , Max[v][i]) ;
             u = dad[u][i] ;
             v = dad[v][i] ;
        }
    }
    res_Min = min(res_Min , Min[u][0]) ;
    res_Min = min(res_Min , Min[v][0]) ;
    res_Max = max(res_Max , Max[u][0]) ;
    res_Max = max(res_Max , Max[v][0]) ;
    return make_pair(res_Min , res_Max) ;
}

int main()
{
#define TASK "text"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%d", &n);
    for(logN = 0 ; (1 << logN) <= n ; ++logN) ;
    for(int i = 0 ; i < n - 1 ; ++i ) {
        int u , v , w ;
        scanf("%d %d %d", &u , &v , &w) ;
        g[u].push_back(make_pair(v , w)) ;
        g[v].push_back(make_pair(u , w)) ;
     }
     for(int i = 0 ; i <= logN ; ++i )
          for(int j = 0 ; j <= n ; ++j ) Min[j][i] = oo , Max[j][i] = 0 ;
     DFS(1 , 0) ;
     make_lca() ;
     scanf("%d", &Q) ;
     while(Q--){
        int u , v ;
        scanf("%d %d", &u , &v ) ;
        pair <int , int> ans = query(u , v) ;
        printf("%d %d\n", ans.st , ans.nd) ;
     }

    return 0;
}
