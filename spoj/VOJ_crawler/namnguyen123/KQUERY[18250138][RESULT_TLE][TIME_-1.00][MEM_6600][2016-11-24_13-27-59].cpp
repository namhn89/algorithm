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
int t[MAXN];
int ans[MAXN];
int n, q ;
inline ll getf(int i)
{
    ll res = 0 ;
    while (i > 0 )
    {
        res = (t[i] + res );
        i -= (i & (-i));
    }
    return res ;
}
inline void change (int v, int value)
{
    while(v <= n )
    {
        t[v] =  (t[v] + value) ;
        v += (v & (-v));
    }
}
struct query
{
    int i,j,k,pos;
};

bool cmp(const query &a, const query &b)
{
    return a.k < b.k ;
}
query que[MAXN];
II a[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    cin >> n ;
    FORE(i, 1, n )
    {
        cin >> a[i].st ;
        a[i].nd = i ;
    }
    sort(a + 1, a + n + 1 );
    cin >> q ; 
    FORE(i, 1, q )
    {
        cin >> que[i].i >> que[i].j >> que[i].k ;
        que[i].pos = i ;
    }
    sort(que + 1, que + q + 1, cmp);
    int t = 1 ;
    FORE(i , 1 , n ) change(i , 1 );
    FORE(i , 1 , q )
    {
        while (t <= n && a[t].st <= que[i].k )
        {
            change(a[t].nd , - 1 );
            t++;
        }
        ans[que[i].pos] = getf(que[i].j) - getf(que[i].i - 1);
    }
    FORE(i , 1 , q ) cout << ans[i] << endl;


    return 0;
}
