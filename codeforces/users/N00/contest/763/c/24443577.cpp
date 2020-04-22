using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 1e5 + 5 ;
int a[MAXN] ;
long long n , MOD ;

long long power(long long a , long long n) {
   a %= MOD ;
   long long res = 1 ;
   while(n) {
      if (n & 1) res = (res * a) % MOD ;
      a = (a * a) % MOD ;
      n >>= 1;
   }
   return res ;
}
long long inverse (long long a ) {
   return power(a , MOD - 2) ;
}
map < int , int > F ;
bool check (long long x , long long d) {
    long long value = x ;
    for(int j = 1 ; j <= n ; ++j )
    {
        if (!F.count(value)) return false ;
        value += d ;
        if (value >= MOD) value -= MOD ;
    }
    return true ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%lld %lld ", &MOD , &n ) ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d",&a[i]) ;
    if (n == MOD || n == 1 ) {
        printf("%d 1\n", a[1]);
        return 0;
    }
    long long Sum = 0 , Sum_mod = 0 , Sum_square_mod = 0 , S_2 = 0  , S_1 = 0 ;
    for(int i = 1 ; i <= n ; ++i ) {
        F[a[i]] = 1 ;
        Sum += a[i] ;
        Sum_mod = (Sum_mod + a[i]) % MOD ;
        Sum_square_mod = (Sum_square_mod + 1LL * a[i] * a[i]) % MOD ;
    }
    S_1 = (n - 1) * n / 2 ;
    S_2 = (n - 1) * n * (2 * n - 1) / 6 ;
    S_1 %= MOD ;
    S_2 %= MOD ;
    for(int i = 1 ; i <= n ; ++i ) {
         long long x = a[i] ;
         long long d = ((Sum - n * x) % MOD + MOD) % MOD * inverse(S_1) % MOD ;
         long long mod_square =  ( n * x % MOD * x % MOD ) + (2 * x * d % MOD * S_1 % MOD) + (d * d % MOD * S_2 % MOD);
         d %= MOD ; mod_square %= MOD ;
         if (mod_square != Sum_square_mod) continue ;
         if (check(x , d) && d != 0 ) { printf("%lld %lld\n", x , d) ; return 0 ;}
    }
    printf("-1\n") ;
    return 0;
}
