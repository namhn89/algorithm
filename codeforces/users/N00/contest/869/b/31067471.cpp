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
    long long b , a ;
    cin >> a >> b ;
    if (b - a >= 5) {
        cout << 0 ;
    }
    else {
        long long ans = 1 ;
        for(long long i = a + 1; i <= b ; ++i ) ans = (ans * i) % 10 ;
        cout << ans ;
    }

    return 0;
}
