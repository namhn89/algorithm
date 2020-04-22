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

const int MOD = 1e9 + 7 ;
const int MAXN = 2e7 + 5 ;
const int X = 1e6 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll powmod(ll a, ll n, ll mod)
{
    ll r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % mod ;
        a= ( a * a ) % mod ;
        n >>=1 ;
    }
    return r;
}
long long M, A, a, b, c, d, BASE ;
long long T[MAXN] ;
long long F1[MAXN] ;
long long F[MAXN] ;
long long pre[MAXN], suf[MAXN] ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> A >> a >> b >> c >> d >> BASE ;
    T[1] = a ;
    FORE(i, 2, M ) T[i] =  ( T[i-1] * b + c ) % d ;
    F[0] = 1 ;
    FORE(i, 1, X ) F[i] =  (F[i-1] * A ) % BASE ;
    long long B = powmod(A , X , BASE );
    F1[0] = 1 ;
    FORE(i, 1, X ) F1[i] = (F1[i-1] * B ) % BASE ;
    FORE(i, 1, M )
    {
        pre[i] = T[i] / X ;
        suf[i] = T[i] % X ;
    }
    ll ans = 0 ;
    FORE(i, 1, M )
    {
        ans += (F1[pre[i]] * F[suf[i]]) % BASE ;
        ans %= BASE ;
    }
    cout << ans << endl ;



    return 0;
}
