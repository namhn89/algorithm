using namespace std;
#include<bits/stdc++.h>
#define FORE(i,a,b) for(int i = a ,_b = (b); i <= _b ; i ++ )
#define FORD(i,a,b) for(int i = a ,_b = (b); i >= _b ; i -- )
const int INF = 1e9 ;
const int MAXN = 1e3 + 1 ;
int m, n ;
int a[MAXN][MAXN]  ;
int h[MAXN], r[MAXN], l[MAXN] ;
int main()
{
   // freopen("MAXRECT.inp","r",stdin);
   // freopen("MAXRECT.out","w",stdout);
    scanf("%d %d", &m, &n) ;
    FORE(i, 1, m)
    {
        FORE(j, 1, n)
        {
            char c ;
            cin >> c ;
            if (c == 'W')
            {
                a[i][j] = 1;
            }
        }
    }
    int ans = 0 ;
    h[0] = h[n+1] = -INF ;
    FORE(i, 1, m)
    {
        FORE(j, 1, n)
        {
            if(a[i][j]) h[j]++ ;
            else h[j] = 0 ;
        }
        FORE(j, 1, n)
        {
            int p = j-1 ;
            while(h[p] >= h[j]) p = l[p] ;
            l[j] = p ;
        }
        FORD(j, n, 1)
        {
            int p = j+1 ;
            while(h[p] >= h[j]) p = r[p] ;
            r[j] = p ;
        }
        FORE(j, 1, n)
        {
            ans = max(ans, (r[j] - l[j] - 1) * h[j] ) ;
        }
    }
    printf("%d", ans) ;
    return 0;
}

