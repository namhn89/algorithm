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
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll power(ll a, ll b)
{
    ll res = 1 ;
    FORE(i, 1, b  ) res*=a ;
    return res ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T ;
    cin >> T ;
    int TN = 0 ;
    while(T--)
    {
        TN++;
        ll L, R ;
        cin >> L >> R ;
        int ans = 1 ;
        if (L == R )
        {
            FORE(k, 2, 64 )
            {
                ll t = ceil(exp(log(R)/k)) ;
                ll x = floor(exp(log(R)/k)) ;
                //cout << t << endl;
                if (power(t,k) == R || power(x,k) == R)
                {
                    ans = max(ans,k);
                }
            }
            cout << "Case #" << TN << ": " << ans << endl;
        }
        else
        {
            FORE(k, 2, 64 )
            {
                //  ll left = ceil(kth_root_finder(l,k));
                //  ll right = ll(kth_root_finder(r,k));
                ld x1 = ceil(exp(log(L)/k));
                ld x2 = floor(exp(log(R)/k));
                //cout << x1 << " " << x2 << endl;
                if (x1 <= x2)
                {
                    ans = max(ans,k);
                }
            }
            cout << "Case #" << TN << ": " << ans << endl;
        }
    }

    return 0;
}
