using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 ;
const int MAXN = 1e5 + 5 ;
const int phi = 400000000 ;
long long power (long long a , long long n) {
    long long res = 1 ;
    while(n) {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
long long Inverse(long long n) {
    return power(n , phi - 1) ;
}

long long F (int n) // 2 * (2n - 1)! / ( (n - 1)! * (n + 1)! )
{
    long long res = 1 ;
    long long cnt2 = 1 , cnt5 = 0 ;
    for(int i = 1 ; i <= n + 1 ; ++i ) {
        int x = i ;
        while(x % 2 == 0) x /= 2 , cnt2--;
        while(x % 5 == 0) x /= 5 , cnt5--;
        res = (res * Inverse(x)) % MOD ;
    }
    for(int i = n ; i <= 2 * n - 1 ; ++i ) {
        int x = i ;
        while(x % 2 == 0) x /= 2 , cnt2++;
        while(x % 5 == 0) x /= 5 , cnt5++;
        res = (res * x) % MOD ;
    }
    res = (res * power(2 , cnt2)) % MOD ;
    res = (res * power(5 , cnt5)) % MOD ;
    return res;
}
long long n , l , r ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    scanf("%lld %lld %lld",&n , &l , &r) ;
    r = 2 ;
    for(int i = 1 ; i < n ; ++i ) {
        int x ;
        scanf("%d",&x) ;
        if (x > l )r++;
        else r = 2 ;
        l = x ;
    }
    printf("%lld %lld",r , F(n + 1)) ;


    return 0;
}
