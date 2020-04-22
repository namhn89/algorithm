using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int oo = 1e9 + 10 ;
const int MAXN = 1e6 + 5 ;
int a[MAXN], b[MAXN] ;
int n, k ;
long long F[25][25] ;
int cnt[MAXN] ;
void solve ()
{
    memset(F, 0, sizeof (F) ) ;
    memset(cnt, 0, sizeof (cnt) ) ;
    FORE(i, 1, n )
    {
        int z = a[i] ;
        FORE(j, 1, k) if (j != z) F[j][z] += cnt[j] ;
        cnt[z] ++ ;
    }
    long long ans = 0 ;
    FORE(i , 1 , k )
    {
        FORE(j , 1 , i - 1 )
        {
            ans += min(F[i][j], F[j][i]) ;
        }
    }
    printf("%lld\n",ans);
}
int main()
{
#define TASK "ballsort"
   //freopen(TASK".inp","r",stdin);
   //freopen(TASK".out","w",stdout);
    while(~scanf("%d %d",&n, &k))
    {
        if(n == 0 && k == 0) break;
        FORE(i, 1, n) scanf("%d", &a[i]);
        solve () ;
    }
    return 0;
}
