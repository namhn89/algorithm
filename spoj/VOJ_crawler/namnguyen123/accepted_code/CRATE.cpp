using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

inline void read (int &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e9 + 7 ;
const int MAXN = 3e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
const int __max = 1e5 ;
struct data
{
    int x1, x2, id ;
} a[MAXN];
int F[__max + 1], ans[MAXN] ;
bool cmp (data x, data y )
{
    if(x.x1 == y.x1 ) return x.x2 < y.x2;
    else return x.x1 < y.x1 ;
}
int get (int u )
{
    int res = 0 ;
    while(u > 0 )
    {
        res += F[u] ;
        u -= u & (-u);
    }
    return res ;
}
void update (int v, int value )
{
    while(v <= __max)
    {
        F[v] += value ;
        v += v & (-v);
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n ;
    read(n) ;
    FORE(i, 1, n )
    {
        read(a[i].x1) ;
        read(a[i].x2) ;
        a[i].id = i ;
    }
    sort(a + 1, a + n + 1, cmp );
    for(int i = 1 ; i <= n ; )
    {
        int j = i ;
        while(j <= n && a[j].x1 == a[i].x1 && a[j].x2 == a[i].x2 ) j++;
        for(int k = i ; k < j ; ++k ) ans[a[k].id] = get(a[k].x2);
        for(int k = i ; k < j ; ++k ) update(a[k].x2, 1);
        i = j ;
    }
    FORE(i, 1, n ) printf("%d\n",ans[i]);


    return 0;
}
