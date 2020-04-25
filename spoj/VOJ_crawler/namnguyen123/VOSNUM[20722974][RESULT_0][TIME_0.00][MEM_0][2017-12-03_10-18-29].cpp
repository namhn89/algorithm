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
    int T ;
    cin >> T ;
    while(T--) {
        long long n ;
        cin >> n ;
        vector <int> digit ;
        while(n) {
            digit.push_back(n % 10) ;
            n /= 10 ;
        }
        int k = digit.size() ;
        int ans = 0;
        reverse(digit.begin() , digit.end() ) ;
        bool ok = false ;
        for(int i = 0 ; i < digit.size() ; ++i ) if (digit[i] == 1) ok = true ;
        if (digit[0] == 1) {
            for(int i = 1 ; i < digit.size() ; ++i ) {
               ans += (digit[i] + 1) ;
            }
            ans-- ;
        }
        else if (ok) {
            for(int i = 1 ; i < digit.size() ; ++i ) {
               ans += (digit[i] + 1) ;
            }
        }
        else {
            int S = 0 ;
            for(int i = 0 ; i < digit.size() ; ++i ) {
                S += digit[i] ;
            }
            S += (k - 2) ;
            ans += S ;
        }
        ans += (10 * (k - 1) * k / 2) ;
        cout << ans << endl ;
    }


    return 0;
}
