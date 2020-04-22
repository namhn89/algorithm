using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int par[MAXN] , n , m ;
vector < pair <int , pair <int , int> > > Edeges ;
int findSet (int p)
{
    if (par[p] == p) return par[p] ;
    else return par[p] = findSet(par[p]) ;
}
void join (int u, int v)
{
    int x = findSet(u), y = findSet(v) ;
    par[y] = x ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d",&n,&m) ;
    for(int i = 1 ; i <= n ; ++i) par[i] = i ;
    for(int i = 1 ; i <= m ; ++i)
    {
        int u, v, w ;
        scanf("%d %d %d", &u, &v, &w) ;
        Edeges.push_back(make_pair(w, make_pair(u, v))) ;
    }
    sort(Edeges.begin(), Edeges.end()) ;
    long long ans = 0 ;
    TR(Edeges, it)
    {
        int w = it -> st ;
        int u = (it -> nd).st ;
        int v = (it -> nd).nd ;
        if (findSet(u) == findSet(v)) continue ;
        join(u , v) ;
        ans += w ;
    }
    cout << ans << endl;
    return 0;
}
