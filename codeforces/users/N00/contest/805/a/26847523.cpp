using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int ans , res = -1 ;
int l , r ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> r ;
    res = l ;
    for(int i = 2 ; i * i <= r ; ++i )
    {
        int _r = r / i ;
        int _l = (l + i - 1) / i ;
        if (ans < _r - _l + 1)
        {
            res = i ;
            ans = _r - _l + 1 ;
        }
        int x = r / i ;
        _r = r / x ;
        _l = (l + x - 1) / x ;
        if (ans < _r - _l + 1)
        {
            res = x ;
            ans = _r - _l + 1 ;
        }
    }
    cout << res << endl ;
    return 0;
}
