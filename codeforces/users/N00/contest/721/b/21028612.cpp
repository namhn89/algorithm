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
string s[MAXN];
int res[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k ;
    cin >> n >> k ;
    FORE(i, 1, n ) cin >> s[i] ;
    string check ;
    cin >> check ;
    int x = check.size();
    int t = 0 ;
    FORE(i, 1, n )
    {
        res[s[i].size()]++;
    }
    FORE(i, 1, n )
    {
        if(s[i] == check ) t++;
    }
    int mi = 0 , ma = 0 ;
    FORE(i , 1, x - 1 ) mi += res[i];
    mi++;
    ma = mi + res[x] - 1  ;
   // cout << mi << " " << ma << endl;
    ma -= (t-1);
    int ans1 = (mi-1)/k*5 + mi ;
    int ans2 = (ma-1)/k*5 + ma ;
    cout << ans1 << " " << ans2 << endl;



    return 0;
}
