using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 3e4 + 5 ;
const int oo = 1e9 + 7 ;
int l[MAXN], r[MAXN], a[MAXN] , n ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i = 1 ; i <= n ; ++i) scanf("%d", &a[i]) ;
        for(int i = 1 ; i <= n ; ++i)
        {
            l[i] = i ;
            while(a[l[i] - 1] >= a[i] ) l[i] = l[l[i] - 1] ;

        }
        for(int i = n ; i >= 1 ; --i)
        {
            r[i] = i ;
            while(a[r[i] + 1] >= a[i] ) r[i] = r[r[i] + 1] ;
        }
        long long ans = 0 ;
        int L , R ;
        for(int i = 1 ; i <= n ; ++i)
        {
            if (ans < a[i] * (r[i] - l[i] + 1))
            {
                ans = a[i] * (r[i] - l[i] + 1) ;
                L = l[i] ;
                R = r[i] ;
            }
        }
        printf("%lld %d %d\n", ans , L , R) ;
    }
    return 0;
}
