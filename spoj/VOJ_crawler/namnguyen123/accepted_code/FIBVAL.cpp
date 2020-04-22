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
int solve(int l, int r)
{
    int len = r - l + 1 ;
    l = l % 16 ;
    r = r % 16 ;
    if (l == 0 ) l = 16 ;
    if (r == 0 ) r = 16 ;
    int res = len / 16 ;
    if (len >= 32) return (res * 16);
    else
    {
        if (len >= 9 ) return 2 ;
        else
        {

            if ( ((l <= 8 ) && (r >= 9 )) || ((l > 9 )&& (r < 8)) ) return 2 ;
            else return -1 ;
        }
    }


}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Test ;
    cin >> Test ;
    while(Test--)
    {
        int L, R ;
        cin >> L >> R  ;
        cout << solve(L,R) << endl;
    }



    return 0;
}
