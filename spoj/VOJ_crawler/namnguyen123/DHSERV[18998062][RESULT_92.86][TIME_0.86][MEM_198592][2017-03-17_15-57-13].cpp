using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 5e3 + 5 ;
const long long oo = 1e18 ;
long long d[MAXN][MAXN] ;
bool Mark[MAXN] ;
int n, m, k ;
int main()
{
#define TASK "DHSERV"
   //  freopen(TASK".inp","r",stdin);
   //  freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k ;
    for(int i = 1 ; i <= n ; ++i )
    for(int j = 1 ; j <= n ; ++j ) {
         if(i == j) d[i][j] = 0 ;
         else d[i][j] = oo , d[j][i] = oo ;
    }
    for(int i = 1 ; i <= m ; ++i )
    {
        int u, v, c;
        cin >> u >> v >> c;
        d[u][v] = c ;
    }
    memset(Mark , false , sizeof (Mark)) ;
    for(int nTest = 1 ; nTest <= k ; ++nTest )
    {
        int type ;
        cin >> type ;
        if (type == 1)
        {
            int u ;
            cin >> u ;
            if (!Mark[u])
            {
                Mark[u] = true ;
                for(int i = 1 ; i <= n ; ++i )
                    for(int j = 1 ; j <= n ; ++j ) d[i][j] = min(d[i][j] , d[i][u] + d[u][j]) ;
            }
        }
        else
        {
            int u , v ;
            cin >> u >> v ;
            if (d[u][v] == oo) cout << -1 << endl;
            else cout << d[u][v] << endl;
        }
    }

    return 0;
}
