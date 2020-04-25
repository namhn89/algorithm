using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int n ;
int a[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int Test ;
    scanf("%d",&Test) ;
    while(Test--)
    {
        map <int, int> f ;
        scanf("%d",&n) ;
        for(int i = 1 ; i <= n ; ++i ) scanf("%d",&a[i]) ;
        sort(a + 1, a + n + 1) ;
        reverse(a + 1, a + n + 1) ;
        int Max1 = 0, Max2 = 0 ;
        for(int i = 1 ; i <= n ; ++i )
        {
            if (f[a[i]] == 0) f[a[i]]++;
            else
            {
                Max1 = max(Max1, a[i]) ;
            }
        }
        if (f[Max1] >= 4)
        {
            long long ans = Max1 * Max1 ;
            printf("%lld\n", ans)  ;
        }
        else
        {
            f.clear() ;
            for(int i = 1 ; i <= n ; ++i )
            {
                if( f.find(a[i]) == f.end() ) f[a[i]]++;
                else
                {
                    if (a[i] != Max1) Max2 = max(Max2, a[i]) ;
                }
            }
            long long ans = Max1 * Max2 ;
            if (ans == 0) printf("-1\n") ;
            else printf("%lld\n",ans) ;
        }
    }
    return 0;
}
