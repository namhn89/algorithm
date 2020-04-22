using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 5e2 + 5 ;
const int oo = 1e9 + 100 ;
int dxA [] = {0, 1, 0 } ;
int dyA [] = {1, 1, 1 } ;
int dxB [] = {0, 1, 1 } ;
int dyB [] = {-1, -1, 0} ;
int a[MAXN][MAXN] ;
int distA[MAXN][MAXN], distB[MAXN][MAXN] ;
int n, k ;
void solve ()
{
    queue < pair <int, int> > Q ;
    FORE(i, 1, n ) FORE(j, 1, n ) distA[i][j] = distB[i][j] = oo ;
    distA[1][1] = 0 ;
    Q.push(make_pair(1, 1)) ;
    while(!Q.empty())
    {
        int x = Q.front().st ;
        int y = Q.front().nd ;
        Q.pop() ;
        for(int k = 0 ; k < 3 ; ++ k)
        {
            int u = x + dxA[k] ;
            int v = y + dyA[k] ;
            if (max(u, v) <= n && min(u, v) >= 1 && distA[u][v] == oo && a[u][v] == 1)
            {
                distA[u][v] = distA[x][y] + 1 ;
                Q.push(make_pair(u, v)) ;
            }
        }
    }
    distB[1][n] = 0 ;
    Q.push(make_pair(1, n)) ;
    while(!Q.empty())
    {
        int x = Q.front().st ;
        int y = Q.front().nd ;
        Q.pop() ;
        for(int k = 0 ; k < 3 ; ++k )
        {
            int u = x + dxB[k] ;
            int v = y + dyB[k] ;
            if (max(u, v) <= n && min(u, v) >= 1 && distB[u][v] == oo && a[u][v] == 1)
            {
                distB[u][v] = distB[x][y] + 1 ;
                Q.push(make_pair(u, v)) ;
            }
        }
    }
    int ans = oo ;
    FORE(i , 1 , n)
    {
        FORE(j , 1 , n)
        {
            if (a[i][j]) ans = min(ans , max(distA[i][j] , distB[i][j]) ) ;
        }
    }
    printf("%d\n", ans) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n, &k) ;
    FORE(i, 1, n )
    FORE(j, 1, n ) a[i][j] = 1 ;
    FORE(i, 1, k )
    {
        int u, v ;
        scanf("%d %d", &u, &v) ;
        a[u][v] = 0 ;
    }
    solve() ;


    return 0;
}
