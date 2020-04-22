using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e3 + 5 ;
pair < double, int> F[MAXN] ;
pair < double, int> S[MAXN] ;
int x[MAXN], y[MAXN] ;
int n, k ;
int main()
{
#define TASK "TFIELD"
   // freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    scanf("%d %d",&n,&k) ;
    //cout << fixed << setprecision(1) ;
    FORE(i, 1, n )
    {
        double S = 0 ;
        int n_point, color ;
        scanf("%d %d",&n_point , &color) ;
        FORE(j, 1, n_point )
        {
            scanf("%d %d", &x[j] , &y[j] );
        }
        x[n_point + 1] = x[1] ;
        y[n_point + 1] = y[1] ;
        FORE(j, 1, n_point)
        {
            S += (x[j] - x[j + 1]) * (y[j] + y[j + 1])  ;
        }
        S = abs(S) / (2.0);
        F[i] = make_pair(S, color)  ;
    }
    sort(F + 1, F + n + 1) ;
    FORE(i, 1, n )
    {
        S[i].st = F[i].st - F[i - 1].st ;
        S[i].nd = F[i].nd ;
    }
    double ans = 0 ;
    FORE(i, 1, n )
    {
        int j = i + 1 ;
        int color = k ;
        while(j <= n)
        {
            if (color == 0 && S[j].nd != S[i].nd ) break ;
            if (S[j].nd != S[i].nd ) color-- ;
            j++;
        }
        j-- ;
        //cout << i << " " << j << endl;
        double sum = 0 ;
        FORE(k , i , j ) sum += S[k].st ;
        ans = max(ans , sum ) ;
    }
    printf("%0.1f\n",ans);

    return 0;
}
