using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long w[MAXN] ;
vector < pair < long long , pair <int , int> > > Edege ;
int par[MAXN] , n , m ;
int findSet (int p) {
   if (par[p] == p) return p ;
   else return par[p] = findSet(par[p]) ;
}
void join (int u , int v) {
  int x = par[u] , y = par[v] ;
  par[y] = x ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &m) ;
    for(int i = 1 ; i <= n ; ++i ) par[i] = i ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d", &w[i]) ;
    for(int i = 1 ; i <= m ; ++i ) {
         int u , v , c ;
         scanf("%d %d %d", &u , &v , &c) ;
         Edege.push_back(make_pair(1LL * w[u] + 1LL * w[v] + 2LL * c , make_pair(u , v))) ;
    }
    sort(Edege.begin() , Edege.end() ) ;
    long long ans = *min_element(w + 1 , w + n + 1) ;
    TR(Edege , it) {
       long long c = it -> st ;
       int u = (it -> nd).st ;
       int v = (it -> nd).nd ;
       if (findSet(u) == findSet(v)) continue ;
       join(u , v) ;
       ans += c ;
    }
    cout << ans << endl;

    return 0;
}
