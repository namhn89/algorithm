using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const int N = 1e6 + 1 ;
long long fact[MAXN] , infact[MAXN] ;
long long power (long long a , long long n) {
    long long res = 1 ;
    while(n) {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
long long nCr (int n , int r) {
   if (r > n) return 0 ;
   long long res = fact[n] ;
   res = (res * infact[n - r]) % MOD ;
   res = (res * infact[r] ) % MOD ;
   return res ;
}
int a[MAXN] , n , k ;
long long S[MAXN] , dp[MAXN] ;

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 1 ; i <= N ; ++i ) fact[i] = (fact[i - 1] * i ) % MOD ;
    for(int i = 1 ; i <= N ; ++i ) infact[i] = power(fact[i] , MOD - 2) ;
    scanf("%d %d", &n , &k) ;
    for(int i = 1;  i <= n ; ++i ) {
        scanf("%d", &a[i]) ;
        S[i] = S[i - 1] + a[i] ;
    }
    long long ans = 0 ;
    if (S[n] % k ) {
        printf("0\n") ; return 0 ;
    }
    if (S[n] % k == 0) {
        long long average = S[n] / k ;
        if (average == 0) {
        int cnt = 0  ;
        for(int i = 1 ; i <= n ; ++i ) if (S[i] == 0) cnt++ ;
        ans = (ans + nCr(cnt - 1 , k - 1)) ;
        }
        else {
            dp[0] = 1 ;
            for(int i = 1 ; i <= n ; ++i ) {
                 if (S[i] % average == 0) {
                        int id = S[i] / average ;
                        dp[id] = (dp[id] + dp[id - 1]) % MOD ;
                 }
            }
        }
        ans = dp[k - 1] ;
    }
    printf("%lld\n", ans) ;

    return 0;
}
