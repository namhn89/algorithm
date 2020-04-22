using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int a[MAXN] , n , k ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i] ;
    sort(a + 1 , a + n + 1) ;
    long long ans = 0 ;
    for(int i = 1 ; i <= k ; ++i ) ans += a[i] ;
    cout << ans << endl ;

    return 0;
}
