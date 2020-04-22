using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 998244353 ;
const int MAXN = 2e3 + 5 ;

int n , m , k ;
long long fact[MAXN] , infact[MAXN] ;

long long power (long long a , long long n) {
  long long res = 1 ;
  while(n) {
     if (n & 1LL ) res = (res * a) % MOD ;
     n >>= 1LL ;
     a = (a * a) % MOD ;
  }
  return res ;
}
long long nCr (int n , int r) {
    if (r > n) return 0 ;
    long long res = fact[n] % MOD ;
    res = (res * infact[r]) % MOD ;
    res = (res * infact[n - r]) % MOD ;
    return res ;
}


int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k ;

    fact[0] = infact[0] = 1 ;
    for (int i = 1 ; i <= n ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    for (int i = 1 ; i <= n ; ++i ) infact[i] = power(fact[i] , MOD - 2) ;

    long long ans = (nCr(n - 1 , k) * power(m - 1 , k)) % MOD * m ;
    ans %= MOD ;
    cout << ans ;



    return 0;
}
