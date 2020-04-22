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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const ll INF=1e9+7;
typedef long long ll;
const int MAXN=1e5+1;
int m,n,a[1001],b[1001],f[1001][1001];
int main(){
  //freopen(".inp","r",stdin);
  //freopen(".out","w",stdout);
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        cin>>a[i];
    for(int j=1; j<=n; j++)
        cin>>b[j];
    f[0][0]=0;
    for(int i=1; i<=m; i++)
        f[i][1]=(a[i]==b[1])?1:f[i-1][1];
    for(int j=1; j<=n; j++)
        f[1][j]=(a[1]==b[j])?1:f[1][j-1];
    for(int i=2; i<=m; i++)
        for(int j=2; j<=n; j++)
    {
        f[i][j]=max(f[i][j-1],max(f[i-1][j],f[i-1][j-1]));
        if(a[i]==b[j])f[i][j]=max(f[i][j],f[i-2][j-2]+1);
    }
    cout<<f[m][n];
return 0;
}
