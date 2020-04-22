using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const long long oo = 1e18 + 1 ;
map < long long, int > F ;
int a[MAXN] ;
long long Sum[MAXN];
long long k, n ;
long long power (long long a, long long n)
{
    long long res = 1 ;
    while (n)
    {
        if (n & 1) res = res * a ;
        a = a * a ;
        n >>= 1;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; ++i ) cin >> a[i] ;
    F[0] = 1 ;
    for(int i = 1 ; i <= n ; ++i ) Sum[i] = Sum[i - 1] + a[i] ;
    long long ans = 0 ;
    for(int i = 1 ; i <= n ; ++i )
    {
        if (k == 1) ans += F[Sum[i] - 1] ;
        else if (k == -1)
        {
            ans += F[Sum[i] + 1] ;
            ans += F[Sum[i] - 1] ;
        }
        else
        {
            for(long long j = 1 ; abs(j) <= oo ; j = j * k ) ans += F[Sum[i] - j] ;
        } ;
        F[Sum[i]]++;
    }
    cout << ans << endl ;
    return 0;
}
