using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
long long Tree[MAXN * 4] ;

typedef long double ld ;
const long double pi = 3.14159265359 ;

void update (int node , int l , int r , int u , long long val )
{
    if (l > u || r < u) return ;
    if (l == r)
    {
        Tree[node] = val ;
        return ;
    }
    int mid = (l + r) / 2 ;
    update(node * 2 , l , mid , u , val ) ;
    update(node * 2 + 1 , mid + 1 , r , u, val) ;
    Tree[node] = max(Tree[node * 2] , Tree[node * 2 + 1]) ;
    return ;
}

long long get (int node , int l , int r , int u , int v) {
    if (v < l || u > r) return 0 ;
    if (u <= l && r <= v) return Tree[node] ;
    int mid = (l + r) / 2 ;
    return max( get(node * 2 , l , mid , u , v) , get(node * 2 + 1 , mid + 1 , r , u , v) ) ;
}

long long f[MAXN] ;
struct data
{
    long long v , id ;
    data () {} ;
    data (long long v , long long id) : v(v) , id(id) {}
    bool operator < (const data &op ) const
    {
        if (v != op.v) return v < op.v ;
        return id > op.id ;
    }
};
long long n , r[MAXN] , h[MAXN] ;
data a[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(8) ;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i ) {
         cin >> r[i] >> h[i] ;
         a[i].v = 1LL * r[i] * r[i] * h[i] ;
         a[i].id = i ;
    }
    sort(a + 1 , a + n + 1) ;
    for(int i = 1 ; i <= n ; ++i ) {
         long long pos = a[i].id ;
         long long v = a[i].v ;
         f[i] = get(1 , 1 , n , 1 , pos - 1) + v ;
         update(1 , 1 , n , pos , f[i]) ;
    }
    long double ans = ld(get(1 , 1 , n , 1 , n)) * PI ;
    cout << ans << endl ;
    return 0;
}