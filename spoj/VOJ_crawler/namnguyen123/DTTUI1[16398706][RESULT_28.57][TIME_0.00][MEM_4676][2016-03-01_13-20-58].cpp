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
int a[MAXN],v[MAXN],w[MAXN],f[101][101];
int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    int n,m;
    cin>>n>>m;
    FORE(i,1,n)cin>>w[i]>>v[i];
    FORE(i,1,n)
    {
        FORE(j,1,m)
        {
            if (j < w[i]) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+v[i]);


        }
    }
cout<<f[n][m]<<endl;
/*while(n){
    { if(f[n][m]!=f[n-1][m])
     { cout << n << " ";
       m-=w[n];
     }
    n--;
  }
}*/
    return 0;
}
