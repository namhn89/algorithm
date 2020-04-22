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
    int n ;
    cin >> n ;
    long long ans = 0 ;
    for(int i = 1 ; i <= n ; ++i ) {
        string s ;
        cin >> s ;
        if (s == "Tetrahedron") ans += 4 ;
        if (s == "Cube" ) ans += 6 ;
        if (s == "Octahedron") ans += 8 ;
        if (s == "Dodecahedron") ans += 12 ;
        if (s == "Icosahedron") ans += 20;
    }
    cout << ans << endl;

    return 0;
}
