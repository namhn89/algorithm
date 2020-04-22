using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
int a[MAXN] ;
long long cnt[MAXN] , f[MAXN] , pw[MAXN] ;
int n , Max = 0 ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i] , cnt[a[i]] ++ , Max = max(Max , a[i]) ;
    pw[0] = 1 ;
    for(int i = 1 ; i <= Max ; ++i ) pw[i] = (pw[i - 1] * 2) % MOD ;
    for(int i = 1 ; i <= Max ; ++i)
        for(int j = i * 2 ; j <= Max ; j += i) cnt[i] += cnt[j] ;
    long long ans = 0 ;
    for(int i = Max ; i >= 2 ; --i) {
        f[i] = 1LL * cnt[i] * pw[cnt[i] - 1] ;
        f[i] %= MOD ;
        for(int j = 2 * i ; j <= Max ; j += i) {
            f[i] = (f[i] - f[j] + MOD) % MOD ;
        }
        ans += (1LL * f[i] * i) % MOD ;
        ans %= MOD ;
    }
    cout << ans ;

    return 0;
}
