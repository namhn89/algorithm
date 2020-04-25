using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 9 ;
const int MAXN = 1e5 + 5 ;
map <int, int> fA ;
map <int, int> fB ;
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
void sub1 ()
{
    if (N == M && K == 1) cout << 0 << endl;
}
void sub2 ()
{
    map <int,int > ::iterator it ;
    long long res = 1 ;
    for(it = fB.begin() ; it != fB.end() ; ++it)
    {
        int Q_pow = it -> nd ;
        int P_pow = fA[it -> st] ;
        if (P_pow != Q_pow)
        {
            res *= 2 ;
            res %= MOD;
        }
    }
    cout << res << endl;
}
int main()
{
#define TASK "SKPV15_5"
   // freopen(TASK".inp","r",stdin);
  //  freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N >> K ;
    FORE(i, 1, M )
    {
        int x ;
        cin >> x ;
        factorial_P(x) ;
    }
    FORE(i, 1, N )
    {
        int x ;
        cin >> x ;
        factorial_Q(x) ;
    }
    if (N == M )
    {
        sub1();
        return 0 ;
    }
    else if (K == 2)
    {
        sub2() ;
        return 0 ;
    }
    return 0;
}
