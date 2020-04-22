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
const int MAXN = 3e4 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
vector <int> b ;
int f[MAXN];
int t[MAXN];
int t2[MAXN];
int n, p ;
ll get(int p, int n)
{
    ll res = 0 ;
    while(n)
    {
        res+=n/p;
        n/=p;
    }
    return res ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    b.push_back(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p ;
    ll ans = LNF;
    FORE(i, 2, sqrt(p))
    {
        if (p % i ==0)
        {
            ll cnt = 0 ;
            while (p % i == 0 )
            {
                cnt++;
                p/=i;
            }
            ans = min(ans ,get(i,n)/cnt);
        }
    }
    if (p > 1 ) ans = min(ans,get(p,n));
    cout << ans << endl;
    return  0;
}
