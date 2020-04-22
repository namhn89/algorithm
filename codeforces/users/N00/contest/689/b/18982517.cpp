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
const int MAXN = 2e5 + 5 ;
vector < int > g[MAXN];
int res[MAXN];
int a[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int n ;
    cin >> n ;
    FORE(i, 1, n )
    {
        cin >> a[i];
        if (i > 1 ) g[i].push_back(i - 1);
        if (i < n ) g[i].push_back(i + 1);
        g[i].push_back(a[i]);
    }
    queue <int> q;
    res[1] = 1 ;
    q.push(1);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        FOR(i, 0, g[u].size())
        {
            int v = g[u][i];
            if(res[v] != 0) continue;
            res[v] = res[u] + 1;
            q.push(v);
        }
    }
    FORE(i,1, n) cout << res[i] - 1 << " ";




    return 0;
}