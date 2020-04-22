using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 2e2 + 5 ;
int a[MAXN][MAXN] ;
int n , m ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n, &m) ;
    int x ;
    FORE(i , 1 , n ) scanf("%d",&x) ;
    FORE(i , 1 , m )
    {
        int u, v ;
        scanf("%d %d",&u, &v) ;
        a[u][v] ++;
        a[v][u] ++;
    }
    stack <int> S ;
    S.push(1) ;
    vector <int> ans ;
    while(!S.empty())
    {
        int u = S.top() ;
        bool ok = true ;
        FORE(i , 1 , n )
        {
            if (a[u][i] > 0)
            {
                a[i][u] -- ;
                a[u][i] -- ;
                ok = false ;
                S.push(i) ;
                break ;
            }
        }
        if (ok) ans.push_back(u) , S.pop() ;
    }
    printf("%d\n", m) ;
    TR(ans , it ) printf("%d ",*it) ;
    return 0;
}
