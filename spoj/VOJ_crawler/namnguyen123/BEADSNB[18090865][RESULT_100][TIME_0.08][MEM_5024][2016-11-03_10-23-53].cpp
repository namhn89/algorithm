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

int n, a[MAXN], s[MAXN] , F[MAXN] , F1[MAXN] ;
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen("TASK.inp","r",stdin);
    // freopen("TASK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n ;
    FORE(i, 1, n ) cin >> a[i] ;
    int k = 1;
    s[1] = a[n];
    F[n] = 1;
    FORD(i , n - 1 , 1 )
    {
        int j = k;
        while (j > 0 && a[i] >= s[j]) j--;
        if (j == k) s[++k] = 0;
        s[j+1] = max(s[j+1], a[i]);
        F[i] = j+1;
    }

    k = 1;
    memset(s , 0 , sizeof s) ;
    s[1] = a[n];
    F1[n] = 1;
    FORD(i , n - 1, 1 )
    {
        int j = k;
        while (j > 0 && a[i] <= s[j]) j--;
        if (j == k) s[++k] = 1e9+7;
        s[j+1] = min(s[j+1], a[i]);
        F1[i] = j+1;
    }
    int ans = 0 ;
    FORE(i, 1, n )
    {
        ans = max(F1[i] + F[i] - 1, ans);
    }
    cout << ans << endl;

    return 0;
}
