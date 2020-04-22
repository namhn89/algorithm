using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
vector < pair <int , int>  > g[MAXN] ;
int n ;
long long dist[MAXN] ;
void DFS (int u , int parent ) {
   TR(g[u] , it) {
      int v = it -> st ;
      int w = it -> nd ;
      if (v == parent) continue ;
      dist[v] = dist[u] + w ;
      DFS(v , u) ;
   }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n ;
    for(int i = 1 ; i < n ; ++i ){
        int u , v , w ;
        cin >> u >> v >> w ;
        g[u].push_back(make_pair(v , w)) ;
        g[v].push_back(make_pair(u , w)) ;
    }
    dist[0] = 0 ;
    DFS(0 , -1) ;
    long long ans = 0 ;
    for(int i = 0 ; i < n ; ++i ) ans = max(ans , dist[i]) ;
    cout << ans << endl;
    return 0;
}
