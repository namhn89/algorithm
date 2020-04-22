using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll ;
const int MOD = 1e6 + 3 ;
const int MAXN = 1e6 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
const int M = 1e6 + 4 ;

long long fact[MAXN], infact[MAXN] ;
long long n , m , k ;

long long powmod (long long a , long long n)
{
    ll r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % MOD ;
        a = ( a * a ) % MOD ;
        n >>= 1 ;
    }
    return r;
}
long long C(int N , int K)
{
    if (K > N) return 0 ;
    ll res = (fact[N] * infact[N - K]) % MOD * (infact[K] % MOD ) % MOD;
    res %= MOD ;
    return res ;
}
int main()
{
    #define TASK "CANDY"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    fact[0] = 1 ;
    infact[0] = 1 ;
    FORE(i , 1 , M ) fact[i] = (fact[i - 1] * i) % MOD ;
    FORE(i , 1 , M ) infact[i] = powmod(fact[i] , MOD - 2);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k ;
    cout << C(n + k , n) - 1 << endl;


    return 0;
}
