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
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
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
const int MAXN=1e3+1;
int a[MAXN][MAXN],f[MAXN][MAXN],b[MAXN][MAXN];
int main()
{
     // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int ans=-INT_MAX;
    int n,k;
    cin>>n>>k;
    FORE(i,1,n)
    {
        FORE(j,1,n)
        {
            cin>>a[i][j];
        }
    }
    FORE(i,1,n)
    {
        FORE(j,1,n)
        {
            b[i][j]=b[i][j-1]+a[i][j];
        }
    }
    FORE(i,1,n)
    {
        FORE(j,1,n)
        {
           f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
    }
    FORE(i,1,n)
    {
        FORE(j,1,n)
        {
            ans=max(ans,f[i][j]-f[i-k][j]-f[i][j-k]+f[i-k][j-k]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
