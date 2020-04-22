using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 6e4 + 5 ;
int x[MAXN] , v[MAXN] , n ;
double eps = 1e-7 ;
bool check (double tick ) {
    double L_Max = 0 , R_Max = 0;
    double L_Min = 1e9 , R_Min = 1e9 ;
    for(int i = 1 ; i <= n ; ++i ) {
        double x_L = x[i] - 1.0 * v[i] * tick ;
        double x_R = x[i] + 1.0 * v[i] * tick ;
        L_Max = max(L_Max , x_L) ;
        L_Min = min(L_Min , x_L) ;
        R_Max = max(R_Max , x_R) ;
        R_Min = min(R_Min , x_R) ;
    }
    //cout << R_Max << " " << R_Min << " " << L_Max << " " << L_Min << endl;
    if (R_Min - L_Max < eps ) return false ;
    else return true ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(12) ;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i) cin >> x[i] ;
    for(int i = 1 ; i <= n ; ++i) cin >> v[i] ;
    double l = 0 , r = 1e9 ;
    double ans ;
    while(r - l > eps) {
        double mid = (l + r) / 2 ;
        if (check(mid)) ans = mid , r = mid ;
        else l = mid ;
    }
    cout << ans << endl ;
    return 0;
}
