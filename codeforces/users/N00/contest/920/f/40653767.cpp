using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 3e5 + 5 ;
const int N = 1e6 + 1 ;
int n , m ;
struct data {
    int Max ;
    long long Sum ;
};
data st[4 * MAXN] ;
int a[MAXN] ;
int f[N] ;
void build (int k , int l , int r ) {
    if (l == r) {
        st[k].Max = a[l] ;
        st[k].Sum = a[l] ;
        return ;
    }
    int mid = (l + r) / 2 ;
    build(2 * k , l , mid ) ;
    build(2 * k + 1 , mid + 1 , r) ;
    st[k].Max = max(st[2 * k].Max , st[2 * k + 1].Max) ;
    st[k].Sum = st[2 * k].Sum + st[2 * k + 1].Sum ;
}
void update (int k , int l , int r , int L , int R) {
    if (L > r || R < l) return ;
    if (L <= l  && r <= R ){
        if (st[k].Max <= 2) return ;
        if (l == r) {
            st[k].Max = st[k].Sum = f[st[k].Max] ;
            return ;
        }
    }
    int mid = (l + r) / 2 ;

    update(2 * k , l , mid , L , R ) ;
    update(2 * k + 1 , mid + 1 , r , L , R) ;

    st[k].Max = max(st[2 * k].Max , st[2 * k + 1].Max) ;
    st[k].Sum = st[2 * k].Sum + st[2 * k + 1].Sum ;
}
long long query (int k , int l , int r , int L , int R) {
     if (L > r || R < l ) return 0 ;
     if (L <= l  && r <= R ) return st[k].Sum ;
     int mid = (l + r) / 2 ;
     return query(2 * k , l , mid , L , R ) + query(2 * k + 1 , mid + 1 , r , L , R) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    for (int i = 1 ; i < N ; ++i )
        for(int j = i ; j < N ; j += i ) f[j] ++ ;
    scanf("%d %d", &n , &m) ;
    for(int i = 1 ; i <= n ;  ++i ) scanf("%d", &a[i]) ;
    build(1 , 1 , n) ;
    while(m--){
        int type , l , r ;
        scanf("%d %d %d" , &type , &l , &r) ;
        if (type == 1) {
             update(1 , 1 , n , l , r) ;
        }
        else {
            printf("%lld\n", query(1 , 1 , n , l , r)) ;
        }
    }



    return 0;
}
