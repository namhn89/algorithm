using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
int dad[MAXN][30] , Max[MAXN][30] ;
int par[MAXN] , level[MAXN] ;
int n , q ;
int logN ;
vector < pair <int , int> > adj[MAXN] ;
int findSet (int u) {
   if (par[u] == u) return par[u] ;
   return par[u] = findSet(par[u]) ;
}
void join (int u , int v) {
    par[findSet(u)] = par[findSet(v)] ;
}
void DFS (int u , int parent) {
    TR(adj[u] , it) {
       int v = it -> st ;
       int w = it -> nd ;
       if (v == parent) continue ;
       level[v] = level[u] + 1 ;
       dad[v][0] = u ;
       Max[v][0] = w ;
       DFS(v , u) ;
    }
}
void makeLCA () {
   for(int i = 1 ; i <= logN ; ++i )
       for(int u = 1 ; u <= n ; ++u  ) {
          dad[u][i] = dad[dad[u][i - 1]][i - 1] ;
          Max[u][i] = max(Max[u][i - 1] , Max[dad[u][i - 1]][i - 1]) ;
   }
}
int LCA (int u , int v) {
   int res = 0 ;
   if (level[v] > level[u]) swap(u , v) ;
   int delta = level[u] - level[v] ;
   for(int i = logN ; i >= 0 ; --i ) {
       if ( (delta >> i) & 1 ) {
            res = max(res , Max[u][i] ) ;
            u = dad[u][i] ;
       }
   }
   if (u == v) return res ;
   for(int i = logN ; i >= 0 ; --i ) {
        if (dad[u][i] != dad[v][i]) {
            res = max(res , Max[u][i]) ;
            res = max(res , Max[v][i]) ;
            u = dad[u][i] ;
            v = dad[v][i] ;
        }
   }
   res = max(res , Max[u][0]) ;
   res = max(res , Max[v][0]) ;
   return res ;
}
vector < pair <int , pair <int , int> > > Edeges ;
int u[MAXN] , v[MAXN] , w[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &q) ;
    for(int i = 1 ; i <= n ;++i) par[i] = i ;
    for(logN = 0 ; (1 << logN) <= n ; ++logN) ;
    for(int i = 0 ; i < q ; ++i ) {
        scanf("%d %d %d", &u[i] , &v[i] , &w[i]) ;
        Edeges.push_back(make_pair(w[i] , make_pair(u[i] , v[i]))) ;
    }
    sort(Edeges.begin() , Edeges.end()) ;
    long long ans = 0 ;
    TR(Edeges , it) {
         int w = (*it).st ;
         int u = (*it).nd.st ;
         int v = (*it).nd.nd ;
         if (findSet(u) == findSet(v)) continue ;
         join(u , v) ;
         ans += w ;
         adj[u].push_back(make_pair(v , w)) ;
         adj[v].push_back(make_pair(u , w)) ;
    }
    DFS(1 , 0) ;
    makeLCA() ;
    for(int i = 0 ; i < q ; ++i ) {
        int need = LCA(u[i] , v[i])  ;
        cout << ans - need + w[i] << endl;
    }
    return 0;
}
