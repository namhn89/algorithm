using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int oo = 1e9 + 1;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    int MaxX_1 = -oo , MinX_1 = oo;
    int MaxY_1 = -oo , MinY_1 = oo;
    int MaxX_2 = -oo , MinX_2 = oo;
    int MaxY_2 = -oo , MinY_2 = oo;
    int n, m ;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i )
    {
        int u, v ;
        cin >> u >> v ;
        MaxX_1 = max(MaxX_1 , u) ;
        MinX_1 = min(MinX_1 , u) ;
        MaxY_1 = max(MaxY_1 , v) ;
        MinY_1 = min(MinY_1 , v) ;
    }
    cin >> m ;
    for(int i = 1 ; i <= m ; ++i )
    {
        int u, v ;
        cin >> u >> v ;
        MaxX_2 = max(MaxX_2 , u) ;
        MinX_2 = min(MinX_2 , u) ;
        MaxY_2 = max(MaxX_2 , v) ;
        MinY_2 = min(MinY_2 , v) ;
    }
    if (MaxX_2 - MinY_1 < 0 && MaxX_1 - MinY_2 < 0) cout << 0 << endl;
    else cout << max(MaxX_2 - MinY_1 , MaxX_1 - MinY_2) << endl;
    return 0;
}
