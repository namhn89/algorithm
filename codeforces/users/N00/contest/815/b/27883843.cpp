using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
int n ;
long long fact[MAXN] , a[MAXN] ;
const int N = 2e5 + 1 ;
long long power (long long a , long long n) {
    long long res = 1 ;
    while(n) {
        if (n & 1LL) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1LL ;
    }
    return res ;
}
long long nCr (int n , int r) {
    if (n < r) return 0 ;
    return ( ( fact[n] * power(fact[n - r] , MOD - 2) ) % MOD * power(fact[r] , MOD - 2) ) % MOD ;
}
long long f[MAXN][10] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n ;
    fact[0] = 1 ;
    for(int i = 1 ; i <= N ; ++i ) fact[i] = (fact[i - 1] * i ) % MOD ;
    int k = (n - 1) / 4 ;
    int cnt = 0 ;
    for(int i = 1 ; i <= 4 * k + 1 ; ++i ) {
          if (i & 1) f[i][0] = nCr(2 * k , cnt) , cnt++ ;
    }
    vector <long long> res ;
    for(int i = 1 ; i <= 4 * k + 1 ; ++i ) res.push_back(f[i][0]) ;
    for(int i = 4 * k + 2 ; i <= n ; ++i ) {
        vector <long long> ans ;
        for(int j = 0 ; j < i ; j++) {
            if (j == 0) ans.push_back(1) ;
            else if (j == i - 1) {
                if (i % 4 == 0 || i % 4 == 3) ans.push_back(-1) ;
                else ans.push_back(1) ;
            }
            else {
                 if (i % 4) {
                 if (j & 1) ans.push_back(res[j - 1] + res[j]) ;
                 else ans.push_back(res[j] - res[j - 1]) ;
                 }
                 else {
                    if (j & 1) ans.push_back(res[j - 1] - res[j]) ;
                    else ans.push_back(res[j] + res[j - 1]) ;
                 }
            }
        }
        res = ans ;
        for(int i = 0 ; i < res.size() ; ++i) res[i] = (res[i] % MOD + MOD) % MOD ;
    }
    long long result = 0 ;
    for(int i = 0 ; i < n ; ++i ) cin >> a[i] ;
    for(int i = 0 ; i < n ; ++i ) result = (result + 1LL * a[i] * res[i]) % MOD ;
    cout << result << endl;
    return 0;
}
