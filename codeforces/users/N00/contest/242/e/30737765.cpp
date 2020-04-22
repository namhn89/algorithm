using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long Tree[4 * MAXN][30] , lazy[4 * MAXN][30] ;
void push (int k , int l , int r , int id)
{
    if (lazy[k][id] == 0) return ;
    lazy[2 * k][id] ^= 1 ;
    lazy[2 * k + 1][id] ^= 1 ;
    int mid = (l + r) / 2 ;
    Tree[2 * k][id] = (mid - l + 1) - Tree[2 * k][id] ;
    Tree[2 * k + 1][id] = (r - mid) - Tree[2 * k + 1][id] ;
    lazy[k][id] = 0 ;
}
void update (int k , int l , int r , int ll , int rr , int id) {
   if (ll > r || rr < l )  return ;
   if (ll <= l && r <= rr ) {
        Tree[k][id] = (r - l + 1) - Tree[k][id] ;
        lazy[k][id] ^= 1 ;
        return ;
   }
   push(k , l , r , id) ;
   int mid = (l + r) / 2 ;
   update(2 * k , l , mid , ll , rr , id) ;
   update(2 * k + 1 , mid + 1 , r , ll , rr , id) ;
   Tree[k][id] = Tree[2 * k][id] + Tree[2 * k + 1][id] ;
}
long long query (int k , int l , int r , int ll , int rr , int id) {
   if (ll > r || rr < l ) return 0 ;
   if (ll <= l && r <= rr) return Tree[k][id] ;
   push(k , l , r , id)  ;
   int mid = (l + r) / 2 ;
   return query(2 * k , l , mid , ll , rr , id) + query(2 * k + 1 , mid + 1 , r , ll , rr , id) ;
}
int n , q ;
int a[MAXN] ;
int main()
{
#define TASK "text"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d", &n) ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d", &a[i]) ;
    for(int u = 0 ; u <= 20 ; ++u ) {
        for(int i = 1 ; i <= n ; ++i ) if ( (a[i] >> u) & 1 ) update(1 , 1 , n , i , i , u) ;
    }
    scanf("%d", &q) ;
    while(q--){
        int type ;
        scanf("%d", &type) ;
        if (type == 1) {
            int l , r ;
            scanf("%d %d", &l , &r) ;
            long long ans = 0 ;
            for(int u = 0 ; u <= 20 ; ++u )  ans += (1LL << u) * query(1 , 1 , n , l , r , u) ;
            printf("%lld\n", ans) ;
        }
        else {
            int l , r , x ;
            scanf("%d %d %d", &l , &r , &x) ;
            for(int u = 0 ; u <= 20 ; ++u ) {
                if ( (x >> u) & 1 ) update(1 , 1 , n , l , r , u) ;
            }
        }
    }


    return 0;
}
