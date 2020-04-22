using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
struct data
{
    long long Sum, Max ;
    data () {} ;
    data (long long Sum, long long Max ) : Sum(Sum), Max(Max) {}
};
data Tree[4 * MAXN] ;
int a[MAXN], n, q ;
data combine (data Left, data Right )
{
    data res ;
    res.Sum = Left.Sum + Right.Sum ;
    res.Max = max(Left.Max, Right.Max) ;
    return res ;
}
void build (int node, int l, int r )
{
    if(l == r )
    {
        Tree[node] = data(a[l], a[l] ) ;
    }
    else
    {
        int mid = (l + r) / 2 ;
        build(node * 2, l, mid ) ;
        build(node * 2 + 1, mid + 1, r );
        Tree[node] = combine(Tree[node * 2], Tree[node * 2 + 1]);
    }
}
void update1 (int node, int L, int R, int i, int v )
{
    if (L > i || R < i ) return ;
    if (L == R)
    {
        Tree[node] = data(v, v) ;
    }
    else
    {
        int mid = (L + R) / 2 ;
        update1(node * 2 , L , mid, i , v) ;
        update1(node * 2 + 1 , mid + 1, R, i, v) ;
        Tree[node] = combine(Tree[node * 2], Tree[node * 2 + 1]);
    }
}
void update2 (int node, int L, int R, int u, int v, int mod )
{
    if (L > v || R < u ) return ;
    if (L >= u && R <= v )
    {
        if (Tree[node].Max < mod ) return ;
        if (L == R )
        {
            Tree[node].Max %= mod;
            Tree[node].Sum %= mod ;
            return ;
        }
        int mid = (L + R) / 2 ;
        update2(node * 2, L, mid, u, v, mod) ;
        update2(node * 2 + 1, mid + 1, R, u, v, mod );
        Tree[node] = combine(Tree[node * 2], Tree[node * 2 + 1]);
    }
    else
    {
        int mid = (L + R) / 2 ;
        update2(node * 2, L, mid, u, v, mod) ;
        update2(node * 2 + 1, mid + 1, R, u, v, mod );
        Tree[node] = combine(Tree[node * 2], Tree[node * 2 + 1]);
    }
}
long long getSum (int node, int L, int R, int u, int v)
{
    if (L > v || R < u ) return 0 ;
    if (L >= u && R <= v ) return Tree[node].Sum ;
    int mid = (L + R) / 2 ;
    long long res = getSum(node * 2, L, mid, u, v) + getSum(node * 2 + 1, mid + 1, R, u, v) ;
    return res ;
}
int main()
{
    #define TASK "SCMQUERY"
  //  freopen(TASK".inp","r",stdin);
  //  freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &q ) ;
    FORE(i , 1 , n ) scanf("%d", &a[i]);
    build(1 , 1 , n) ;
    while(q--)
    {
        int type ;
        scanf("%d",&type) ;
        if (type == 1 )
        {
            int l, r ;
            scanf("%d %d",&l,&r);
            printf("%lld\n" , getSum(1 , 1 , n , l , r));
        }
        if (type == 3)
        {
            int p , x ;
            scanf("%d %d",&p , &x);
            a[p] = x ;
            update1(1, 1, n, p, x) ;
        }
        if (type == 2)
        {
            int l , r , mod ;
            scanf("%d %d %d",&l , &r ,&mod) ;
            update2(1, 1, n, l, r, mod) ;
        }
    }
    return 0;
}
