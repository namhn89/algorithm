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
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 2e9 + 10 ;
const int BASE = 31 ;
int a[4][MAXN] ;
int f[MAXN][20] ;
int d[] = {0, 1, 2, 4, 5, 8, 9, 10} ;
int getbit (int k, int x )
{
    return (x >> (k-1)) & 1 ;
}
int check (int x, int y )
{
    FORE(i, 1, 4) if ( getbit(i, x) == 1 && getbit(i, y) == 1) return 0 ;
    return 1 ;
}
int val (int x, int y)
{
    int res = 0 ;
    FORE(i, 1, 4)
    {
        if (getbit(i, x) == 1) res += a[i][y] ;
    }
    return res ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    read(n);
    int dmax = -INF ;
    FORE( i, 1, 4 )
    {
        FORE( j, 1, n )
        {
            read(a[i][j]);
            dmax = max(a[i][j],dmax);
        }
    }
    if (dmax < 0 )
    {
        printf("%d\n",dmax);
        return 0 ;
    }
    FORE(i, 1, n )
    {
        FOR(j, 0, 8 )
        {
            FOR( k, 0, 8 )
            {
                if (check(d[j], d[k]) == 1)
                {
                    f[i][j] = max(f[i-1][k] + val(d[j],i), f[i][j]) ;
                }
            }
        }
    }
    int res = -INF ;
    FOR(i, 0, 8) res = max(res, f[n][i])  ;
    printf("%d\n",res);



    return 0;
}
