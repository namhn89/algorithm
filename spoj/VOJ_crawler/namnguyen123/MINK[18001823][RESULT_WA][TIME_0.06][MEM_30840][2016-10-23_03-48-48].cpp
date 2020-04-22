using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int INF=1e9;
typedef long long ll;
const long  MAXN = 1e6+100;
int       n,m,k,u,v,q,L,R,a[MAXN],t[5*MAXN],res,b[MAXN];
inline void build(int k,int l,int r)
{
    if (l == r) t[k] = a[l];
    else
    {
        int m = (l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        t[k] = min(t[k*2],t[k*2+1]);
    }
}
inline int query(int x, int l, int r, int u, int v)
{
    if (v < l || u > r) return INF;
    if (u <= l && r <= v) return t[x];
    int m = (l + r) / 2;
    int trai = query(x * 2, l, m, u, v);
    int phai = query(x * 2 + 1, m + 1, r, u, v);
    return min(trai, phai);
}
int main()
{
    //freopen("MINIMUM.inp","r",stdin);
    //freopen("MINIMUM.out","w",stdout);
    int n,k;
    int Test ;
    scanf("%d",&Test);
    while(Test--)
    {
        scanf("%d%d",&n,&k);
        FORE(i,1,n)scanf("%d",&a[i]);
        build(1,1,n);
        int x=1;
        while(k<=n)
        {
            printf("%d ",query(1, 1, n, x, k));
            x++;
            k++;
        }
        printf("\n");
    }

    return 0;
}
