using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e4 + 1 ;

int n , Max , cnt[MAXN] , p[MAXN] , dp[MAXN] ;
long long ret ;
int main ()
{

    // Input reading

    while(~scanf("%d",&n))
    {
        for(int i = 0 ; i < MAXN ; ++i ) { cnt[i] = 0 ;  p[i] = 0 ; dp[i] = 0 ; }
        Max = 0;
        ret = 0 ;
        for(int i = 1 ; i <= n ; i++)
        {
            int x ;
            scanf("%d", &x);
            cnt[x]++ ;
            Max = max(Max , x);
        }

        // Mobius function calculation

        for(int i = 2 ; i <= Max ; i++) if (!p[i])
            {
                int j = i;
                while (j <= Max)
                {
                    if (!p[j]) p[j] = i;
                    j += i;
                }
            }
        for(int i = 1 ; i <= Max ; i++)
        {

            // Mobuis function

            if (i == 1) dp[i] = 1;
            else
            {
                if (p[i / p[i]] == p[i]) dp[i] = 0;
                else // Checking for non square-free
                    dp[i] = -1 * dp[i / p[i]] ;
            }
            if (!dp[i]) continue;

            // Calculating D(X). Can be done naively, because [N/1] + [N/2] + [N/3] + ... + [N/N] -> N log N

            int j = i ;
            long long ans = 0;
            while (j <= Max)
            {
                ans += cnt[j];
                j += i;
            }

            // Adding the number of the combinations to the final answer

            ret += ( (ans - 1) * (ans - 2) * (ans - 3) * ans / 24 ) * dp[i] ;
        }
        cout << ret << endl;
    }
    return 0;
}
