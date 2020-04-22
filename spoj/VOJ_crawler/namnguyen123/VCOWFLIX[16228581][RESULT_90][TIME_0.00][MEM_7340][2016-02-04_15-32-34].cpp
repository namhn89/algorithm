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
const int MAXN=1e5+1;
int a[5000];
int  f[20][50000];
int main()
{
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    int m,n ;
    memset(f, sizeof f , 0 );
    cin >> m >> n;
    for (int i = 1; i <= n; i++ )
    {
        cin >> a[i] ;
    }
    FORE(i,1,n)
    {
        FORE(j,1,m)
        {
            f[i][j]=f[i-1][j];
            if(j>a[i]&&f[i][j]<f[i-1][j-a[i]]+a[i])
                f[i][j]=f[i-1][j-a[i]]+a[i];

        }

    }
cout<<f[n][m]<<endl;



    return 0;
}
