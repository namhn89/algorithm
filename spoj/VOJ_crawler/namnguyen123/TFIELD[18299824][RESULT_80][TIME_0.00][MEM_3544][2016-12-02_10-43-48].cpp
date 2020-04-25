using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e3 + 5 ;
pair < long long, int> F[MAXN] ;
pair < long long, int> S[MAXN] ;
int x[MAXN], y[MAXN] ;
int f[MAXN] ;
int n, k ;
int main()
{
#define TASK "TFIELD"
    //freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    scanf("%d %d",&n,&k) ;
    FORE(i, 1, n )
    {
        long long S = 0 ;
        int n_point, color ;
        scanf("%d %d",&n_point, &color) ;
        FORE(j, 1, n_point )
        {
            scanf("%d %d", &x[j], &y[j] );
        }
        x[n_point + 1] = x[1] ;
        y[n_point + 1] = y[1] ;
        FORE(j, 1, n_point)
        {
            S += (x[j] - x[j + 1]) * (y[j] + y[j + 1])  ;
        }
        S = abs(S) ;
        F[i] = make_pair(S, color)  ;
    }
    sort(F + 1, F + n + 1) ;
    FORE(i, 1, n )
    {
        S[i].st = F[i].st - F[i - 1].st ;
        S[i].nd = F[i].nd ;
    }
    long long ans = 0 ;
    FORE(i, 1, n )
    {
        memset(f, 0, sizeof(f)) ;
        long long sum = S[i].st ;
        int maxC = 1, len = 1 ;
        f[S[i].nd]++;
        ans = max(ans, sum) ;
        for(int j = i + 1 ; j <= n ; ++j )
        {
            f[S[j].nd]++;
            len++;
            maxC = max(maxC, f[S[j].nd] ) ;
            if (len - maxC <= k )
            {
                sum += S[j].st ;
                ans = max(ans, sum) ;
            }
        }
    }
    if (ans & 1)
    {
        ans /= 2 ;
        printf("%lld",ans ) ;
        printf(".5") ;
    }
    else
    {
        ans /= 2 ;
        printf("%lld",ans);
        printf(".0");
    }

    return 0;
}
