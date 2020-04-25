#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int MAXN = 2e3 + 501 ;
int n , f[MAXN][MAXN] , a[MAXN] ;
int pos[MAXN * MAXN * 4] ;
const int NEG = 2e6 + 1 ;
void solve ()
{
    memset(pos , -1 , sizeof(pos) ) ;
    int ans = 0 ;
    for(int i = 1 ; i <= n ; ++i )
    {
        for(int j = i + 1 ; j <= n ; ++j )
        {
            int k = pos[a[j] - a[i] + NEG] ;
            if (k != -1) f[i][j] = f[k][i] + 1 ;
            else f[i][j] = 2 ;
            ans = max(ans , f[i][j])  ;
        }
        pos[a[i] + NEG] = i ;
    }
    cout << ans << endl;
}
int main ()
{
    //freopen("test.inp","r",stdin) ;
    int Test ;
    scanf("%d",&Test);
    while(Test--)
    {
        scanf("%d", &n) ;
        for(int i = 1 ; i <= n ; ++i ) scanf("%d", &a[i]) ;
        solve() ;
    }
}