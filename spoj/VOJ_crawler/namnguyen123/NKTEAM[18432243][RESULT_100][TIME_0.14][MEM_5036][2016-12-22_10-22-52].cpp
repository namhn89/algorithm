using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
struct data
{
    int a, b, c ;
    data () {}
    data (int a, int b, int c) : a(a), b(b), c(c) {} ;
    bool operator < (const data &e) const
    {
        if(a != e.a ) return a < e.a ;
        if(b != e.b ) return b < e.b ;
        return c < e.c ;
    }
} x[MAXN] ;
int n ;
int Tree[MAXN] ;
int getTree(int u)
{
    int res = n + 1 ;
    while(u > 0)
    {
        res = min(res, Tree[u]) ;
        u -= u & (-u) ;
    }
    return res;
}
void update (int u, int value )
{
    while(u <= n)
    {
        Tree[u] = min(Tree[u], value) ;
        u += u & (-u) ;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d",&n) ;
    FORE(i , 1 , n) Tree[i] = n + 1 ;
    int u ;
    FORE(i , 1 , n) scanf("%d",&u) , x[u].a = i ;
    FORE(i , 1 , n) scanf("%d",&u) , x[u].b = i ;
    FORE(i , 1 , n) scanf("%d",&u) , x[u].c = i ;
    sort(x + 1, x + n + 1) ;
    int ans = 0 ;
    FORE(i , 1 , n )
    {
        int value = getTree(x[i].c) ;
        if (value > x[i].b ) ans++;
        update(x[i].c , x[i].b) ;
    }
    printf("%d\n", ans) ;

    return 0;
}
