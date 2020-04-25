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
const int MAXN = 1e6 + 5 ;
const int INF = 1e9 + 10 ;
int a[MAXN];
int f[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int S, n ;
    int x = 0 ;
    int s = 0 ;
    cin >> n >> S ;
    FORE(i,1,n )
    {
        cin >> a[i];
        x = max(x,a[i]);
        s += a[i];
    }
    int ans = 0 ;
    while(S > s)
    {
        S -= x ;
        ans++;
    }
    FORE(i,1,S) f[i] = INF ;
    f[0] = 0 ;
    FORE(i,1,S )
    {
        FORE(j,1,n)
        {
            if (i >= a[j]) f[i] = min(f[i],f[i-a[j]]+1);
        }
    }
    cout << f[S] + ans << endl;



    return 0;
}
