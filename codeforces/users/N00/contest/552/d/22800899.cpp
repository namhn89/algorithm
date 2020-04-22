using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
int x[MAXN],y[MAXN] ;
int main()
{
     // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    scanf("%d",&n);
    FORE(i, 1, n )
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    ll ans = 0 ;
    for(int i = 1 ; i <= n ; ++ i )
    {
        vector<II> VECTOR ;
        for(int j = i + 1 ; j <= n ; ++ j)
        {
            int xx = x[j] - x[i] ;
            int yy = y[j] - y[i] ;
            int k = __gcd(xx,yy);
            VECTOR.push_back(II(xx/k,yy/k));
        }
        sort(VECTOR.begin(),VECTOR.end());
        //TR(VECTOR,it) cout << it->st << " " << it->nd << endl;
        int lent = VECTOR.size() - 1 ;
        int t = 0 ;
        while(t <= lent)
        {
            int k = t + 1;
            while( k <= lent && VECTOR[t] == VECTOR[k] ) k++;
            //cout << endl;
            //cout << t << " " << k << endl;
            int len = k - t  ;
            ans += 1ll*len*(len - 1)/2  ;
            t = k   ;
        }
       // cout << endl;
    }
    long long res = 1ll * n * (n - 1) * (n - 2) / 6 - ans ;
    printf("%lld",res);


    return 0;
}
