using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long power (long long a, long long n, long long MOD)
{
    long long res = 1 ;
    a %= MOD ;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
long long n ;
bool Is_prime(long long n) {
   for(int i = 2 ; i * i <= n ; ++i ) if (n % i == 0) return false ;
   return true ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n ;
    if (n == 1) {
        printf("YES\n1\n") ;
        return 0 ;
    }
    if (n == 4) {
        printf("YES\n1\n3\n2\n4\n") ;
        return 0 ;
    }
    if (Is_prime(n)) {
        vector <int> ans ;
        ans.push_back(1) ;
        for(int i = 2 ; i < n ; ++i ) {
            long long x = (i * power(i - 1 , n - 2 , n) ) % n  ;
            ans.push_back(x) ;
        }
        ans.push_back(n) ;
        cout << "YES" << endl;
        TR(ans , it) cout << *it << endl ;
        return 0 ;
    }
    cout << "NO" << endl;
    return 0 ;
}
