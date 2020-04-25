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
int dxA [] = {0 , 1 , 1 } ;
int dyA [] = {1 , 1 , 0 } ;
int dxB [] = {0 , 1 , 1 } ;
int dyB [] = {-1, -1, 0 } ;
int a[MAXN][MAXN] ;
int distA[MAXN][MAXN][MAXN] , distB[MAXN][MAXN][MAXN] ;
struct data {
   int x , y , vtime ;
   data (int x , int y , int vtime ) : x(x) , y(y) , vtime (vtime) {} ;
};
int n , k ;
int solve ()
{
    queue < data > Q ;
    distA[1][1][0] = 1 ;
    Q.push(data (1 , 1 , 0)) ;
    while(!Q.empty())
    {
        int x = Q.front().x ;
        int y = Q.front().y ;
        int vtime = Q.front().vtime ;
        Q.pop() ;
        for(int k = 0 ; k < 3 ; ++ k)
        {
            int u = x + dxA[k] ;
            int v = y + dyA[k] ;
            if (max(u , v) <= n && min(u , v) >= 1 && !distA[u][v][vtime] && a[u][v] == 1)
            {
                distA[u][v][vtime] = 1  ;
                Q.push(data(u , v , vtime) ) ;
            }
        }
    }
    distB[1][n][0] = 1 ;
    Q.push(data(1 , n , 0)) ;
    while(!Q.empty())
    {
        int x = Q.front().x ;
        int y = Q.front().y ;
        int vtime = Q.front().vtime ;
        if (distA[x][y][vtime]) return vtime ;
        Q.pop() ;
        for(int k = 0 ; k < 3 ; ++k )
        {
            int u = x + dxB[k] ;
            int v = y + dyB[k] ;
            vtime++ ;
            if (max(u , v) <= n && min(u , v) >= 1 && !distB[u][v][vtime] && a[u][v] == 1)
            {
                distB[u][v][vtime] = 1 ;
                Q.push(data(u , v , vtime)) ;
            }
        }
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &k) ;
    FORE(i , 1 , n )
    FORE(j , 1 , n ) a[i][j] = 1 ;
    FORE(i , 1 , k )
    {
        int u, v ;
        scanf("%d %d", &u, &v) ;
        a[u][v] = 0 ;
    }
    printf("%d\n",solve()) ;
    return 0;
}
