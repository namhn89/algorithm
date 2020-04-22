using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 5 ;
int n ;
long long p[MAXN] , k[MAXN] ;
long long power (long long a , long long n) {
    a %= MOD ;
    long long res = 1 ;
    while(n) {
        if (n & 1LL) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1;
    }
    return res ;
}
long long mul (long long a , long long n , long long MOD )
{ return ((a % MOD) * (n % MOD)) % MOD ; }
long long fpow (long long a , long long n , long long MOD )
{
    if (n == 0) return 1 ;
    if (n % 2 == 0) return ( 1  + mul(a , fpow(a , n - 1, MOD ) , MOD ) % MOD );
    long long T = mul(a + 1 , fpow( mul(a , a , MOD ) , n / 2 , MOD ) , MOD );
    return T ;
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i) cin >> p[i] >> k[i] ;
    long long ans = 1 ;
    for(int i = 1 ; i <= n ; ++i) {
        long long res = 2 * fpow(p[i] , k[i] , MOD) - power(p[i] , k[i]) ;
        if(res < 0) res += MOD ;
        ans = (ans * res) % MOD ;
    }
    cout << ans << endl;

    return 0;
}
