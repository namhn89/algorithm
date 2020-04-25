using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 1 ;
const int INF = 1e9 + 1 ;
ll n, m, k ;
int sz ;
ll f[MAXN];
struct t
{
    int x, y, z ;
};
t a[MAXN];
bool cmp(const t &a, const t &b)
{
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
void co()
{
    vector< ll > x;
    map< ll, ll > m;
    FORE(i, 1, k) x.push_back(a[i].y);
    sort(x.begin(), x.end());
    x.resize(distance(x.begin(), unique(x.begin(), x.end())));
    sz = x.size();
    FORE(i, 0, x.size()-1)
    {
        m[x[i]] = i + 1;
    }
    FORE(i, 1, k) a[i].y = m[a[i].y];
}
ll getf(ll i)
{
    ll res = 0 ;
    while (i > 0 )
    {
        res = max(f[i], res);
        i -= (i & (-i));
    }
    return res ;
}
void change (ll v, ll value)
{
    while(v <= sz )
    {
        f[v] =  max(f[v], value) ;
        v += (v & (-v));
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    cin >> n >> m >> k ;
    FORE(i, 1, k )
    {
        cin >> a[i].x >> a[i].y >> a[i].z ;
    }
    sort( a + 1, a + k + 1, cmp );
    co();
    ll ans = 0 ;
    FORE(i, 1, k )
    {
        ll t = getf(a[i].y);
        ans = max(ans, t + a[i].z);
        change(a[i].y, t + a[i].z);
    }
    cout << ans << endl;

    return 0;
}
