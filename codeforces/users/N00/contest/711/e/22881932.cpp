using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e6 + 3  ;
const int MAXN = 1e5 + 5 ;

long long  power (long long  a, long long  n)
{
    a %= MOD ;
    long long r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % MOD ;
        a = ( a * a ) % MOD;
        n >>= 1 ;
    }
    return r;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n , k ;
    cin >> n >> k ;
    if (n <= 63 && k > (1LL << n)){
           cout << 1 << " " << 1 << endl;
           return 0 ;
    }
    long long nth = n % (MOD - 1) ;
    long long kth = k % (MOD - 1) ;
    int digits = __builtin_popcountll(k - 1) ;
    long long v2 = k - 1 - digits ;
    long long v2th = v2 % (MOD - 1) ;
    long long exp = nth * (kth - 1) - v2th ;
    exp %= (MOD - 1) ;
    if (exp < 0) exp += (MOD - 1) ;
    long long denominator = power(2 , exp) ;
    long long numerator , res ;
    if (k - 1 >= MOD ){
        res = 0 ;
    }
    else {
        long long pro = 1 ;
        long long two_n = power(2 , nth) ;
        pro = power(2 , v2th) ;
        pro = power(pro , MOD - 2) ;
        for(int y = 1 ; y <= k - 1 ; ++y){
                pro *= (two_n - y) ;
                pro %= MOD ;
        }
        res = pro ;
    }
    numerator = denominator - res ;
    numerator = (numerator % MOD + MOD) % MOD ;
    denominator = (denominator % MOD + MOD) % MOD ;
    cout << numerator << " " << denominator << endl;


    return 0;
}
