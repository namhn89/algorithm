using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

long long x, y, p, q ;
bool check (long long val )
{
    long long k = val * q - y, t = val * p - x ;
    return (k >= t) ;
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int T ;
    scanf("%d", &T) ;
    while(T--)
    {
        scanf("%lld %lld %lld %lld", &x, &y, &p, &q) ;
        if (p == 0)
        {
            if (x == 0) printf("0\n") ;
            else printf("-1\n") ;
        }
        else
        {
            long long L = max( (x + p - 1) / p, (y + q - 1) / q ), R = (long long) (1e18) / q, res = -1 ;
            while(L <= R)
            {
                long long mid = (L + R) / 2 ;
                if (check(mid)) res = (mid * q) - y, R = mid - 1 ;
                else L = mid + 1 ;
            }
            printf("%lld\n",res) ;
        }
    }
    return 0;
}
