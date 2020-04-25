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
const int MAXN = 2e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
int f[MAXN];
void sang()
{
    FORE(i, 2,sqrt(MAXN))
    {
        if (!f[i])
        {
            for(int j = 2*i ; j <= MAXN ; j += i)
            {
                f[j] = 1;
            }
        }
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sang();
    int a, b ;
    cin >> a >> b ;
    FORE(i, a, b )
    {
        if (i > 1)
        {
            if (!f[i]) cout << i << endl;
        }
    }

    return 0;
}
