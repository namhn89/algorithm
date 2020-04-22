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
const ll MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const ll BASE = 31 ;
ll Hash[MAXN], powmod[MAXN];
int n ;
inline ll getHash(int i, int j)
{
    return (Hash[j] - Hash[i-1] * powmod[j-i+1] + MOD*MOD )%MOD;
}
inline bool check (int d )
{
    ll t = getHash( 1, d )  ;
    FORE(i, 2, n - d )
    {
        if (getHash(i, i + d - 1) == t ) return true ;
    }
    return false ;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s ;
    cin >> s ;
    n = s.size();
    s = " " + s ;
    powmod[0] = 1 ;
    FORE(i, 1, n ) powmod[i] = (powmod[i-1] * BASE) % MOD ;
    FORE(i, 1, n )
    {
        Hash[i] = Hash[i - 1] * BASE + (s[i] - 'a');
        Hash[i] %= MOD;
    }
    vector<int> T ;
    FORE(i, 1, n )
    {
        ll pre = getHash(1, i );
        ll suf = getHash(n - i + 1, n );
        if (pre == suf) T.push_back(i);
    }
    int res = -1 ;
    int left = 0, right = T.size();
    while(left <= right )
    {
        int mid = ( left + right )/2 ;
        if (check(T[mid]))
        {
            res = max(res,T[mid]);
            left = mid + 1 ;
        }
        else right = mid - 1 ;
    }
    if (res == - 1 ) cout << "Just a legend" << endl;
    else
    {
        FORE(i, 1, res ) cout << s[i] ;
    }



    return 0;
}
