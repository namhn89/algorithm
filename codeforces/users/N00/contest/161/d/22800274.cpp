using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 5e4 + 5 ;
const int MAXDIST = 5e2 + 10;
vector <int> g[MAXN] ;
long long dp[MAXN][MAXDIST] ;
int n, k ;
long long ans ;
void DFS (int u, int parent )
{
    dp[u][0] = 1 ;
    TR(g[u] , it)
    {
        if (*it == parent) continue ;
        DFS(*it , u) ;
        FORE(i , 1 , k ) ans += dp[u][i - 1] * dp[*it][k - i] ;
        FORE(i , 1 , k ) dp[u][i] += dp[*it][i - 1] ;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k ;
    ans = 0 ;
    FORE(i , 1 , n - 1)
    {
        int u, v ;
        cin >> u >> v ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    DFS(1 , 0) ;
    cout << ans << endl;

    return 0;
}
