using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define BG begin()
#define ED end()
#define SZ size()
#define PB push_back
#define PF push_front
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e5+5;
int t[MAXN],r[MAXN];
int f[MAXN];
int main()
{
     freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int n ;
    cin >> n ;
    FORE(i, 1, n ) cin >> t[i] ;
    FORE(i, 1, n - 1  ) cin >> r[i] ;
    f[1] = t[1] ;
    FORE(i, 2, n)
    {
        f[i] = min(f[i-1] + t[i] , f[i-2] + r[i-1]);
    }
    cout << f[n] << endl;





    return 0;
}
