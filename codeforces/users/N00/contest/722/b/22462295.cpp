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
int a[MAXN];
char s[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    scanf("%d",&n);
    FORE(i, 1, n ) scanf("%d",&a[i]);
    int res = 0 ;
    getchar();
    FORE(i, 1, n )
    {
        gets(s + 1);
        int l = strlen(s + 1);
        int cnt = 0 ;
        FORE(j, 1, l)
        {
            if(s[j] == 'a' || s[j]=='e' || s[j]=='i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'y') cnt++;
        }
        if(cnt == a[i]) res++;
       // cout << cnt << endl;
    }
    if (res == n) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}