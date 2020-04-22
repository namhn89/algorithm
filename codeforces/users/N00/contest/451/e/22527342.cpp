using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const long long MOD = 1e9 + 7 ;
const int MAXN = 50 ;
long long a[MAXN], S, fact[MAXN], infact[MAXN], N ;
long long power (long long a, long long n )
{
    long long res = 1 ;
    while(n)
    {
        if(n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
long long nCr (long long n, long long r)
{
    if (n < r ) return 0 ;
    n %= MOD ;
    long long res = 1 ;
    for(int i = 0 ; i < r ; ++i ) res = (res * (long long)(n - i) ) % MOD ;
    res *= infact[r] ;
    res %= MOD ;
    return res ;
}
int main()
{
#define TASK "451E"
  //  freopen(TASK".inp","r",stdin);
  //  freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S ;
    for(int i = 0 ; i < N ; ++i ) cin >> a[i] ;
    fact[0] = infact[0] = 1 ;
    for(int i = 1 ; i <= N ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    for(int i = 1 ; i <= N ; ++i ) infact[i] = power(fact[i], MOD - 2) ;
    long long ans = 0 ;
    for(int mask = 0 ; mask < (1 << N ) ; ++mask )
    {
        long long H = S ;
        for(int j = 0 ; j < N ; ++j)
        {
            if ( (1 << j) & mask )
            {
                H -= (a[j] + 1);
            }
        }
        if (__builtin_popcount(mask) & 1)
        {
            ans -= nCr(H + N - 1, N - 1 ) ;
            ans = (ans + MOD) % MOD ;
        }
        else
        {
            ans += nCr(H + N - 1, N - 1 ) ;
            ans %= MOD ;
        }
    }
    cout << ans << endl ;
    return 0;
}
/*2 270030023747
891135146290 437305641972
30021858
*/
