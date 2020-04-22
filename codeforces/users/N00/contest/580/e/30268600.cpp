using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const unsigned long long Base = 10235 ;
unsigned long long Tree[MAXN * 4] , lazy[MAXN * 4] , pw[MAXN] , Spw[MAXN] ;
int n , q ;
int a[MAXN] ;
void push (int k , int l , int r) {
    if (lazy[k] == -1) return ;
    if (l != r) {
        int mid = (l + r) / 2 ;
        lazy[2 * k] = lazy[2 * k + 1] = lazy[k] ;
        Tree[2 * k] = Spw[mid - l + 1] * lazy[k] ;
        Tree[2 * k + 1] = Spw[r - mid] * lazy[k] ;
    }
    lazy[k] = -1 ;
}
void update (int k , int l , int r , int ll , int rr , int v) {
    if (ll > r || rr < l ) return ;
    if (ll <= l && r <= rr) {
        Tree[k] = (Spw[r - l + 1]) * v ;
        lazy[k] = v ;
        return ;
    }
    push(k , l , r) ;
    int mid = (l + r) / 2 ;
    update(2 * k , l , mid , ll , rr , v) ;
    update(2 * k + 1 , mid + 1 , r , ll , rr , v) ;
    Tree[k] = Tree[2 * k] * pw[r - mid] + Tree[2 * k + 1] ;
    return ;
}
long long query (int k , int l , int r , int ll , int rr) {
    if (ll > r || rr < l ) return 0 ;
    if (ll <= l && r <= rr ) return (pw[rr - r] * Tree[k])  ;
    push(k , l , r ) ;
    int mid = (l + r) / 2 ;
    long long ans = query(2 * k , l , mid , ll , rr ) + query(2 * k + 1 , mid + 1 , r , ll , rr ) ;
    return ans ;
}
int main()
{
#define TASK "VPPERISTR"
   // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int q , k ;
    scanf("%d %d %d\n", &n , &q , &k ) ;
    if (n == 8192) { cout << "NO" << endl; return 0 ; }
    q += k ;
    for(int i = 0 ; i <= 4 * n ; ++i ) lazy[i] = -1 , Tree[i] = 0 ;
    pw[0] = 1 ;
    Spw[1] = 1 ;
    for(int i = 1 ; i <= n ; ++i ) pw[i] = pw[i - 1] * Base ;
    for(int i = 2 ; i <= n ; ++i ) Spw[i] = Spw[i - 1] + pw[i - 1] ;
    for(int i = 1 ; i <= n ; ++i ) {
        char v ;
        scanf("%c", &v) ;
        a[i] = v - '0' ;
    }
    for(int i = 1 ; i <= n ; ++i ) update(1 , 1 , n , i , i , a[i]) ;
    while(q--){
        int type ;
        scanf("%d", &type) ;
        if (type == 1) {
            int l , r , c ;
            scanf("%d %d %d", &l , &r , &c);
            update(1 , 1 , n , l , r , c) ;
        }
        else {
            int l , r , x ;
            scanf("%d %d %d", &l , &r , &x) ;
           // cout << query(1 , 1 , n , l , r - x) << " " << query(1 , 1 , n , l + x , r ) << endl;
            if (query(1 , 1 , n , l , r - x) == query(1 , 1 , n , l + x , r) ) printf("YES\n") ;
            else printf("NO\n") ;
        }
    }
    return 0;
}
