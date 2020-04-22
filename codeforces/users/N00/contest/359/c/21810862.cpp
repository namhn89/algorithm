using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
map < long long , long long > cnt ;
long long s[MAXN] ;
long long a[MAXN] ;
long long n , x  ;
ll powmod(ll a, ll n, ll mod)
{
    ll r = 1 ;
    while(n)
    {
        if(n & 1) r = (r * a) % mod ;
        a= ( a * a ) % mod ;
        n >>=1 ;
    }
    return r;
}

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Test ;
    //cin >> Test ;

        cnt.clear() ;
        cin >> n >> x  ;
        FORE(i, 1, n ) cin >> a[i] ;
        sort (a + 1 , a + n + 1);
        long long sum = 0 ;
        FORE(i , 1 , n ) sum += a[i] ;
        FORE(i , 1 , n ) cnt[sum - a[i]]++;
        long long i = sum - a[n] ;
        while(cnt[i] % x == 0 )
        {
            cnt[i + 1] += cnt[i] / x ;
            i ++ ;
        }
        cout << powmod(x , min(i , sum ) , MOD ) << endl ;
   // }









    return 0;
}
