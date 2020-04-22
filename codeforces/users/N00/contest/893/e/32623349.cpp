using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e6 + 200  ;
const int N = 2e6 + 100 ;
int p[MAXN] ;
long long infact[MAXN] , fact[MAXN] ;
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
    if (n < r) return 0 ;
    long long ans = fact[n] ;
    ans = (ans * infact[n - r]) % MOD ;
    ans = (ans * infact[r]) % MOD ;
    return ans ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    fact[0] = 1 , infact[0] = 1 ;
    for(int i = 1 ; i <= N ; ++i ) p[i] = i ;
    for(int i = 2 ; i <= N ; ++i )
        if (p[i] == i) for(int j = i ; j <= N ; j += i) p[j] = i ;
    for(int i = 1 ; i <= N ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    infact[N] = power(fact[N] , MOD - 2) ;
    for(int i = N - 1 ; i >= 1 ; --i ) infact[i] = (infact[i + 1] * (i + 1)) % MOD ;
    int q ;
    scanf("%d", &q ) ;
    while(q--){
        long long ans = 1LL ;
        int x , y ;
        scanf("%d %d", &x , &y) ;
        while(x != 1) {
            int h = p[x] ;
            int cnt = 0 ;
            while (x % h == 0) cnt ++ , x /= h ;
            ans = (ans * nCr(y + cnt - 1 , y - 1) ) % MOD ;
        }
        ans = (ans * power(2 , y - 1)) % MOD;
        printf("%lld\n", ans) ;
    }
    return 0;
}
