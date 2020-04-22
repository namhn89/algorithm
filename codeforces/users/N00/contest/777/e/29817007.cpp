using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
const int oo = 1e9 + 1 ;
struct data {
   int a , b , h ;
    bool operator < (const data &op) const
    {
        if (b != op.b) return b > op.b ;
        else if (a != op.a) return a > op.a ;
        else return h < op.h ;
    }
};
map < int , long long> f ;
data p[MAXN] ;
long long res[MAXN] ;
int n ;
void update (int node , long long val) {
   for(int i = node ; i < oo ; i += i & (-i)) f[i] = max(f[i] , val) ;
}
long long query (int node) {
   long long ans = 0 ;
   for(int i = node ; i > 0 ; i -= i & (-i)) ans = max(ans , f[i]) ;
   return ans ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i ) cin >> p[i].a >> p[i].b >> p[i].h ;
    sort(p + 1 , p + n + 1) ;
    for(int i = 1 ; i <= n ; ++i ) res[i] = p[i].h ;
    for(int i = 1 ; i <= n ; ++i ) {
        res[i] += query(p[i].b - 1) ;
        update(p[i].a , res[i]) ;
    }
    long long ans = 0 ;
    for(int i = 1 ; i <= n ; ++i ) ans = max(ans , res[i]) ;
    cout << ans ;


    return 0;
}
