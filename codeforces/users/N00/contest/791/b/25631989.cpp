using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 3e5 + 5 ;
int n, m, nscc ;
int cnt[MAXN] , edge[MAXN] , par[MAXN] ;
int findSet (int p)
{
    if(par[p] == p) return p ;
    else return par[p] = findSet(par[p]) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; ++i ) cnt[i] = 1, par[i] = i ;
    for(int i = 1 ; i <= m ; ++i )
    {
        int u, v ;
        cin >> u >> v ;
        int x = findSet(u), y = findSet(v) ;
        if (x != y)
        {
            if(cnt[x] < cnt[y]) swap(x , y) ;
            par[y] = x ;
            cnt[x] += cnt[y] ;
            edge[x] += edge[y] + 1 ;
        }
        else edge[x]++;
    }
    for(int i = 1 ; i <= n ; ++i )
    {
        //cout << cnt[i] << " " << edge[i] << endl;
        if (par[i] != i) continue ;
        if (cnt[i] <= 2) continue ;
        if (edge[i] != 1LL * cnt[i] * (cnt[i] - 1) / 2)
        {
            cout << "NO" << endl;
            return 0 ;
        }
    }
    cout << "YES" << endl;
    return 0;
}
