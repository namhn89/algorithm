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
    long long xA , yA , xB , yB , xC , yC , xD , yD ;
    cin >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD ;
    long long area = (xA - xB) * (xA - xB) + (yA - yB) * (yA - yB)  ;
    long long P = __gcd(xB - xA , yB - yA) + __gcd(xD - xA , yD - yA) ;
    long long ans = area - P + 1 ;
    cout << ans << endl;

    return 0;
}
