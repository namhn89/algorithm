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

const int MOD = 1e9 + 7 ;
const int MAXN = 1e3 + 27 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
ll f[MAXN][MAXN];
int n ;
void Init ()
{
    FORE(i , 0 , n )
    {
        FORE(j , 0 , n ) f[i][j] = 0 ;
    }
}
void update(int x , int y , long long v )
{
    for(int a = x; a <= n; a += a & (-a))
    {
        for(int b = y; b <= n; b += b & (-b))
        {
            f[a][b] += v;
        }
    }
}
long long get(int x, int y)
{
    ll res = 0;
    for(int a = x; a > 0; a -= a & (-a))
    {
        for(int b = y ; b > 0; b -= b & (-b))
        {
            res += f[a][b];
        }
    }
    return res;
}
long long query (int x1, int y1, int x2, int y2 )
{
    long long res = get(x2 , y2) - get(x2 , y1 - 1) - get(x1 - 1 , y2) + get(x1 - 1 , y1 - 1) ;
    return res ;
}

int main()
{
    // freopen("test.inp","r",stdin);
     //freopen("NKMOBILE.inp","r",stdin);
     //freopen("NKMOBILE.out","w",stdout);
    int x ;
    while(~scanf("%d",&x))
    {
        if (x == 0)
        {
            scanf("%d",&n);
            Init() ;
        }
        if (x == 1 )
        {
            int x, y, h ;
            scanf("%d %d %d" , &x , &y , &h) ;
            x++; y++;
            update(x, y, h ) ;
        }
        if (x == 2){
            int L , B , R , T ;
            scanf("%d %d %d %d", &L , &B , &R , &T) ;
            L++ ; B++; R++; T++;
            printf("%lld\n", query(L ,B , R ,T)) ;
        }
        if (x == 3 ) return 0 ;
    }
    return 0;
}
