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
II tree[MAXN];
int a[MAXN];
int n, m ;
inline void build(int k, int l, int r, int i, int v)
{
    if (i<l or i>r or l>r) return;
    if (l == r)
    {
        tree[k].st = v ;
        tree[k].nd = i ;
    }
    else
    {
        int mid = (l+r)/2;
        build(k*2,l,mid,i,v);
        build(k*2+1,mid+1,r,i,v);
        tree[k] = max(tree[k*2],tree[k*2+1]);
    }
}
II getmax(int k, int l, int r, int u, int v)
{
    if( v < l || r < u ) return II(0,0);
    if( u <= l && r <= v) return II(tree[k].st,tree[k].nd);
    int mid = (r + l )/2;
    II trai = getmax(2*k,mid,l,u,v);
    II phai = getmax(2*k+1,mid+1,r,u,v);
    return max(trai,phai);
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n ;
    FORE(i, 1, n )
    {
        cin >> a[i];
        build(1,1,n,i,a[i]);
    }
    cin >> m ;
    FORE(i, 1, m )
    {
        char c ;
        cin >> c ;
        if (c == 'U')
        {
            int i, x ;
            cin >> i >> x ;
            a[i] = x ;
            build(1, 1, n, i, x);
        }
        else
        {
            int l, r ;
            cin >> l >> r ;
            II t = getmax(1, 1, n, l, r );
            int x = t.nd ;
            II k = max(getmax(1 , 1, n , l , x - 1 ), getmax(1 , 1 , n , x + 1 , r) );
          // cout << getmax(1,1,n,l,x-1).st << endl;
           // cout << getmax(1,1,n,x+1,r).nd << endl;
           // cout << x << " " << t.st << " " << k.st << " " << k.nd << endl;
            cout << t.st + k.st << endl;
        }
    }
    return 0;
}
