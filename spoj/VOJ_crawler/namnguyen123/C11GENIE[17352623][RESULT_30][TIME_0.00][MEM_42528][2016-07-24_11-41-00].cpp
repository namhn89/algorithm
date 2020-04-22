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
const int MAXN = 1e7 + 5 ;
int f[MAXN];
vector <int> b ;
void sang(int n )
{
    for (int i = 2; i < n ; i++)
    {
        if (f[i]==0)
        {
            b.push_back(i);
            for (int j=2; j*i<= n; j++)
                f[i*j] = 1;
        }
    }
}
ll power(ll b, ll p)
{
    if (!p)
        return 1;
    if (p == 1)
        return b % MOD;
    ll ret = pow(b , p >> 1);
    ret = (ret * ret) % MOD;
    if (p & 1)
        ret = (ret * b) % MOD;
    return ret % MOD;
}
ll get (ll p, ll n)
{
    ll res = 0;
    ll t = p;
     while(t <= n)
    {
        res += n/t ;
        t *= p;
    }
    return res;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int n ;
    cin >> n ;
    sang(n);
    ll res = 1 ;
    FOR(i , 0 , b.size()){
        res = res * power(b[i],get(b[i],n)&~1);
    }
    printf("%lld\n",res);

    return 0;
}
