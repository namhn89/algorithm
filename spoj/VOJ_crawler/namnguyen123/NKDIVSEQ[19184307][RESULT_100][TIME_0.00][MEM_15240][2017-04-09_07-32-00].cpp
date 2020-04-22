using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N ;
    cin >> N ;
    int x = 1 , cnt = 1 , nxt = 1 ;
    long long ans = 1 ;
    for(int i = 1 ; i <= N - 1 ; ++i)
    {
        cnt--;
        if(cnt == 0)
        {
            x ++ ;
            cnt = x ;
            nxt ++ ;
        }
        if (cnt == x) ans += nxt - (ans % nxt) ;
        else ans += x ;
    }
    cout << ans << endl;

    return 0;
}
