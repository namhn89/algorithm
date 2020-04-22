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
map<int,int>f ;
int fib(int n,int MOD)
{
    if (f.count(n)) return f[n];
    else
    {
        int k = n/2;
        if (n % 2 == 0) return f[n] = (fib(k,MOD)*fib(k,MOD)%MOD + fib(k-1,MOD)*fib(k-1,MOD)%MOD)%MOD;
        else return f[n] = (fib(k,MOD)*fib(k+1,MOD)%MOD + fib(k,MOD)*fib(k-1,MOD)%MOD)%MOD;
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T ;
    cin >> T ;
    while(T--)
    {
        int x, MOD ;
        cin >> x >> MOD ;
        f.clear();
        f[0] = 1 ;
        f[1] = 1 ;
       cout << fib(x-1,MOD) << endl;
    }

    return 0;
}
