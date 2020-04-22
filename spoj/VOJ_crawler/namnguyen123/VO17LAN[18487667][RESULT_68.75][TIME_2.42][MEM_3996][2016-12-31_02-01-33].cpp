using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int a[MAXN] ;
int n ;
void sub1 ()
{
    long long b[21] ;
    for(int i = 1 ; i <= n ; ++i ) b[i - 1] = a[i] ;
    long long res = 0 ;
    for(int mask = 1 ; mask < (1 << n) ; ++ mask )
    {
        long long gcdS1 = 0 ;
        long long gcdS2 = 0 ;
        for(int j = 0 ; j < n ; ++j )
        {
            if( (mask & (1 << j)) != 0) gcdS1 = __gcd(gcdS1, b[j]) ;
            else gcdS2 = __gcd(gcdS2, b[j]) ;
        }
        res = max(res, min(gcdS1, gcdS2)) ;
    }
    printf("%lld\n", res) ;
}
map <int, int> vis ;

bool check(int gcd)
{
    vis.clear() ;
    int ans1 = 0, ans2 = 0 ;
    ans1 = a[1] ;
    vis[a[1]] = 1 ;
    for(int i = 2; i <= n; ++i)
        if(__gcd(ans1, a[i]) >= gcd)
        {
            ans1 = __gcd(ans1, a[i]) ;
            vis[a[i]] = 1 ;
        }
    bool ok = false;
    for(int i = 2; i <= n; ++i)
        if(!vis[a[i]])
        {
            ok = true ;
            ans2 = __gcd(ans2, a[i]) ;
        }
    if(!ok) ans2 = ans1 ;
    if(ans1 >= gcd && ans2 >= gcd) return true ;
    return false ;
}

void sub23()
{
    int l = 0, r = 1000000000, m, ans = -1 ;
    while(l <= r)
    {
        m = (l + r) >> 1 ;
        if(check(m)) l = m + 1, ans = m ;
        else r = m - 1 ;
    }
    printf("%d\n", ans) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d", &n) ;
        FORE(i, 1, n ) scanf("%d", &a[i]) ;
        if (n <= 15) sub1 () ;
        else sub23() ;
    }
    return 0;
}
