using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long power (long long a , long long n) {
   a %= MOD ;
   long long res = 1 ;
   while(n) {
      if (n & 1) res = (res * a) % MOD ;
      a = (a * a) % MOD ;
      n >>= 1 ;
   }
   return res ;
}
long long inverse (long long a) { return power(a , MOD - 2 ) ; }
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    string s ;
    long long k ;
    cin >> s >> k ;
    long long n = s.size() ;
    long long ans = 0 ;
    for(int i = 0 ; i < n ; ++i ) if (s[i] == '0' || s[i] == '5') ans = (ans + power(2 , i)) % MOD ;
    ans = (ans * (power(2 , (n * k % (MOD - 1))) - 1) ) % MOD ;
	ans = (ans * inverse (power(2 , n ) - 1) ) % MOD ;
	cout << ans << endl;
    return 0;
}
