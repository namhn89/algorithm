using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair < int , int > II ;
typedef pair < int , II > III ;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int n, m ;
vector <III> edge ;
int par[MAXN] ;
int getRoot (int p )
{
    if (par[p] == p) return p;
    else return par[p] = getRoot(par[p]) ;
}
void join (int u, int v)
{
    par[getRoot(u)] = getRoot(v) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &m ) ;
    FORE(i , 1 , n ) par[i] = i ;
    FORE(i , 1 , m )
    {
        int u , v , w ;
        scanf("%d %d %d", &u , &v , &w) ;
        edge.push_back(III(w , II(u , v))) ;
    }
    sort(edge.begin() , edge.end()) ;
    vector <III> ::iterator it  ;
    int ans = 0 ;
    for(it = edge.begin() ; it != edge.end() ; ++it )
    {
        int u = (it -> nd ).st ;
        int v = (it -> nd ).nd ;
        int w = (it -> st ) ;
        if ( getRoot(u) != getRoot(v) )
        {
            join(u , v) ;
            ans = max(ans , w) ;
        }
    }
    printf("%d", ans) ;

    return 0;
}
