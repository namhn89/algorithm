using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
struct DSU
{
    int par[MAXN], cnt[MAXN] ;
    void refine (int n)
    {
        for(int i = 1 ; i <= n ; ++i ) par[i] = i, cnt[i] = 1 ;
    }
    int findSet (int p)
    {
        if (par[p] == p) return p ;
        else return par[p] = findSet(par[p]) ;
    }
    void Union (int u, int v)
    {
        int x = findSet(u), y = findSet(v) ;
        if (y > x) swap(x, y);
        par[x] = y ;
        cnt[y] += cnt[x] ;
    }
};
int n, m ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m ;
    DSU a;
    a.refine(n) ;
    for(int i = 1 ; i <= m ; ++i )
    {
        int u , v ;
        cin >> u >> v ;
        a.Union(u , v) ;
    }
    if (n == m)
    {
        for(int i = 1 ; i <= n ; ++i )
        {
            if (a.par[i] == i && i != 1)
            {
                cout << "NO" << endl;
                return 0 ;
            }
        }
        cout << "FHTAGN!";
    }
    else cout << "NO";
    return 0;
}