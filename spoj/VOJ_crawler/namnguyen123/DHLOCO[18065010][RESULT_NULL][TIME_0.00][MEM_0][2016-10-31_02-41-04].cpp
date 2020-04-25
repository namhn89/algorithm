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

//const int mod = 1e15 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;

ll n, mod, k;

ll mul (ll a, ll p, ll mod)
{
    ll res = 0;
    while (p)
    {
        if (p & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        p >>= 1;
    }
    return res;
}

struct Matrix
{
    ll data[4][4];

    Matrix (ll a = 0, ll b = 0, ll c = 0, ll d = 0, ll e = 0, ll f = 0, ll i = 0, ll j = 0, ll k = 0 )
    {
        data[1][1] = a;
        data[1][2] = b;
        data[1][3] = c;
        data[2][1] = d;
        data[2][2] = e;
        data[2][3] = f;
        data[3][1] = i;
        data[3][2] = j;
        data[3][3] = k;

    }

    Matrix operator * (Matrix b)
    {
        Matrix res;
        Matrix a = *this;
        FORE (x, 1, 3)
        {
            FORE (y, 1, 3)
            {
                FORE (z, 1, 3)
                {
                    res.data[x][y] += mul(a.data[x][z], b.data[z][y], mod) % mod;
                    res.data[x][y] %= mod;
                }
            }
        }
        return res;
    }
    Matrix power(ll p)
    {
        Matrix t = *this;
        Matrix res = t;
        p--;
        while (p)
        {
            if (p & 1) res = (res * t);
            t = t * t;
            p >>= 1;
        }
        return res;
    }
};
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T ;
    //cin >> T ;
    //while(T--)
    // {
    cin >> n >> mod ;
    if (n == 1) cout << 1 << endl;
    if (n == 2) cout << 2 << endl;
    if (n == 3) cout << 4 << endl;
    if (n > 3)
    {
        Matrix res = Matrix(1, 2, 4, 0, 0, 0, 0, 0, 0 );
        Matrix base = Matrix(0, 0, 1, 1, 0, 1, 0, 1, 1 );
        base = base.power(n - 3);
        res = res * base ;
        cout << res.data[1][3] << endl;
    }
    //}

    return 0;
}
