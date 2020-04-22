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
const int MAXN = 1e6 + 5 ;
const int N = 1e6 + 1 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
double f[MAXN], S[MAXN] ;

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(6) << fixed;
    f[0] = 0 ;
    FORE(i , 1 , N )  f[i] = f[i - 1] + 1.0 / double(i) ;
    FORE(i , 3 , N )
    {
        S[i] = 1.0 / double(i) * f[i - 1] ;
        if (i % 2 == 0) S[i] -= 2.0 / double (i * i);
    }
    for(int i = 2 ; i <= N ; ++i )
    {
        for(int j = 2 * i ; j <= N; j += i)
        {
            double t = 1.0 * double(j/i) * double(j/i) ;
            S[j] -= S[i] * 1.0 / t ;
        }
    }
    FORE(i , 2 , N ) S[i] += S[i-1] + 0.5 ;

    int n ;
    while (cin >> n) cout << S[n] << endl;
    return 0;
}
