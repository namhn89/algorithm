using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int par[MAXN] , cnt[MAXN] , n , m , a[MAXN] ;
int anc (int p )
{
    if (par[p] == p ) return p ;
    else return par[p] = anc(par[p]) ;
}
typedef vector < pair <int , pair<int ,int> > > VII ;
VII Edges ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i] ;
    for(int i = 1 ; i <= n ; ++i ) par[i] = i , cnt[i] = 1 ;
    for(int i = 1 ; i <= m ; ++i )
    {
        int u, v ;
        cin >> u >> v ;
        Edges.push_back(make_pair(min(a[u] , a[v]) , make_pair(u , v) ) ) ;
    }
    sort(Edges.begin() , Edges.end()) ;
    reverse(Edges.begin() , Edges.end());
    long long ans = 0 ;
    for(int i = 0 ; i < Edges.size() ; ++i )
    {
        int w = Edges[i].st ;
        int u = Edges[i].nd.st ;
        int v = Edges[i].nd.nd ;
        int par_u = anc(u) , par_v = anc(v) ;
      //  cout << u << " " << v << " " << w << endl ;
      //  cout << par_u << " " << par_v << endl;
        if (par_u != par_v)
        {
            if (cnt[par_u] < cnt[par_v]) swap(par_u , par_v) ;
            ans += 1LL * w * cnt[par_u] * cnt[par_v] ;
           // cout << w << " " << cnt[par_u] << " " << cnt[par_v] << endl;
            cnt[par_u] += cnt[par_v] ;
            par[par_v] = par_u ;
        }
       // cout << endl;
    }
   // cout << ans << endl;
    long double res = 2.0 * ans / ( 1.0 * n * (n - 1) ) ;
    cout << fixed << setprecision(7) << res << endl;
    return 0;
}
