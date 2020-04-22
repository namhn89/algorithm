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

inline void read (int &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
int a[MAXN] ;
long long s[MAXN] ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin >> n ;
    FORE(i, 1, n ) cin >> a[i] ;
    FORE(i, 1, n ) s[i] = s[i - 1] + a[i] ;
    long long res = -LNF;
    long long ans = 0 ;
    long long maxS , minS ;
    maxS = minS = a[n] ;
    long long S = a[n] ;
    int cntMin = 0, cntMax = 0 ;
    FORD(i, n - 1, 1 )
    {
        if (abs(s[i] - minS) > res )
        {
            res = abs(s[i] - minS) ;
            ans = cntMin ;
        }
        else if (abs(s[i] - minS) == res )
        {
            ans += cntMin ;
        }
        if (minS != maxS)
        {
            if (abs(s[i] - maxS) > res)
            {
                res = abs(s[i] - maxS);
                ans = cntMax;
            }
            else if (abs(s[i] - maxS) == res)
                ans += cntMax;
        }
        S += a[i] ;
        if (S < minS)
		{
			minS = S;
			cntMin = 1;
		}
		else if (S == minS) cntMin++;
		if (S > maxS)
		{
			maxS = S;
			cntMax = 1;
		}
		else if (S == maxS) cntMax++;
    }
    cout << res << " " << ans << endl;



    return 0;
}
