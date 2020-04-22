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
const int MAXN = 2e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
int a[MAXN] ;
int b[MAXN] ;
int F[MAXN] ;
int ma ;
int n ;
struct data
{
    int val ;
    long long cnt ;
} Tree[MAXN] ;
data get (int u)
{
    data ans;
    ans.val = 0;
    ans.cnt = 0;
    while(u > 0)
    {
        if (ans.val < Tree[u].val) ans.val = Tree[u].val, ans.cnt = Tree[u].cnt ;
        else if (ans.val == Tree[u].val)
        {
            ans.cnt += Tree[u].cnt ;
            ans.cnt %= MOD ;
        }
        u -= u & (-u);
    }
    return ans ;
}
void update(int x, int value, long long res )
{
    while(x <= ma )
    {
        if(value > Tree[x].val ) Tree[x].val = value, Tree[x].cnt = res ;
        else
        {
            if (value == Tree[x].val )
            {
                Tree[x].cnt += res ;
                Tree[x].cnt %= MOD ;
            }
        }
        x += x & (-x);
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
  //  freopen("SUBSEQ.inp","r",stdin);
 //   freopen("SUBSEQ.out","w",stdout);
    scanf("%d",&n);
    FORE(i, 1, n ) scanf("%d",&a[i]);
    FORE(i, 1, n ) b[i] = a[i] ;
    sort(b + 1, b + n + 1);
    FORE(i, 1, n ) a[i] = lower_bound(b + 1 , b + n + 1 , a[i] ) - b + 1 ;
    ma = 0 ;
    FORE(i, 1, n ) ma = max(a[i], ma);
    ma++;
    a[n + 1] = ma ;
    ll res ;
    for(int i = 1 ; i <= n + 1 ; ++i )
    {
        data ans = get(a[i] - 1);
        F[i] = ans.val + 1 ;
        if (ans.cnt == 0) ans.cnt ++;
        ans.cnt %= MOD;
        if (i == n + 1 ) cout << ans.cnt << endl;
        update(a[i], F[i] , ans.cnt);
    }

    return 0;
}
