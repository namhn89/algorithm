using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long phi(long long n)
{
    long long res = n;
    for (long long i=2; i*i<=n; ++i)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            res -= res / i;
        }
    if (n > 1)
        res -= res / n;
    return res;
}
long long power (long long a , long long n , long long mod) {
    long long res = 1;
    while(n){
        if(n & 1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        n >>= 1 ;
    }
    return res ;
}
string b , n ;
long long c ;
long long string_to_num (string s) {
    long long res = 0 ;
    for(int i = 0 ; i < s.size() ; ++i ) {
         res = res * 10 + s[i] - '0' ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> b >> n >> c ;
    long long A = 0 ;
    long long X = 0 ;
    int mod_phi = phi(c) ;
    n[n.size() - 1]--;
    for(int i = 0 ; i < b.size() ; ++ i ) A = ( (A * 10) + (b[i] - '0') ) % c ;
    for(int i = 0 ; i < n.size() ; ++ i ) X = ( (X * 10) + (n[i] - '0') ) % mod_phi ;
    bool add = true ;
    if (n.size() <= 10 ) {
         if ( string_to_num(n) < mod_phi) add = false ;
    }
    if (add) X = X + mod_phi ;
    long long ans = ( (A - 1) % c + c) * power(A , X , c) ;
    ans %= c ;
    if(!ans) cout << c << endl;
    else cout << ans << endl;
    return 0;
}
