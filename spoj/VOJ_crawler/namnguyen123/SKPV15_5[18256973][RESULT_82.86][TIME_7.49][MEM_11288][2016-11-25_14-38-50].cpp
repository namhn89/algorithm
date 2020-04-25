using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 9 ;
const int MAXN = 1e6 + 5 ;
const int NX = 1e6 + 1 ;
int fA[MAXN], fB[MAXN] ;
int N, M, K ;
void factorial_P(int n)
{
    for(int i = 2 ; i * i <= n ; ++i )
    {
        if(n % i == 0 )
        {
            while(n % i == 0 )
            {
                n /= i ;
                fA[i] ++ ;
            }
        }
    }
    if (n > 1) fA[n] ++;
}
void factorial_Q(int n)
{
    for(int i = 2 ; i * i <= n ; ++i )
    {
        if(n % i == 0 )
        {
            while(n % i == 0 )
            {
                n /= i ;
                fB[i] ++ ;
            }
        }
    }
    if (n > 1) fB[n] ++;
}
long long power(long long a, long long n)
{
    long long r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % MOD;
        a = ( a * a ) % MOD ;
        n >>= 1 ;
    }
    return r;
}
void calc()
{
    long long res = 1 ;
    for(int i = 2 ; i <= NX ; ++i)
    {
        long long H = fB[i] - fA[i] ;
        if (H < 0)
        {
            res = 0 ;
            break;
        }
        if (H == 1 )
        {
            res *= (power(2, K ) - 2 ) ;
            res %= MOD ;
        }
        else if (H > 1)
        {
            res *=  ( (power(H + 1, K ) - 2 * power(H, K) + power(H - 1, K) + MOD) % MOD );
            res %= MOD ;
        }
    }
    printf("%lld\n", res);
}
int main()
{
#define TASK "GCDLCM"
   // freopen(TASK".inp","r",stdin);
  //  freopen(TASK".out","w",stdout);
    scanf("%d %d %d", &M, &N, &K );
    FORE(i, 1, M )
    {
        int x ;
        scanf("%d",&x);
        factorial_P(x) ;
    }
    FORE(i, 1, N )
    {
        int x ;
        scanf("%d",&x);
        factorial_Q(x) ;
    }
    if (N == M && K > 1)
    {
        printf("0\n");
        return 0 ;
    }
    else if (K == 1) {
        cout << 1 << endl;
        return 0 ;
    }
    calc();
    return 0;
}

