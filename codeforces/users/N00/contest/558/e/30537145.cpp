using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 1 ;
char a[MAXN] , ans[MAXN] ;
int n , q ;
int Tree[MAXN * 4][27] , lazy[MAXN * 4][27] ;

void build (int k , int l , int r , int id ) {
    if (l > r) return ;
    if (l == r) {
        if ((int)(a[l] - 'a') == id) Tree[k][id] = 1 ;
        else Tree[k][id] = 0 ;
        return ;
    }
    int mid = (l + r) / 2 ;
    build(2 * k , l , mid , id) ;
    build(2 * k + 1 , mid + 1 , r , id) ;
    Tree[k][id] = Tree[2 * k][id] + Tree[2 * k + 1][id] ;
}

void push (int k , int l , int r , int id) {
    if (lazy[k][id] == -1) return ;
    int mid = (l + r) / 2 ;
    Tree[2 * k][id] = (mid - l + 1 ) * lazy[k][id] ;
    Tree[2 * k + 1][id] = (r - mid ) * lazy[k][id] ;
    lazy[2 * k][id] = lazy[2 * k + 1][id] = lazy[k][id] ;
    lazy[k][id] = -1 ;
}
void update (int k , int l , int r , int ll , int rr , int v , int id) {
    if (ll > r || l > rr) return ;
    if (ll <= l && r <= rr) {
        Tree[k][id] = (r - l + 1) * v ;
        lazy[k][id] = v  ;
        return ;
    }
    push(k , l , r , id) ;
    int mid = (l + r) / 2 ;
    update(2 * k , l , mid , ll , rr , v , id) ;
    update(2 * k + 1 , mid + 1 , r  , ll , rr , v , id)  ;
    Tree[k][id] = Tree[2 * k][id] + Tree[2 * k + 1][id] ;
}
int query (int k , int l , int r , int ll , int rr , int id ){
    if (ll > r || l > rr) return 0  ;
    if (ll <= l && r <= rr) return Tree[k][id] ;
    push(k , l , r , id) ;
    int mid = (l + r) / 2 ;
    return query(2 * k , l , mid , ll , rr , id) + query(2 * k + 1 , mid + 1 , r , ll , rr , id) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &q ) ;
    scanf("%s", a + 1) ;
    for(int id = 0 ; id < 26 ; ++id )
        for(int i = 0 ; i < 4 * n ; ++i ) Tree[i][id] = 0 , lazy[i][id] = -1 ;
    for(int id = 0 ; id < 26 ; ++id ) build(1 , 1 , n , id) ;
    while(q--){
        int l  , r , type ;
        scanf("%d %d %d" , &l , &r , &type ) ;
        int pos = l ;
        if(type == 1) {
            for(int id = 0 ; id < 26 ; ++id ) {
                int cnt = query(1 , 1 , n , l , r , id) ;
                update(1 , 1 , n , l , r , 0 , id) ;
                if (cnt == 0) continue ;
                update(1 , 1 , n , pos , pos + cnt - 1 , 1 , id) ;
                pos += cnt ;
            }
        }
        else {
            for(int id = 25 ; id >= 0 ; --id ) {
                int cnt = query(1 , 1 , n , l , r , id) ;
                update(1 , 1 , n , l , r , 0 , id) ;
                if (cnt == 0) continue ;
                update(1 , 1 , n , pos , pos + cnt - 1 , 1 , id) ;
                pos += cnt ;
            }
        }
    }

    for(int i = 1 ; i <= n ; ++i )
        for(int id = 0 ; id < 26 ; ++id ) if (query(1 , 1 , n , i , i , id) == 1) ans[i] = (char)(id) + 'a' ;
    puts(ans + 1) ;


    return 0;
}
