using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int n ;
int a[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int Test ;
    scanf("%d",&Test) ;
    while(Test--)
    {
        scanf("%d",&n) ;
        for(int i = 1 ; i <= n ; ++i ) scanf("%d",&a[i]) ;
        sort(a + 1, a + n + 1, greater <int> ()) ;
        int x = -1, y = -1;
        for (int i = 1; i <= n && (x == -1 || y == -1); )
        {
            int j = i + 1;
            while (j <= n && a[j] == a[i]) ++j;
            int c = j - i;
            if (c >= 2) if (x == -1) x = a[i], c -= 2;
            if (c >= 2) if (y == -1) y = a[i];
            i = j;
        }
        if (x != -1 && y != -1) printf("%lld\n", 1ll * x * y);
        else puts("-1");
    }
    return 0;
}
