using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long a[MAXN] ;
long long power (long long a, long long n)
{
    a %= MOD ;
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int n ;
    scanf("%d",&n) ;
    FORE(i , 1 , n) scanf("%lld",&a[i]);
    bool even = false ;
    long long index = 1 ;
    FORE(i , 1 , n) {
         if (a[i] % 2 == 0 ) even = true ;
         index = (index * (a[i] % (MOD - 1))) % (MOD - 1) ;
    }
    if(even) {
        long long p = power(2 , index - 1 + MOD - 1) + 1 ;
        p = (p * (power(3 , MOD - 2))) % MOD ;
        long long q = power(2 , index - 1 + MOD - 1) ;
        printf("%lld/%lld",p , q) ;
    }
    else {
        long long p = power(2 , index - 1 + MOD - 1) - 1 ;
        p = (p * (power(3 , MOD - 2))) % MOD ;
        long long q = power(2 , index - 1 + MOD - 1) ;
        printf("%lld/%lld",p , q) ;
    }
    return 0;
}
