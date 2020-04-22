using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 1e6 + 500 ;
int phi (int n) {
  int res = n ;
  for (int i = 2 ; i * i <= n ; ++i ) {
      if (n % i == 0) {
         while(n % i == 0) n /= i ;
         res = res - res / i ;
      }
  }
  if (n > 1) res = res - res / n ;
  return res ;
}
int N , M , a , MOD , p = -1 ;
long long power (long long a , long long n , long long mod ) {
   long long res = 1 ;
   while(n) {
     if (n & 1LL) res = (res * a) % mod ;
     a = (a * a) % mod ;
     n >>= 1LL ;
   }
   return res ;
}
long long fact[MAXN] , infact[MAXN] , pw[MAXN] ;
long long nCr (int n , int r) {
   if (n < r) return 0 ;
   return ( (fact[n] * infact[n - r] % p) * (infact[r] % p) ) % p ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> a >> MOD ;
    long long res = 1 ;
    for(int i = 1 ; i <= int(1e9) ; ++i ) {
        res = (res * a) % MOD ;
        if (res == 1) {
            p = i ;
            break ;
        }
    }
    fact[0] = infact[0] = 1LL ;
    for(int i = 1 ; i <= p ; ++i ) fact[i] = (fact[i - 1] * i) % p ;
    for(int i = 1 ; i <= p ; ++i ) infact[i] = power(fact[i] , p - 2 , p ) ;
    for(int i = N ; i >= 1 ; --i ) pw[i] = (pw[i + 1] + nCr(M , N - 1 - (i - 1)) ) % p ;
    for(int i = 1 ; i <= N ; ++i ) {
        long long v = power(a , pw[i] , MOD) ;
        printf("%lld ", v) ;
    }

    return 0;
}
