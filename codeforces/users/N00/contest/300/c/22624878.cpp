using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
long long infact[MAXN], fact[MAXN] ;
bool check (int x, int a, int b)
{
    while(x)
    {
        if (x % 10 == a || x % 10 == b)
        {
            x /= 10;
        }
        else return false ;
    }
    return true ;
}
long long nCr (int n, int r )
{
    if (n < r ) return 0 ;
    long long res = 1 ;
    res = ( res * fact[n]) % MOD ;  ;
    res = ( res * infact[n - r] ) % MOD ;
    res = ( res * infact[r] ) % MOD ;
    res %= MOD ;
    return res ;
}
long long powmod(long long a, long long n)
{
    long long r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % MOD ;
        a = ( a * a ) % MOD ;
        n >>= 1 ;
    }
    return r;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, n ;
    cin >> a >> b >> n  ;
    fact[0] = infact[0] = 1 ;
    FORE( i , 1 , n ) fact[i] = (fact[i - 1] *  i) % MOD ;
    FORE( i , 1 , n ) infact[i] = powmod(fact[i] , MOD - 2) ;
    long long ans = 0;
    for(int i = 0 ; i <= n ; ++i )
    {
        int sum = a * i + b * (n - i) ;
        if ( check(sum, a, b ) )
        {
            ans += nCr (n, i) ;
            ans %= MOD ;
        }
    }
    cout << ans << endl;
    return 0;
}
