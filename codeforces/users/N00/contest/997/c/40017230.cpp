using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 998244353 ;
const int MAXN = 1e6 + 5 ;
const int N = 1e6 + 1 ;
int n ;
long long power (long long a , long long n) {
    long long res = 1 ;
    while(n) {
        if (n & 1LL) res = (res * a) % MOD ;
        n >>= 1LL ;
        a = (a * a) % MOD ;
    }
    return res ;
}
long long fact[MAXN] , infact[MAXN] , pw3[MAXN] ;

long long nCr (long long n , long long k) {
    if (k > n) return 0 ;
    long long res = fact[n] ;
    res = (res * infact[k]) % MOD ;
    res = (res * infact[n - k]) % MOD ;
    return res ;
}
long long f (int u , int v) {
    long long res = 3;
    if (u == 0 || v == 0) res = pw3[u + v] ;
    res = (res * power(3 , 1LL* (n - u) * (n - v) )) % MOD ;
    return res ;
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    fact[0] = infact[0] = pw3[0] = 1 ;
    for(int i = 1 ; i <= N ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    for(int i = 1 ; i <= N ; ++i ) infact[i] = power(fact[i] , MOD - 2) % MOD ;
    for(int i = 1 ; i <= N ; ++i ) pw3[i] = (pw3[i - 1] * 3) % MOD ;
    long long ans = 0 ;
    cin >> n ;
    for(int i = 0 ; i <= n ; ++i ) {
          if (i == 0) continue ;
             long long res = f(i , 0) ;
             res = (res * nCr(n , i) ) % MOD ;
             res = (res * 2) % MOD ;
             if (i & 1) ans += res ; // (-1) ^ (i + 1)
             else ans -= res ;
             ans %= MOD ;
    }
    for(int i = 0 ; i <= n - 1 ; ++i ) {
         long long H = power(3 , i) % MOD ;
         H *= (-1LL) ;
         long long res = (power(H + 1 , n) - power(H , n)) % MOD ;
         res = (res + MOD) % MOD ;
         res = (res * 3) % MOD ;
         res = (res * nCr(n , i)) % MOD ;
         if (i & 1) ans += res ; // (-1) ^ (i + 1)
         else ans -= res ;
         ans %= MOD ;
    }
    cout << (ans + MOD) % MOD ;
    return 0;
}
