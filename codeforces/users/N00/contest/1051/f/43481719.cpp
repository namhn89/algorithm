using namespace std;
#include<bits/stdc++.h>

typedef pair < long long , int> LI ;
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int MAXM = 43 ;
const int MAXLOG = 20 ;
vector <pair <int , int> > g[MAXN] , h[MAXN] ;
int dad[MAXLOG][MAXN] , level[MAXN] ;
int logN ;
long long dist[MAXN] ;
int m , n ;
long long d[MAXM][MAXN] ;
vector <int> news ;
struct data {
   int u , v , w ;
   bool is_tree ;
} E[MAXN] ;

int par[MAXN] ;
const long long oo = 1e18 ;

int findSet (int p) {
    if (par[p] == p) return par[p] ;
    else return par[p] = findSet(par[p]) ;
}
int Union (int u , int v) {
   int x = findSet(u) , y = findSet(v) ;
   if (x == y) return 0 ;
   else {
     par[x] = y ;
     return 1 ;
   }
}

void DFS (int u , int parent )
{
    dad[0][u] = parent ;
    TR(h[u] , it) {
        int v = it -> first ;
        if (v == parent) continue ;
        level[v] = level[u] + 1 ;
        dist[v] = dist[u] + it -> second ;
        DFS(v , u) ;
    }
}
void make_lca () {
    for(int i = 1 ; i <= logN ; ++i )
        for(int u = 1 ; u <= n ; ++u ) dad[i][u] = dad[i - 1][dad[i - 1][u]] ;
}
int LCA (int x, int y)
{
    if (level[y] > level[x]) swap(x, y) ;
    int delta = level[x] - level[y] ;
    for(int i = logN ; i >= 0 ; --i ) if ( (delta >> i) & 1 ) x = dad[i][x] ;
    if (x == y) return x ;
    for(int i = logN ; i >= 0 ; --i )
    {
        if (dad[i][x] != dad[i][y])
        {
            x = dad[i][x] ;
            y = dad[i][y] ;
        }
    }
    return dad[0][x] ;
}

void dijkstra (int idx) {
  int S = news[idx] ;
  for (int i = 1 ; i <= n ; ++i ) d[idx][i] = oo ;
  d[idx][S] = 0 ;
  priority_queue < LI , vector <LI>, greater <LI> > Q ;
  Q.push(make_pair(0, S)) ;
  while(!Q.empty()) {
      long long du = Q.top().first ;
      int u = Q.top().second ;
      Q.pop() ;
      if (d[idx][u] != du) continue ;
      TR(g[u] , it) {
         int v = it -> st ;
         int w = it -> nd ;
         if (d[idx][v] > du + w) {
             d[idx][v] = du + w ;
             Q.push(make_pair(d[idx][v] , v)) ;
         }
      }
  }
}

int main()
{
#define TASK "test"
     //freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &m) ;
    for (int i = 1 ; i <= n ; ++i ) par[i] = i ;
    for(logN = 0 ; (1 << logN) <= n ; ++logN) ;
    memset(dad , 0 , sizeof(dad)) ;
    memset(level , 0 , sizeof(level) ) ;
    for (int i = 1 ; i <= m ; ++i ) {
        int u , v , w ;
        scanf("%d %d %d", &u , &v , &w)  ;
        g[u].push_back(make_pair(v , w)) ;
        g[v].push_back(make_pair(u , w)) ;
        E[i].u = u , E[i].v = v , E[i].w = w ;
    }
    for (int i = 1 ; i <= m ; ++i ) {
        if (Union(E[i].u , E[i].v)) {
            int u = E[i].u , v = E[i].v , w = E[i].w ;
            h[u].push_back(make_pair(v , w)) ;
            h[v].push_back(make_pair(u , w)) ;
            E[i].is_tree = true ;
        }
        else {
            news.push_back(E[i].u) ;
            news.push_back(E[i].v) ;
            E[i].is_tree = false ;
        }
    }
    DFS(1 , 0) ;
    make_lca() ;
    sort(news.begin(), news.end());
	news.resize(unique(news.begin() , news.end()) - news.begin());
    for (int i = 0 ; i < news.size() ; ++i) {
        dijkstra(i) ;
    }
    int q ;
    scanf("%d", &q) ;
    while(q--){
        int u , v ;
        scanf("%d %d", &u , &v) ;
        long long ans = dist[u] + dist[v] - 2 * dist[LCA(u , v)] ;
        for (int i = 0 ; i < news.size() ; ++i) {
            ans = min(ans , d[i][u] + d[i][v]) ;
        }
        printf("%lld\n" , ans) ;
    }

    return 0;
}
