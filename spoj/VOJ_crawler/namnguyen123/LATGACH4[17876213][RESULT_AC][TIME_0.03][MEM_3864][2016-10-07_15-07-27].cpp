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
const int MOD = 111539786 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
map<ll,ll>f;
ll n;
ll fibo(ll x)
{
    ll k = x/2;
    if(f.count(x)) return f[x];
    if(x%2 == 0)return	f[x] = (fibo(k)*fibo(k)+fibo(k-1)*fibo(k-1))%MOD;
    else return	f[x] = (fibo(k-1)*fibo(k)+fibo(k)*fibo(k+1))%MOD;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f[0]=1;
    f[1]=1;
    int T ;
    cin >> T ;
    while(T--)
    {
        cin >> n;
        cout<< fibo(n)% MOD << endl;
    }

    return 0;
}
