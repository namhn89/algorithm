using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

int Tree[MAXN * 4] , lazy[MAXN * 4] ;
void push (int k , int l , int r ) {
   if (lazy[k] == 0) return ;
   lazy[2 * k] += lazy[k] ;
   lazy[2 * k + 1] += lazy[k] ;
   Tree[2 * k] +=  lazy[k] ;
   Tree[2 * k + 1] += lazy[k] ;
   lazy[k] = 0 ;
}
void update (int k , int l , int r , int ll , int rr , int v) {
    if (rr < l || r < ll) return ;
    if (ll <= l && r <= rr) {
        Tree[k] += v ;
        lazy[k] += v ;
        return ;
    }
    push(k , l , r)  ;
    int mid = (l + r) / 2 ;
    update(2 * k , l , mid , ll , rr , v) ;
    update(2 * k + 1 , mid + 1 , r , ll , rr , v) ;
    Tree[k] =  max(Tree[2 * k] , Tree[2 * k + 1]) ;
}
int query (int k , int l , int r , int ll , int rr ){
   if (r < ll || l > rr) return 0 ;
   if (ll <= l && r <= rr ) return Tree[k] ;
   push(k , l , r) ;
   int mid = (l + r) / 2 ;
   return max(query(2 * k , l , mid , ll , rr) , query(2 * k + 1 , mid + 1 , r , ll , rr)) ;
}
int n , m ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &m) ;
    for(int i = 1 ; i <= m ; ++i ) {
        int type ;
        scanf("%d",&type) ;
        if (type == 0) {
            int l , r , x ;
            scanf("%d %d %d", &l , &r , &x) ;
            update(1 , 1 , n , l , r , x) ;
        }
        else {
            int l , r ;
            scanf("%d %d" , &l , &r) ;
            printf("%d\n" , query(1 , 1 , n , l , r)) ;
        }
    }

    return 0;
}
