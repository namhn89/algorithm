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
const int MAXN = 1e3 + 10 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
int a[MAXN][MAXN];
int dp[2][MAXN][MAXN];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", a[i] + j);
    int ans = 0;
    for (int k = 0; k <= 1; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (a[i][j] == k)
                {
                    dp[k][i][j] = min(dp[k][i - 1][j - 1], min(dp[k][i - 1][j], dp[k][i][j - 1])) + 1;
                    ans = max(ans, dp[k][i][j]);
                }
    printf("%d", ans);
}
