using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
typedef long long ll;
ll phi(ll n)
{
    ll result = n;
    for (ll i = 2 ; i * i <= n ; ++i)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    long long n , k ;
    cin >> n >> k ;
    long long ans = n ;
    while(ans != 1 && k != 0)
    {
        if (k % 2 == 1) ans = phi(ans) ;
        k--;
    }
    cout << ans % MOD << endl;
    return 0;
}