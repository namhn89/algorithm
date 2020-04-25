using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int oo = 1e9 + 100 ;
struct data
{
    long long sum, pre, suf, ans ;
    data () {}
    data(long long sum, long long pre, long long suf, long long ans): sum(sum), pre(pre), suf(suf), ans(ans) {}
};
data tree [MAXN * 4];
int n, a[MAXN], q ;
data combine (data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.pre = max(l.pre, l.sum + r.pre);
    res.suf = max(r.suf, r.sum + l.suf);
    res.ans = max( max(l.ans, r.ans), l.suf + r.pre);
    return res;
}
void build(int node = 1, int L = 1, int R = n)
{
    if(L == R)
    {
        tree[node] = data(a[L], a[L], a[L], a[L]);
    }
    else
    {
        long mid = (L + R) / 2;
        build(node*2, L, mid );
        build(node*2 + 1, mid + 1, R);
        tree[node] = combine(tree[node*2], tree[node*2 + 1]);
    }
}
void update (int node, int l, int r, int i, int v)
{
    if (i < l || i > r) return ;
    if (l == r )
    {
        tree[node] = data(v, v, v, v ) ;
    }
    else
    {
        int mid = (l + r) / 2 ;
        update(node * 2, mid, l, i, v );
        update(node * 2 + 1, mid + 1, r, i, v );
        tree[node] = combine(tree[node*2], tree[node*2+1]);
    }
}
data query (int node, int l, int r, int u, int v )
{
    if (l > v || r < u ) return data( 0, -oo, -oo, -oo );
    if (l >= u && r <= v) return tree[node];
    else
    {
        int mid = (l + r) / 2;
        data trai = query( node * 2, l, mid, u, v) ;
        data phai = query( node * 2 + 1, mid + 1, r, u, v);
        return combine (trai, phai);
    }
}
int main ()
{
    scanf("%d",&n);
    FORE(i, 1, n ) scanf("%d",&a[i]) ;
    build() ;
    scanf("%d",&q);
    while(q--)
    {
        /*  int type ;
          cin >> type ;
          if (type == 1)
          {
              int i, v ;
              cin >> i >> v ;
              a[i] = v;
              update(1, 1, n, i, v);
          }
          else
          {
          */
        int l, r ;
        scanf("%d %d",&l, &r);
        printf("%lld\n",query( 1, 1, n, l, r ).ans);
        // }
    }
    return 0;
}
