using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(long long i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(long long i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const long long MOD = 1e9 + 7 ;
const long long MAXN = 1e5 + 5 ;
long long a[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n , x ;
    cin >> n >> x ;
    map < long long , long long > f ;
    FORE(i , 1 , n ) cin >> a[i] , f[a[i]]++;
    long long ans = 0 ;
    FORE(i , 1 , n ) {
       long long d = (a[i] ^ x) ;
       if (d == a[i]) ans--;
       ans += f[d] ;
    }
    cout << ans / 2 << endl;

    return 0;
}
