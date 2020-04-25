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
const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
int n, m ;
ll power [22], cnt [MAXN];
int rev (int x)
{
    int ret = 0;
    while (x)
    {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}
int revLen (int x, int len)
{
    int ret = 0;
    while (len--)
    {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}
int main ()
{
    //freopen("bipal.inp","r",stdin);
    //freopen("bipal.out","w",stdout);
    power[0] = 1 ;
    FOR(i, 1, 10 ) power [i] = power [i - 1] * 10;
    cin >> n >> m;
    int len = (n / 2 + 1) / 2;
    for (int i = 0; i < power [len]; ++i)
    {
        ll tmp = revLen (i, len);
        if (n / 2 % 2) tmp += 1ll * ( i / 10) * power [len];
        else tmp += 1ll * i * power [len];
       // cout << i << " " << tmp << endl;
        tmp %= m;
        cnt[tmp] ++;
    }
    ll res = 0;
    for (int i = power [len - 1]; i < power [len]; ++i)
    {
        ll tmp = rev (i);
        if (n / 2 % 2) tmp +=  (i / 10) * power [len];
        else tmp +=  i * power [len];
        tmp %= m;
        tmp *= power [n / 2];
        tmp %= m;
        res += cnt [(m - tmp) % m];
    }
    cout << res << endl;
}
