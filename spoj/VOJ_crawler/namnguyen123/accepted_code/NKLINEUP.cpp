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
const int INF = 1e9 + 1 ;
int tmin[4*MAXN];
int tmax[4*MAXN];
int a[MAXN];
int n,q ;
inline void build(int k, int l, int r, int i, int v)
{
    if (i < l or i > r or l > r) return;
    if (l == r)
    {
        tmax[k] = v;
        tmin[k] = v;
    }
    else
    {
        int m = (l+r)/2;
        build(k*2,l,m,i,v);
        build(k*2+1,m+1,r,i,v);
        tmax[k] = max(tmax[k*2],tmax[k*2+1]);
        tmin[k] = min(tmin[k*2],tmin[k*2+1]);
    }
}
inline int querymin(int x, int l, int r, int u, int v)
{
    if (v < l || u > r) return INF;
    if (u <= l && r <= v) return tmin[x];
    int mid = (l + r) / 2;
    int trai = querymin(x * 2, l, mid, u, v);
    int phai = querymin(x * 2 + 1, mid + 1, r, u, v);
    return min(trai, phai);
}
inline int querymax(int x, int l, int r, int u, int v)
{
    if (v < l || u > r) return -INF;
    if (u <= l && r <= v) return tmax[x];
    int mid = (l + r) / 2;
    int trai = querymax(x * 2, l, mid, u, v);
    int phai = querymax(x * 2 + 1, mid + 1, r, u, v);
    return max(trai, phai);
}
int main()
{
   // freopen("IT2.inp","r",stdin);
  // freopen("IT2.out","w",stdout);
    scanf("%d %d",&n,&q);
    FORE(i, 1, n )
    {
        scanf("%d",&a[i]);
        build(1,1,n,i,a[i]);
    }
    FORE(i, 1, q )
    {

            int l,r ;
            scanf("%d %d",&l,&r);
            cout << querymax(1,1,n,l,r) - querymin(1,1,n,l,r) << endl;
    }
    return 0;
}
