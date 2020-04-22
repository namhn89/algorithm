#include<bits/stdc++.h>
using namespace std ;
#define second nd
#define first st
#define FORE(i, a, b) for(int i = a , _b = (b) ; i <= _b ; ++i)
#define FORD(i, a, b) for(int i = a , _b = (b) ; i >= _b ; --i)
#define TR(c,it) for(__typeof((c).begin()) it = (c).begin() ; it != (c).end(); ++it)
typedef long long ll ;
typedef pair<int,int> II ;
typedef pair<int,II> III ;
typedef pair<ll,ll> LL ;
const int MAXN = 1e5 + 1 ;
const int MOD = 1e9 + 7 ;
int f[MAXN] ;
int a[MAXN] ;
const int INF = 303 ;
int cnt[301];
int main ()
{
    // freopen("lnds.inp","r",stdin);
    //  freopen("lnds.out","w",stdout);
    int n, t ;
    cin >> n >> t ;
    int ma = 0 ;
    FORE(i, 1, n )
    {
        cin >> a[i] ;
        cnt[a[i]]++;
        ma = max(ma,cnt[a[i]]);
    }
    FORE(i, 1, n )
    {
        FORE(j, 1, min(t,100) )
        {
            a[i+(j-1)*n] = a[i];
        }
    }
    int m = min(t,100) * n ;
    int k = min(t,100);
    FORE(i, 1, m ) f[i] = 1 ;
    FORE(i, 1, m )
    {
        FORE(j, 1, i - 1 )
        {
            if( a[i] >= a[j] )
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int ans = 0 ;
    FORE(i, 1, m )
    {
        ans = max(ans, f[i]) ;
    }
    ans += (t-k)*ma ;
    cout << ans << endl;




           return 0;
}
