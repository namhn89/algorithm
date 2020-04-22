using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e5+5;
int a[MAXN];
ll c ;
ll pow(ll b, ll p, ll m)
{
    if (!p)
        return 1;
    if (p == 1)
        return b % m;
    ll ret = pow(b, p >> 1, m);
    ret = (ret * ret) % m;
    if (p & 1)
        ret = (ret * b) % m;
    return ret % m;
}
ll phi(ll n)
{
    ll result = n;
    for (ll i=2; i*i<=n; ++i)
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    string a ;
    string b ;
    cin >> a >> b >> c ;
    ll x = 0 ;
    FORE(i, 0, a.size() - 1 )
    {
        x = (x * 10 + (a[i] - '0'))%c ;
    }
    ll d = phi(c);
    ll k = 0 ;
    FORE(i, 0,b.size() - 1 )
    {
        k = (k * 10 + (b[i] - '0'))%d ;
    }
    ll ans = pow(x , k  , c) ;
    cout << ans << endl;




    return 0;
}
