using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
long long Tree[8 * MAXN], lazy[8 * MAXN] ;
void push_down (int node , int ll , int rr )
{
    if (lazy[node] == 0) return ;
    Tree[node] += lazy[node] ;
    if (ll != rr )
    {
        lazy[2 * node] += lazy[node] ;
        lazy[2 * node + 1] += lazy[node] ;
        lazy[node] = 0 ;
    }
}
void update (int node , int l , int r , int u , int v , int val )
{
    push_down(node, l, r) ;
    if (r < u || v < l || l > r) return ;
    if (u <= l && r <= v )
    {
        Tree[node] += val  ;
        if(l == r) return ;
        lazy[2 * node] += val ;
        lazy[2 * node + 1] += val ;
    }
    else
    {
        int mid = (l + r) / 2 ;
        update(node * 2, l, mid, u, v, val) ;
        update(node * 2 + 1, mid + 1, r, u, v, val) ;
        Tree[node] = max(Tree[node * 2], Tree[node * 2 + 1]) ;
    }
}
long long query (int node, int l, int r, int u, int v)
{
    push_down(node, l, r) ;
    if (r < u || v < l || l > r) return 0 ;
    if (u <= l && r <= v && l <= r ) return Tree[node] ;
    int mid = (l + r) / 2 ;
    return max( query(node * 2 , l , mid , u , v ) , query(node * 2 + 1 , mid + 1 , r , u , v) ) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m ;
    cin >> n >> m ;
    while(m--){
        int type ;
        cin >> type ;
        if (type == 0 ) {
             int u , v , k ;
             cin >> u >> v >> k ;
             update(1 , 1 , n , u , v , k) ;
        }
        else {
            int u , v ;
            cin >> u >> v ;
            cout << query(1 , 1 , n , u , v) << endl;
        }
    }
    return 0;
}
