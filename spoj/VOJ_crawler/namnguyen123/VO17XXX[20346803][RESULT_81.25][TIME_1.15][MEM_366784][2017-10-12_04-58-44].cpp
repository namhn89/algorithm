using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e7 + 5 ;
int P[MAXN] , cnt[MAXN] , a[MAXN] ;
long long pw2[MAXN] ;
long long pwC[MAXN] ;
long long F[MAXN] ;
const int N = 1e6 + 1 ;
long long power (long long a , long long n) {
    long long res = 1 ;
}
int n , C ;
void sieve () {
    for(int i = 1 ; i <= N ; ++i ) P[i] = i ;
    for(int i = 2 ; i <= N ; ++i )
        if (P[i] == i) for(int j = i ; j <= N ; j += i ) P[j] = i ;
}
int main()
{
#define TASK "VO17XXX"
     //freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    sieve() ;
    scanf("%d %d", &n , &C) ;
    int Max = 0 ;
    pw2[0] = pwC[0] = 1LL ;
    for(int i = 1 ; i <= N ; ++i ) pw2[i] = (pw2[i - 1] * 2LL) % MOD , pwC[i] = (pwC[i - 1] * 1LL * C) % MOD ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d" , &a[i]) , cnt[a[i]]++ , Max = max(Max , a[i]) ;
    for(int i = Max ; i >= 1 ; i-- ) {
        F[i] = 0 ;
        int res = 0 ;
        for(int j = i ; j <= Max ; j += i) {
              res += cnt[j] ;
              if (j > i) F[i] = (F[i] - F[j] + MOD) % MOD ;
        }
        F[i] = (F[i] + pw2[res] - 1 + MOD) % MOD ;
    }
    long long ans = 0 ;
    for(int i = Max ; i >= 1 ; i-- ) {
         if (F[i] == 0) continue ;
         int K = 0 ;
         int x = i ;
         while(x != 1) {
             int u = P[x] ;
             K++ ;
             while(x % u == 0) x /= u ;
         }
         ans = (ans + pwC[K] * F[i]) % MOD ;
    }
    printf("%lld\n" , ans) ;
    return 0;
}
