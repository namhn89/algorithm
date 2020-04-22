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
const int MAXN = 2e3 + 1 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
map<II,II> F1 ;
map<II,II> F2 ;
int xa[MAXN], ya[MAXN] ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    FORE(i, 1, 2*n ) cin >> xa[i] >> ya[i] ;
    FORE(i, 1, n )
    {
        FORE(j, i + 1, n )
        {
            int x = xa[i] - xa[j];
            int y = ya[i] - ya[j];
            int d = __gcd(x,y);
            x /= d ;
            y /= d ;
            if (x < 0 ) x = -x ;
            if (y < 0 ) y = -y ;
            F1[II(x,y)] = II(i,j);
        }
    }
    FORE(i , n + 1 , 2*n )
    {
        FORE(j , i + 1 , 2*n )
        {
            int x = xa[i] - xa[j];
            int y = ya[i] - ya[j];
            int d = __gcd(x,y);
            x /= d ;
            y /= d ;
            if (x < 0 ) x = -x ;
            if (y < 0 ) y = -y ;
            F2[II(x,y)] = II(i,j);
        }
    }
    FORE(i , 1 , n )
    {
        FORE(j , j + n , 2*n )
        {
            int x = xa[i] - xa[j] ;
            int y = ya[i] - ya[j] ;
            int d = __gcd(x,y);
            x /= d ;
            y /= d ;
            if (x < 0 ) x = -x ;
            if (y < 0 ) y = -y ;
            if (F1.count(II(x,y)))
            {
                int a = F1[II(x,y)].st ;
                int b = F1[II(x,y)].nd ;
                if (a != i && a != j )
                {
                    printf("%d %d %d\n", i, j, a );
                    return 0 ;
                }
                else if (b != i && b != j )
                {
                    printf("%d %d %d\n", i, j, b );
                    return 0 ;
                }
            }
            if (F2.count(II(x,y)))
            {
                int a = F2[II(x,y)].st ;
                int b = F2[II(x,y)].nd ;
                if (a != i && a != j )
                {
                    printf("%d %d %d\n", i, j, a );
                    return 0 ;
                }
                else if (b != i && b != j )
                {
                    printf("%d %d %d\n", i, j, b );
                    return 0 ;
                }
            }
        }
    }
    printf("-1\n");

    return 0;
}
