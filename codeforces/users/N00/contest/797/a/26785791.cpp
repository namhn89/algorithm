using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int n, k ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k ;
    vector <int> fact ;
    for(int i = 2 ; i * i <= n ; ++i )
    {
        while(n % i == 0)
        {
            fact.push_back(i) ;
            n /= i ;
        }
    }
    if (n != 1) fact.push_back(n) ;
    if (fact.size() < k) {
        cout << -1 << endl ;
    }
    else {
        int ans = 1 ;
        while(fact.size() >= k ) { ans *= fact.back() ; fact.pop_back() ; } ;
        for(int i = 0 ; i < fact.size() ; ++i ) cout << fact[i] << ' '; cout << ans ;

    }


    return 0;
}
