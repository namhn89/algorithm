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
    map < int , int> f ;
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i ) {
        int x ;
        cin >> x ;
        for(int i = 2 ; i * i <= x ; ++i ){
            if (x % i == 0) {
                f[i]++;
                while(x % i == 0) x /= i ;
            }
        }
        if (x > 1) f[x]++;
    }
    int ans = 1 ;
    for(map <int, int> :: iterator it = f.begin() ; it != f.end() ; ++it ) {
         ans = max(ans , it -> nd) ;
    }
    cout << ans << endl;
    return 0;
}
