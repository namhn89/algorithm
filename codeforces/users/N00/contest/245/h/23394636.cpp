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
const int MAXN = 5e3 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
long long f[MAXN][MAXN];
bool t[MAXN][MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    string s ;
    cin >> s ;
    int n = s.size();
    s = " " + s ;
    FORE(i , 1 , n )
    {
        FORE(j , 1 , n )
        {
            if (i >= j )
            {
                t[i][j] = true ;
            }
        }
    }
    FORE(i , 1 , n ) f[i][i] = 1 ;
    FORE(len , 1 , n )
    {
        FORE(l , 1 , n - len + 1)
        {
            int r = l + len - 1 ;
            if (s[l] == s[r] && t[l+1][r-1])
            {
                t[l][r] = true ;
            }
        }
    }
    FORE(len , 1 , n )
    {
        FORE(i , 1 , n - len + 1)
        {
            int j = i + len - 1  ;
            f[i][j] = f[i+1][j] + f[i][j-1] - f[i+1][j-1] + (t[i][j] == true) ;
        }
    }
    int q ;
    scanf("%d",&q) ;
    while(q--)
    {
        int l , r ;
        scanf("%d %d",&l ,&r) ;
        printf("%lld\n", f[l][r]) ;
    }
    return 0;
}
