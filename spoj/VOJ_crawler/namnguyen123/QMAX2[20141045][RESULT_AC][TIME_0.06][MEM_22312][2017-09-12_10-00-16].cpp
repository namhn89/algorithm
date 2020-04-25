using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const long long oo = 1e18 ;
int n , q ;
long long Tree[MAXN * 4] , lazy[MAXN * 4] ;
void push (int k) {
   if (lazy[k] == 0) return ;
   lazy[2 * k] += lazy[k] ;
   lazy[2 * k + 1] += lazy[k] ;
   Tree[2 * k] += lazy[k] ;
   Tree[2 * k + 1] += lazy[k] ;
   lazy[k] = 0 ;
}
void update (int k , int l , int r , int ll , int rr , long long v) {
    if (l > rr || ll > r) return ;
    if (ll <= l && r <= rr) {
        Tree[k] += v ;
        lazy[k] += v ;
        return ;
    }
    push(k) ;
    int mid = (l + r) / 2 ;
    update(2 * k , l , mid , ll , rr , v) ;
    update(2 * k + 1 , mid + 1 , r , ll , rr , v) ;
    Tree[k] = max(Tree[2 * k] , Tree[2 * k + 1]) ;
}
long long query (int k , int l , int r , int ll , int rr ) {
    if (l > rr || ll > r ) return -oo ;
    if (ll <= l && r <= rr) return Tree[k] ;
    push(k) ;
    int mid = (l + r) / 2 ;
    return max(query(2 * k , l , mid , ll , rr) , query(2 * k + 1 , mid + 1 , r , ll , rr)) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &q) ;
    while(q--){
        int type ;
        scanf("%d",&type) ;
        if (type == 0) {
            int l , r , x ;
            scanf("%d %d %d", &l , &r , &x) ;
            update(1 , 1 , n , l , r , x) ;
        }
        else {
                int l , r ;
                scanf("%d %d", &l , &r) ;
                printf("%lld\n", query(1 , 1 , n , l , r) );
        }
    }

    return 0;
}
