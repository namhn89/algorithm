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

const ll mod = 1e15 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;

ll n ;

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
    ll data[5][5];

    Matrix (ll a = 0, ll b = 0, ll c = 0, ll n = 0 ,ll d = 0, ll e = 0, ll f = 0, ll m = 0 , ll i = 0, ll j = 0, ll k = 0, ll t = 0 , ll l = 0 , ll x = 0 , ll y = 0 , ll z = 0 )
    {
        data[1][1] = a,data[1][2] = b,data[1][3] = c,data[1][4] = n;
        data[2][1] = d,data[2][2] = e,data[2][3] = f,data[2][4] = m;
        data[3][1] = i,data[3][2] = j,data[3][3] = k,data[3][4] = t;
        data[4][1] = l,data[4][2] = x,data[4][3] = y,data[4][4] = z ;

    }

    Matrix operator * (Matrix b)
    {
        Matrix res;
        Matrix a = *this;
        FORE (x, 1, 4)
        {
            FORE (y, 1, 4)
            {
                FORE (z, 1, 4)
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
    cin >> T ;
    while(T--)
    {
        cin >> n ;
        if (n == 1) cout << 1 << endl;
        if (n == 2) cout << 3 << endl;
        if (n == 3) cout << 6 << endl;
        if (n > 3)
        {
            Matrix res = Matrix(1, 2, 3, 3, 0, 0, 0, 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 );
            Matrix base = Matrix(0, 0, 1, 0, 1, 0, 1, 0, 0 , 1 , 1 , 1 , 0 , 0 , 0 , 1);
            base = base.power(n - 2);
            res = res * base ;
            cout << res.data[1][4] << endl;
        }
    }

    return 0;
}
