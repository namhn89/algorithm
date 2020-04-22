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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n , k ;
    cin >> n >> k ;
    int T = k ;
    for(int i = 0 ; i < n ; ++i ){
        int x ;
        cin >> x ;
        x %= k ;
        T = __gcd(T , x) ;
    }
    cout << k / T << endl ;
    for(int i = 0 ; i < k ; i += T) cout << i << " " ;
    return 0;
}
