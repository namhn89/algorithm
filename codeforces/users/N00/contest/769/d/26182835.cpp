using namespace std;
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
const int MAXN = 10 + 1e5;
int n , k ;
const int N = 1e4 ;
int a[MAXN] , cnt[MAXN] ;
int main()
{
    //freopen("test.inp","r",stdin);
    scanf("%d %d", &n , &k) ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%d", &a[i]), cnt[a[i]]++;
    long long ans = 0 ;
    for(int i = 0 ; i <= N ; ++i )
    {
        for(int j = i ; j <= N ; ++j )
        {
            int xx = i ^ j ;
            int b = __builtin_popcount(xx) ;
            if (b == k && k) ans += 1LL * cnt[i] * cnt[j] ;
            if (b == k && !k) ans += (1LL *  cnt[i] * (cnt[i] - 1))/ 2 ;
        }
    }
    cout << ans << endl;
    return 0;
}
