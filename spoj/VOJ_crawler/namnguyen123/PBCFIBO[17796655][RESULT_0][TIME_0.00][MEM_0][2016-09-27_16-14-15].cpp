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
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll MOD ;
map<ll,ll>f;
ll n , t ;
ll fibo(ll x)
{
    ll k = x/2;
    if(f.count(x)) return f[x];
    if(x%2 == 0)return	f[x] = (fibo(k)*fibo(k)+fibo(k-1)*fibo(k-1))%MOD;
    else return	f[x] = (fibo(k-1)*fibo(k)+fibo(k)*fibo(k+1))%MOD;
}
int main()
{
    f[0] = 1 ;
    f[1] = 1 ;
    cin >> n >> MOD >> t ;
    cout << fibo(t) % MOD << endl;

    return 0 ;
}
