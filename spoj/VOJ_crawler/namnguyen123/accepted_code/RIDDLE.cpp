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
const int INF = 2e9 +10  ;
const int BASE = 31 ;

int a[MAXN], F[MAXN], n, k ;
int check (int x)
{
    FORE(i , 1 , x ) F[i] = a[i];
    sort(F + 1, F + x + 1);
    long long hig = 0;
    FORE(i , 1 , x)
    {
        if (F[i] > hig + 1) return false;
        hig += F[i];
        if (hig >= k ) return true;
    }
    return false;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("shopping.inp","r",stdin);
    //  freopen("shopping.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Test ;
    cin >> Test ;
    while(Test--)
    {
        cin >> n >> k ;
        FORE(i, 1, n ) cin >> a[i] ;
        int l = 1 ;
        int r = n ;
        int ans =  -1 ;
        while(l <= r )
        {
            int mid = (l + r) / 2 ;
            if(check(mid)) r = mid - 1, ans = mid ;
            else l = mid + 1 ;
        }
        cout << ans << endl;
    }

    return 0;
}
