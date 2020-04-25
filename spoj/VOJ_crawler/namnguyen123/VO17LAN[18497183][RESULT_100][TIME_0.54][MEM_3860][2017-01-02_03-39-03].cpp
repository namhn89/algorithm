using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int n, a[MAXN] ;
int calc (int x , int limit )
{
    int res = 0 ;
    FORE(i, 1, n)
    {
        if (res > 0 && res < limit ) return res ;
        if (a[i] % x != 0 ) res = __gcd(res , a[i]) ;
    }
    if (res == 0) return x ;
    else return res ;
}
void solve ()
{
    int res = 0 ;
    int id = 1 + rand() % n ;
    for(int i = 1 ; i * i <= a[id] ; ++i )
    {
        if (a[id] % i == 0 )
        {
            if (i > res) res = max(res , min(i , calc(i , res) ) ) ;
            if (a[id] / i > res ) res = max(res , min( a[id] / i , calc(a[id] / i , res) ) ) ;
        }
    }
    printf("%d\n", res) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int Test ;
    scanf("%d",&Test) ;
    while(Test --)
    {
        scanf("%d",&n) ;
        FORE(i, 1, n ) scanf("%d",&a[i]) ;
        solve() ;
    }
    return 0;
}
