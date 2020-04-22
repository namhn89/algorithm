using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
const int oo = 2e9 ;
int a[MAXN] , Tree[4 * MAXN] , n , m , q ;
void build (int node , int l , int r)
{
    if (l == r)
    {
        Tree[node] = a[l] ;
        return ;
    }
    int mid = (l + r) / 2 ;
    build(node * 2, l, mid) ;
    build(node * 2 + 1, mid + 1, r) ;
    Tree[node] = max(Tree[node * 2], Tree[node * 2 + 1]) ;
}
int get (int node, int l, int r, int u, int v)
{
    if (v < l || r < u) return -oo ;
    if (u <= l && r <= v) return Tree[node] ;
    int mid = (l + r) / 2 ;
    return max(get(node * 2, l, mid, u, v), get(node * 2 + 1, mid + 1, r, u, v)) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n, &m) ;
    for(int i = 1 ; i <= m ; ++i)
    {
        int u , v , k ;
        scanf("%d %d %d", &u, &v, &k) ;
        a[v + 1] -= k ;
        a[u] += k ;
    }
    for(int i = 1 ; i <= n ; ++i) a[i] += a[i - 1] ;
    build(1 , 1 , n ) ;
    scanf("%d",&q) ;
    while(q--)
    {
        int u, v ;
        scanf("%d %d", &u, &v) ;
        printf("%d\n", get(1 , 1 , n , u , v)) ;
    }

    return 0;
}
