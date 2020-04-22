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
int a[MAXN],f[MAXN];
int main(){
  //freopen(".inp","r",stdin);
  //freopen(".out","w",stdout);
  int n,k;
  int ans=0;
  cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) {
        f[i] = -1e9;
        for(int j=1;j<=k;++j) {
            f[i] = max(f[i], f[i-j] + a[i]);
            ans = max(ans, f[i]);
        }
    }
    cout<<ans;
return 0;
}
