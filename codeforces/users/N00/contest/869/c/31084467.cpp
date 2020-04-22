using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const long long MOD = 998244353 ;
const int MAXN = 5e3 + 50 ;
const int N = 5e3 + 1 ;
long long infact[MAXN] , fact[MAXN] ;
long long power (long long a , long long n) {
    long long res = 1 ;
    while(n) {
        if (n & 1) res = (res * a) % MOD  ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
long long nCr (int r , int n ) {
   if (r > n) return 0 ;
   long long res = fact[n] ;
   res = (res * infact[n - r]) % MOD ;
   res = (res * infact[r]) % MOD ;
   return res ;
}
long long FA[MAXN] , FB[MAXN] ;
int a , b , c ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b >> c ;
    fact[0] = infact[0] = 1LL ;
    for(int i = 1 ; i <= N ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    for(int i = 1 ; i <= N ; ++i ) infact[i] = power(fact[i] , MOD - 2) ;
    long long res = 0 , ans = 0;
    for( int i = 0 ; i <= min(b , c) ; ++ i ){
        res += ( ( nCr( i , b ) * nCr( i , c ) ) % MOD * fact[i] ) % MOD ;
        res %= MOD ;
    }
    FORE(i , 0 , b) FA[i] = ( ( nCr( i , a ) * nCr( i , b ) ) % MOD * fact[i] ) % MOD ;
    FORE(j , 0 , c) FB[j] = ( ( ( nCr(j , a ) * nCr( j , c ) ) % MOD ) * fact[j] ) % MOD ;

   FORE(i , 0 , b){
        FORE(j , 0 , c) {
            ans += ( FA[i] * FB[j] ) % MOD ; ans %= MOD ;
        }
    }

    ans *= res ; ans %= MOD ;
    cout << ans ;

    return 0;
}
