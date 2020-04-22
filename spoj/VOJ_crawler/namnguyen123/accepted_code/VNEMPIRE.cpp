using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
pair <int, int > fA[MAXN], fB[MAXN], fC[MAXN] ;
vector < pair <int, pair <int, int> > > Edges ;
int par[MAXN], n, a[MAXN], b[MAXN], c[MAXN] ;
int findSet (int p)
{
    if (par[p] == p ) return p ;
    else return par[p] = findSet(par[p]) ;
}
void Union (int u, int v)
{
    int x = findSet(u), y = findSet(v) ;
    par[x] = y ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i ) par[i] = i ;
    for(int i = 1 ; i <= n ; ++i )
    {
        cin >> a[i] >> b[i] >> c[i] ;
        fA[i].st = a[i] ;
        fB[i].st = b[i] ;
        fC[i].st = c[i] ;
        fA[i].nd = fB[i].nd = fC[i].nd = i ;
    }
    sort(fA + 1, fA + n + 1) ;
    sort(fB + 1, fB + n + 1) ;
    sort(fC + 1, fC + n + 1) ;
    for(int i = 1 ; i < n ; ++i )
    {
        int u = fA[i].nd, v = fA[i + 1].nd ;
        int w = min(abs(a[u] - a[v]), min (abs(b[u] - b[v]), abs(c[u] - c[v]) ) ) ;
        Edges.push_back( make_pair(w, make_pair(u, v) ) ) ;
    }
    for(int i = 1 ; i < n ; ++i )
    {
        int u = fB[i].nd, v = fB[i + 1].nd ;
        int w = min(abs(a[u] - a[v]), min (abs(b[u] - b[v]), abs(c[u] - c[v]) ) ) ;
        Edges.push_back( make_pair(w, make_pair(u, v) ) ) ;
    }
    for(int i = 1 ; i < n ; ++i )
    {
        int u = fC[i].nd, v = fC[i + 1].nd ;
        int w = min(abs(a[u] - a[v]), min (abs(b[u] - b[v]), abs(c[u] - c[v]) ) ) ;
        Edges.push_back( make_pair(w, make_pair(u, v) ) ) ;
    }
    long long ans = 0 ;
    sort(Edges.begin(), Edges.end()) ;
    TR(Edges, it)
    {
        int w = it -> st ;
        int u = (it -> nd).st ;
        int v = (it -> nd).nd ;
        if (findSet(u) != findSet(v))
        {
            ans += w ;
            Union(u, v) ;
        }
    }
    cout << ans << endl;
    return 0;
}
