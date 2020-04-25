using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

long long power (long long a , long long n , long long MOD) {
    long long res = 1 ;
    while(n) {
         if (n & 1) res = (res * a) % MOD ;
         a = (a * a) % MOD ;
         n >>= 1 ;
    }
    return res ;
}
long long phi (long long n) {
    long long res = n ;
    for(long long i = 2 ; i * i <= n ; ++i ) {
        if (n % i == 0)
        {
            while(n % i == 0) n /= i ;
            res -= res / i ;
        }
    }
    if (n > 1) res -= res / n ;
    return res ;
}
long long solve (string a , string b , long long MOD) {
     long long c = phi(MOD) ;
     long long X = 0 ;
     long long T = 0 ;
     for(int i = 0 ; i < b.size() ; ++i) T = (T * 10 + b[i] - '0') % c ;
     for(int i = 0 ; i < a.size() ; ++i) X = (X * 10 + a[i] - '0') % MOD ;
     return power(X , T , MOD) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string a , b ; long long MOD ;
    cin >> a >> b >> MOD ;
    cout << solve(a , b , MOD) << endl;

    return 0;
}
