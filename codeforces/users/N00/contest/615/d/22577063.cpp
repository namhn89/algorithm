using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
typedef pair <int,int> II ;
int N ;
int P[MAXN] ;
long long power(long long a, long long n)
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d",&N) ;
    FORE(i, 1, N ) scanf("%d", &P[i]) ;
    sort(P + 1, P + N + 1) ;
    int j = 1  ;
    vector < II > fact ;
    P[N + 1] = -1 ;
    FORE(i , 2 , N + 1)
    {
        if (P[i] != P[i-1])
        {
            fact.push_back( II(P[i - 1], i - j) );
            j = i ;
        }
    }
    long long ans = 1 ;
    long long D = 1 ;
    for(int i = 0 ; i < fact.size() ; ++i )
    {
        long long p = fact[i].st ;
        long long p_pow = fact[i].nd ;
        long long fP = power(p , ( p_pow + 1 ) * p_pow / 2 ) ;
        ans = ( power(ans , p_pow + 1 ) * power(fP, D) ) % MOD ;
        D *= (p_pow + 1) ;
        D %= (MOD - 1) ;
    }
    printf("%lld", ans);


    return 0;
}
