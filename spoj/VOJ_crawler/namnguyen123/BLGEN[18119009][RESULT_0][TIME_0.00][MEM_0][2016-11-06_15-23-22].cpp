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
const int MAXN=2500+1;
char a[MAXN],b[MAXN];
int f[MAXN][MAXN];
int main()
{
    //freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int m,n;
    cin>>m>>n;
    FORE(i,1,m)
    {
        cin >> a[i];
    }
    FORE(i,1,n)
    {
        cin >> b[i];
    }
    FORE(i,1,m)
    {

        FORE(j,1,n)
        {
            if (a[i]==b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout<<f[m][n];

    return 0;
}
