using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const double eps = 1e-5 ;
const double pi = acos(-1) ;
double R[MAXN] ;
int n ;
bool check (double ans) {
    long double res = 0 ;
    for(int i = 1 ; i <= n ; ++i) {
        long double OA = ans + R[i] ;
        long double OB = ans + R[i + 1] ;
        long double AB = R[i] + R[i + 1] ;
        res += acos((OA * OA + OB * OB - AB * AB) / (2 * OA * OB)) ;
    }
    if (res < 2 * pi) return true ;
    else return false ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    double left = 0 , right = 0 ;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i) cin >> R[i] , right += R[i] ;
    R[n + 1] = R[1] ;
    while(abs(right - left) > eps) {
        double mid = (left + right) / 2 ;
        if (check(mid)) right = mid ;
        else left = mid ;
    }
    printf("%0.3f", left) ;
    return 0;
}
