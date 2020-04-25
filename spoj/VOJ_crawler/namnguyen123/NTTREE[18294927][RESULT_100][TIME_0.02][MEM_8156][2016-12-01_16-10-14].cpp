using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORD(i,a,b) for(long long i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(long long i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
typedef pair < pair <long long, long long>, long long> III ;
const long long MOD = 1e9 + 7 ;
const long long MAXN = 1e5 + 5 ;
vector <long long> g[MAXN] ;
III Edge [MAXN] ;
long long nChild[MAXN] ;
void DFS (long long u, long long parent)
{
    TR(g[u], it)
    {
        if (*it == parent) continue;
        DFS(*it , u) ;
        nChild[u] += nChild[*it] ;
    }
}
int main()
{
#define TASK "NTTREE"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    long long n ;
    scanf("%d",&n) ;
    FORE(i , 0 , n - 2)
    {
        long long u, v, w ;
        scanf("%lld %lld %lld",&u, &v, &w) ;
        Edge[i].st.st = u ;
        Edge[i].st.nd = v ;
        Edge[i].nd = w ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    FORE(i , 0 , n - 1 ) nChild[i] = 1 ;
    DFS(0, -1 ) ;
    long long ans = 0 ;
    FORE(i , 0 , n - 2){
       long long u = Edge[i].st.st ;
       long long v = Edge[i].st.nd ;
       long long w = Edge[i].nd ;
       ans +=  w * (n - min(nChild[u] , nChild[v])) * min(nChild[u] , nChild[v]) ;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
5
0 1 1
0 2 2
2 3 4
2 4 3
*/
