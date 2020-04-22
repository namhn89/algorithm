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
const int MAXN=1e2+1;
const int INF = 1e9;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int MAX(int a,int b,int c)
{
    return max(a,max(b,c));
}
int main()
{
   // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int m,n;
    cin >> m >> n;
    FORE(i, 1, m)
    {
        FORE(j, 1, n)
        {
            cin >> a[i][j];

        }
    }
    FORE(i, 1, m)
    {
        f[i][1] = a[i][1];
    }
    FORE(i, 0, n+1)
    {
        f[0][i] = -INF;
        f[m+1][i] = -INF ;
    }
    FORE(j, 2, n)
    {
        FORE(i, 1, m)
        {
            f[i][j]= max(f[i][j-1], max (f[i-1][j-1], f[i+1][j-1]))+a[i][j];
        }
    }
    int best = -INF;

    FORE(i, 1, m) best = max(best, f[i][n]);

    cout << best <<endl;

    return 0;
}
