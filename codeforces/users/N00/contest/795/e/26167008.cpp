using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 2e5 + 5 ;
long long pre[MAXN] ;
string s ;
int MOD ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> MOD ;
    int n = s.size() ;
    s = s + s ;
    s = " " + s ;
    long long ans = MOD, res = 0 ;
    pre[0] = 1 ;
    for(int i = 1 ; i <= n ; ++i ) pre[i] = (pre[i - 1] * 10) % MOD ;
    for(int i = 1 ; i <= n ; ++i )
    {
        res = (res * 10) + (s[i] - '0') ;
        res %= MOD ;
    }
    for(int i = 2 ; i <= n + 1 ; ++i )
    {
        //cout << res << endl;
        if (s[i - 1] != '0') ans = min(ans , res) ;
        res = (res * 10) % MOD ;
        res -= ( (s[i - 1] - '0') * pre[n] ) % MOD ;
        res %= MOD ;
        res = (res + MOD) % MOD ;
        res += (s[i + n - 1]  - '0') ;
        res %= MOD ;
    }
    cout << ans << endl ;
    return 0;
}
