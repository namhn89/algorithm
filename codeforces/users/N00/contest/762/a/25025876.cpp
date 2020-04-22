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
    long long n ;
    long long k ;
    cin >> n >> k ;
    vector <long long> divisor ;
    for(long long i = 1 ; i * i <= n ; ++i ){
         if (n % i == 0) {
         if (i * i != n ){
            divisor.push_back(i) ;
            divisor.push_back(n / i) ;
         }
         else divisor.push_back(i);
         }
    }
    if (divisor.size() < k) {cout << -1 ; return 0 ; }
    sort(divisor.begin(),divisor.end()) ;
    cout << divisor[k - 1] << endl ;

    return 0;
}
