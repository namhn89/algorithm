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
    int s , a , b , c ;
    cin >> s >> a >> b >> c ;
    cout << fixed << setprecision(10) ;
    if (a + b + c == 0) {
        cout << "0 0 0" << endl;
        return 0 ;
    }
    double x = 1.0 * s * a / (a + b + c);
	double y = 1.0 * s * b / (a + b + c);
	double z = 1.0 * s * c / (a + b + c);
	cout << x << " " << y << " " << z << endl;
    return 0;
}
