using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e3 + 5 ;
int n , a[MAXN][MAXN] ;
vector < pair < int , int> > Edge[MAXN] ;
int conver (int i , int j) {
  return (i - 1) * n + j ;
}
int par[MAXN * MAXN] , cnt[MAXN * MAXN] ;
int findSet (int p ) {
  if (par[p] == p) return par[p] ;
  else return par[p] = findSet(par[p]) ;
}
void Union (int u , int v) {
   int x = findSet(u) , y = findSet(v) ;
   if (x == y) return ;
   par[y] = x ;
   cnt[x] += cnt[y] ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int Max = 0 ;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= n ; ++j) cin >> a[i][j] , Max = max(Max , a[i][j]) ;
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= n ; ++j) {
            if (i < n) Edge[abs(a[i][j] - a[i + 1][j])].push_back(make_pair(conver(i , j) , conver(i + 1 , j)) ) ;
            if (j < n) Edge[abs(a[i][j] - a[i][j + 1])].push_back(make_pair(conver(i , j) , conver(i , j + 1)) ) ;
        }
    }
    for(int i = 1 ; i <= n * n ; ++i ) par[i] = i , cnt[i] = 1 ;
    int ans = 0 ;
    for(int u = 0 ; u <= Max ; ++u ) {
        TR(Edge[u] , it) {
            int x = it -> st , y = it -> nd ;
            cnt[x] = 1 , cnt[y] = 1 ;
            par[x] = x ; par[y] = y ;
        }
        TR(Edge[u] , it) {
            int x = it -> st , y = it -> nd ;
            Union(x , y) ;
        }
        TR(Edge[u] , it) {
           int x = it -> st , y = it -> nd ;
           ans = max(ans , cnt[x]) ;
           ans = max(ans , cnt[y]) ;
        }
    }
    cout << ans << endl;
    return 0;
}
