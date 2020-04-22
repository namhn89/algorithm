using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e6 + 3 ;
const int MAXN = 1e5 + 5 ;
long long power (long long a , long long n) {
   long long res = 1 ;
   while(n) {
      if (n & 1) res = (res * a) % MOD ;
      a = (a * a) % MOD ;
      n >>= 1 ;
   }
   return res ;
}
long long calc (long long n , long long p) {
    long long res = 0 ;
    while(n) {
        res += n / p ;
        n /= p ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    long long n , k ;
    cin >> n >> k ;
    if ( (1LL << n) < k && n <= 63) {
        cout << 1 << ' ' << 1 << endl;
        return 0 ;
    }
    long long nth = n % (MOD - 1) ;
    long long kth = k % (MOD - 1) ;
    long long cnt2 = calc(k - 1 , 2) % (MOD - 1);
    long long two = power(2 , n % (MOD - 1) ) ;
    long long cnt_y = nth * (kth - 1) - cnt2 ;
    cnt_y %= (MOD - 1) ;
    if (cnt_y < 0) cnt_y += (MOD - 1) ;
    long long denominator = power(2 , cnt_y) , ans , numerator ;
    if (k - 1 >= MOD ) ans = 0 ;
    else {
        ans = 1 ;
        for(int i = 1 ; i < k ; ++i) ans = (ans * (two - i)) % MOD ;
        ans = (ans *  power( power(2 , cnt2) , (MOD - 2) ) ) % MOD ;
    }
    numerator = denominator - ans ;
    numerator = (numerator % MOD + MOD) % MOD ;
    denominator = (denominator % MOD + MOD) % MOD ;
    cout << numerator << " " << denominator << endl;

    return 0;
}
