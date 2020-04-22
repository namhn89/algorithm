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
const ll LNF = 9e18;
const int INF = 1e9 + 10 ;
ll p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
ll ans, n ;
void dfs(int pos , ull res, ull num)
{
    if(num > n ) return ;
    if(num == n && ans > res )
    {
        ans = res ;
        return ;
    }
    FORE(i, 1, 63 )
    {
        if(ans/p[pos] < res ) break ;
        res *= p[pos];
        dfs(pos + 1, res, num *(i+1) );
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans = LNF ;
    cin >> n ;
    dfs(0,1,1);
    cout << ans << endl;

    return 0;
}
