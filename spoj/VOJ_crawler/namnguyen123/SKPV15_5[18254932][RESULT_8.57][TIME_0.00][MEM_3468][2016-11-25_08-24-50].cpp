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
    if (n > 0) fA[n] ++;
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
    if (n > 0) fB[n] ++;
}
long long power(long long a, long long n)
{
    long long r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % MOD;
        a = ( a * a ) % MOD ;
        n >>=1 ;
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
    map <int,int > ::iterator it ;
    long long res = 1 ;
    for(it = fB.begin() ; it != fB.end() ; ++it){
        int Q_pow = it -> nd ;
        int P_pow = fA[it -> st] ;
        int ans = Q_pow - P_pow + 1 ;
        long long d = ( power(ans , K) - 2 + MOD) % MOD ;
        res = (res * d) % MOD ;
    }
    cout << res << endl;


    return 0;
}
