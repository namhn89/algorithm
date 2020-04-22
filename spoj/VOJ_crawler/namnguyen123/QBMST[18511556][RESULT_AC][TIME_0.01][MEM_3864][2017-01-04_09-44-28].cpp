using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
struct data
{
    int u, v, w ;
    data (int u, int v, int w) : u(u), v(v), w(w) {} ;
    bool operator < (const data &other) const
    {
        if (w != other.w) return w < other.w  ;
        else if (u != other.u) return u < other.u ;
        else return v < other.v ;
    }
};
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int par[MAXN] ;
int n, m;
vector < data > edge ;
int getRoot (int p)
{
    if (par[p] == p) return p ;
    else return par[p] = getRoot(par[p]) ;
}
void join (int p, int q)
{
    par[getRoot(p)] = getRoot(q) ;
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
        int u, v, w ;
        scanf("%d %d %d",&u,&v,&w) ;
        edge.push_back(data(u, v, w)) ;
    }
    sort(edge.begin(), edge.end()) ;
    long long ans = 0 ;
    TR(edge, it)
    {
        int u = it -> u ;
        int v = it -> v ;
        int w = it -> w ;
        if (getRoot(u) != getRoot(v))
        {
            join(u, v) ;
            ans += w ;
        }
    }
    printf("%lld\n",ans) ;
    return 0;
}
