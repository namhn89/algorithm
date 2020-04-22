using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int par[MAXN] ;
int u[MAXN], v[MAXN] ;
int N, M, Q ;
int Clear[MAXN], id[MAXN], cnt ;
int findSet (int u)
{
    if (par[u] == u) return par[u] ;
    else return par[u] = findSet(par[u]) ;
}
void Union (int u, int v)
{
    int x = findSet(u) ;
    int y = findSet(v) ;
    if (x != y)
    {
        par[y] = x ;
        cnt-- ;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Q ;
    cnt = N ;
    for(int i = 1 ; i <= N ; ++i ) par[i] = i ;
    for(int i = 1 ; i <= M ; ++i ) cin >> u[i] >> v[i] ;
    for(int i = 1 ; i <= Q ; ++i )
    {
        cin >> id[i] ;
        Clear[id[i]] = 1 ;
    }
    for(int i = 1 ; i <= M ; ++i)
    {
        if (!Clear[i]) Union(u[i], v[i]) ;
    }
    vector <int> ans;
    for(int i = Q ; i >= 1 ; --i )
    {
        ans.push_back(cnt) ;
        Union(u[id[i]] , v[id[i]]) ;
    }
    reverse(ans.begin() , ans.end()) ;
    TR(ans , it) cout << *it << endl;

    return 0;
}
