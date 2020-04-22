using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n ;
    cin >> n ;
    if (n % 3 != 0)
    {
        cout << 0 << endl;
        return 0 ;
    }
    n /= 3 ;
    long long ans = 0 ;
    vector < long long > divisor ;
    for(long long i = 1 ; i * i <= n ; ++i ) if (n % i == 0) divisor.push_back(i) ;
    for(int i = 0 ; i < divisor.size() ; ++ i )
    {
        long long x = divisor[i] ;
        if (x * x * x > n) break ;
        for(int j = i ; j < divisor.size() ; ++ j )
        {
            long long y = divisor[j] ;
            if (x * x * y > n ) break ;
            if (n % (x * y) == 0 )
            {

                long long z = n / (x * y) ;
                //printf("%lld %lld %lld\n", x,y, z);
                long long s = (x + y + z) ;
                if (s % 2 == 0 && z >= y && y >= x )
                {
                    long long a = s / 2 - z ;
                    long long b = s / 2 - x ;
                    long long c = s / 2 - y ;
                    if (a > 0 && b > 0 && c > 0)
                    {
                        if (a == b && b == c) ans ++ ;
                        else if (a == b || b == c || c == a) ans += 3 ;
                        else ans += 6 ;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
