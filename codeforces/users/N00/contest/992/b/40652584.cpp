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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long x , y , l , r ;
    cin >> l >> r >> x >> y ;
    if (y % x != 0 ) {cout << 0 ; return 0 ;}
    else {
        int ans = 0 ;
        long long n = y / x ;
        for(long long i = 1 ; i * i <= n ; ++i ) {
             if (n % i == 0) {
                  long long k = n / i ;
                  if (__gcd(k , i) == 1 && x * k >= l && x * k <= r && i * x >= l && i * x <= r) {
                      if (i * i == n) ans++ ;
                      else ans += 2 ;
                  }
             }
        }
        cout << ans ;

    }

    return 0;
}
