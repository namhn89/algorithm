using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int MAXS = 400 ;
const int LIM = 350 ;
int f[MAXN][MAXS], a[MAXN], n, q ;
int main()
{
#define TASK "test"
    // freopen(TASK".inp","r",stdin);
   //  freopen(TASK".out","w",stdout);
    scanf("%d", &n) ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d", &a[i]) ;
    for(int k = 1 ; k <= LIM ; ++k )
        for(int p = n ; p >= 1 ; --p )
        {
            if (p + a[p] + k > n) f[p][k] = 1 ;
            else f[p][k] = f[p + a[p] + k][k] + 1 ;
        }
    scanf("%d", &q) ;
    while(q--)
    {
        int p , k ;
        scanf("%d %d", &p , &k) ;
        if (k < sqrt(n) ) printf("%d\n", f[p][k]) ;
        else
        {
            int ans = 0 ;
            while(p <= n)
            {
                ans++;
                p = p + a[p] + k ;
            }
            printf("%d\n", ans) ;
        }
    }


    return 0;
}
