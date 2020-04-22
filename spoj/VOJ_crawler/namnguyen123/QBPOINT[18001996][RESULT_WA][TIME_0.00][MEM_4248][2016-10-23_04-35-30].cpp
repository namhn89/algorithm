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
    cin >> n ;
    FORE(i, 1, n )
    {
        cin >> x[i] >> y[i] ;
    }
    ll ans = 0 ;
    FORE(i, 1, n )
    {
        vector<II> VECTOR ;
        FORE(j , i + 1 , n )
        {
            int xx = x[j] - x[i] ;
            int yy = y[j] - y[i] ;
            int k = __gcd(xx,yy);
            VECTOR.push_back(II(xx/k,yy/k));
        }
        sort(VECTOR.begin(),VECTOR.end());
        // TR(VECTOR,it) cout << it->st << " " << it->nd << endl;
        for(int j = 0 ; j < VECTOR.size() ; ++j )
        {
            int k = j ;
            while(j < VECTOR.size() && VECTOR[j] == VECTOR[k] ) k++;
            //cout << i << " " << j << endl;
            int len = k - j ;
            ans += len*(len - 1) ;
            j = k   ;
        }
    }

    cout << ans / 2 << endl ;



    return 0;
}
