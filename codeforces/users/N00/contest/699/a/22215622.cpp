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
const int MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
const ll INF = 1e18;
char a[MAXN];
ll x[MAXN];
ll ans = INF ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);

    int n ;
    cin >> n ;
    FORE(i, 1, n ) cin >> a[i];
    FORE(i, 1, n ) cin >> x[i];
    FOR(i , 1 , n )
    {
        if(a[i]=='R' && a[i+1]=='L') ans = min(ans, x[i+1] - x[i] );
    }
    if(ans == INF) {
        cout << - 1 << endl;
        return 0;
    }
    cout << ans/2 << endl;


    return 0;
}