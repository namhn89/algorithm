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
vector<II> VECTOR ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    FORE(i, 1, n )
    {
        cin >> x[i] >> y[i] ;
    }
    FORE(i, 1, n )
    {
        FORE(j, i + 1, n )
        {
            int xx = x[i] - x[j] ;
            int yy = y[i] - y[j] ;
            int k = __gcd(xx,yy);
            VECTOR.push_back(II(xx/k,yy/k));
        }
    }
    sort(VECTOR.begin(),VECTOR.end());
    // TR(VECTOR,it) cout << it->st << " " << it->nd << endl;
    ll ans = 0 ;
    for(int i = 0 ; i < VECTOR.size() ; ++i ){
        int j = i + 1 ;
        while(j < VECTOR.size() && VECTOR[j] == VECTOR[i] ) j++;
        int len = j - i ;
        ans += len*(len - 1)/2 ;
        i = j  ;
    }
    cout << ans / 2 ;



    return 0;
}
