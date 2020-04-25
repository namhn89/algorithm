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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

inline void read (int &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e5 + 3 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
const int M = 1e5 + 4 ;
long long fact[MAXN], infact[MAXN] ;
long long n, m ;
vector< int > getRepresentation(long long N, int M)
{
    vector< int > res;
    while (N > 0)
    {
        res.push_back(N % M);
        N /= M;
    }
    return res;
}
long long powmod(long long a, long long n)
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
long long C(int N, int K)
{
    ll res = (fact[N] % MOD ) * (infact[N - K] % MOD) * (infact[K] % MOD ) % MOD;
    res %= MOD ;
    return res ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    int Test ;
    read(Test);
    fact[0] = 1 ;
    infact[0] = 1 ;
    FORE(i, 1, M ) fact[i] = (fact[i-1] * i) % MOD ;
    FORE(i, 1, M ) infact[i] = powmod(fact[i], MOD - 2);
    while(Test --)
    {
        cin >> m >> n ;
        if (m < 2*n - 1)
        {
            cout << 0 << endl;
        }
        else
        {
            m -= (2 * n - 1);
            long long N = n + m ;
            long long K = n ;
            vector<int> x = getRepresentation(N,MOD);
            vector<int> y = getRepresentation(K,MOD);
            while(x.size() < y.size())x.push_back(0);
            while(y.size() < x.size())y.push_back(0);
             //TR(x,it) cout << *it <<" ";cout << endl;
            // TR(y,it) cout << *it <<" ";cout << endl;
            long long res = 1;
            for (int i = 0; i < x.size() ; ++i)
            {
                res = ( res * C(x[i], y[i]) ) % MOD ;
            }
            cout << res << endl;
        }
    }



    return 0;
}
