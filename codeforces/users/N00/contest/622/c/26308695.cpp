using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
const int oo = 2e9 ;
typedef pair <int, int> II ;

II TMAX[4 * MAXN] , TMIN[4 * MAXN] ;
int a[MAXN] , n , q ;

void build (int node , int l , int r)
{
    if (l > r) return ;
    if (l == r)
    {
        TMAX[node] = II(a[l] , l) ;
        TMIN[node] = II(a[l] , l) ;
        return ;
    }
    int mid = (l + r) / 2 ;
    build(node * 2 , l , mid) ;
    build(node * 2 + 1 , mid + 1 , r) ;
    TMAX[node] = max(TMAX[node * 2] , TMAX[node * 2 + 1]) ;
    TMIN[node] = min(TMIN[node * 2] , TMIN[node * 2 + 1]) ;
}
II Querymin (int node , int l , int r , int u , int v) {
    if (v < l || r < u) return II(oo , oo) ;
    if (u <= l && r <= v) return TMIN[node] ;
    int mid = (l + r) / 2 ;
    return min(Querymin(node * 2 , l , mid , u , v) , Querymin(node * 2 + 1 , mid + 1 , r , u , v)) ;
}
II Querymax (int node , int l , int r , int u , int v) {
    if (v < l || r < u) return II(-oo , -oo) ;
    if (u <= l && r <= v) return TMAX[node] ;
    int mid = (l + r) / 2 ;
    return max(Querymax (node * 2 , l , mid , u , v) , Querymax (node * 2 + 1 , mid + 1 , r , u , v)) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d",&n ,&q) ;
    for(int i = 1 ; i <= n ; ++i) scanf("%d",&a[i]) ;
    build(1 , 1 , n) ;
    while(q--){
        int l , r , x ;
        scanf("%d %d %d", &l , &r , &x) ;
        int ans = -1 ;
        II Min = Querymin(1 , 1 , n , l , r) ;
        II Max = Querymax(1 , 1 , n , l , r) ;
        if (Min.st == Max.st && Min.st == x) ans = -1;
        else {
            if (Min.st != x) ans = Min.nd ;
            else ans = Max.nd ;
        }
        printf("%d\n",ans) ;
    }

    return 0;
}
