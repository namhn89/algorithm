using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 5 ;
const long long INF = 1e18 ;

long long F[MAXN] , dp1[MAXN] , dp2[MAXN] ;
int s[MAXN] ;

long long solve(long long n)
{
    int k = 0;
    for(int i = 89 ; i >= 1 ; i--)
    {
        if(n >= F[i])
        {
            k++;
            s[k] = i;
            n -= F[i];
        }
    }
    reverse (s + 1 , s + 1 + k) ;
    dp1[1] = 1 ;
    dp2[1] = (s[1] - 1) / 2;
    for(int i = 2 ; i <= k ; i++)
    {
        dp1[i] = dp1[i - 1] + dp2[i - 1];
        dp2[i] = dp1[i - 1] * ( (s[i] - s[i - 1] - 1) / 2) + dp2[i - 1] * ( (s[i] - s[i - 1]) / 2);
    }
    return dp1[k] + dp2[k];
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    F[1] = 1 ;
    F[2] = 2 ;
    for (int i = 3 ; i <= 89 ; ++i ) F[i] = F[i - 1] + F[i - 2] ;
    int nTest ;
    scanf("%d",&nTest) ;
    while(nTest--)
    {
        long long n ;
        scanf("%lld", &n) ;
        printf("%lld\n", solve(n)) ;
    }
    return 0;
}
