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
typedef vector<int> VI ;
typedef vector<II> VII;
const ll MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const ll BASE = 26 ;
ll ha[MAXN];
ll power[MAXN];
ll get(int i, int j)
{
    return (ha[j] - ha[i-1] * power[j-i+1] + MOD*MOD )%MOD;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b ;
    cin >> a;
    cin >> b;
    int n = a.size();
    int m = b.size();
    a = " " + a ;
    b = " " + b ;
    power[0] = 1 ;
    FORE(i, 1, n ) power[i] = (power[i-1] * BASE )% MOD ;
    ha[0] = 0 ;
    FORE(i, 1, n ) ha[i] = (ha[i-1]*BASE + a[i]-'a') % MOD ;
    ll hb = 0 ;
    FORE(i, 1, m ) hb = (hb * BASE + b[i] - 'a') % MOD ;
    FORE(i, 1, n - m + 1 )
    {
        if (hb == get(i, i + m - 1)) cout << i << " ";
    }
    return 0;
}
