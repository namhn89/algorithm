using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)


const int MAXN = 1e5 + 5 ;

long long a , b , mod , x ;
long long power (long long a , long long n) {
    long long res = 1 ;
    while(n) {
        if (n & 1LL) res = (res * a) % mod;
        a = (a * a) % mod ;
        n >>= 1LL ;
    }
    return res ;
}
long long inv (long long h) {
   return power(h , mod - 2) ;
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b >> mod >> x ;
    long long p = mod ;
    long long ans = 0 ;
    for(long long j = 1 ; j <= (p - 1) ; ++j ) {
          long long i = (j - ((b * inv(power(a , j))) % mod) + mod ) % mod ;
          long long n = (p - 1) * i + j ;
          if (n > x) continue ;
          ans += (x - n) / (p * (p - 1)) + 1;
    }
    cout << ans << endl;
    return 0;
}
