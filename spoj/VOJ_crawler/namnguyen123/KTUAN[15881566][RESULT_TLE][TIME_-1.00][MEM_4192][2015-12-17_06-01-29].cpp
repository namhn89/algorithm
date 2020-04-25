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
const int MAXN=1e5+1;
int a[MAXN],b[MAXN];//f[MAXN][MAXN];
int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    int n;
    cin>>n;
    /*f[0][0]=1;
    FORE(i,1,n)f[i][0]=1;
    FORE(i,1,n)
    {
        FORE(j,0,n)
        {
            if(i>j)f[i][j]=f[i-1][j];
            else f[i][j]=f[i-1][j]+f[i][j-i];
        }
    }
    cout<<f[n][n];*/
    memset(a,0,sizeof(a));
    a[0]=1;
    FORE(i,1,n)
    {
        FORE(j,i,n)
        {
           a[j]=a[j]+a[j-i];

        }
    }
    cout<<a[n]%MOD<<endl;
    return 0;
}
