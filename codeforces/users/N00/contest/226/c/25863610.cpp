using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
map < long long , long long > F ;
long long L , R , MOD , k ;
long long fibo (long long n) {
    if (F.count(n)) return F[n] ;
    long long k = n / 2 ;
    if (n % 2)
        return F[n] = (fibo(k) * fibo(k + 1) % MOD + fibo(k) * fibo(k - 1) % MOD ) % MOD ;
    else
        return F[n] = (fibo(k) * fibo(k) % MOD + fibo(k - 1) * fibo(k - 1) % MOD ) % MOD ;
}
int main ()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> MOD >> L >> R >> k ;
    F[0] = 1 % MOD ;
    F[1] = 1 % MOD ;
    vector <long long> val ;
    for(long long i = 1 ; i * i <= R ; ++i) {
            val.push_back(i) ;
            val.push_back(R / i) ;
    }
    for(long long i = 1 ; i * i <= L ; ++i )
    {
         if (L % i == 0) val.push_back(L / i) ;
         else val.push_back(L / (i + 1) ) ;
    }
    long long ans = 0 ;
    for(int i = 0 ; i < val.size() - 1 ; ++i ) {
          long long r = R / val[i] ;
          long long l = (L - 1) / val[i] ;
          if (r - l >= k) ans = max(ans , val[i]) ;
    }
    cout << fibo(ans - 1) % MOD << endl;
}
