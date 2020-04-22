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
int a[MAXN];
//freopen(".inp","r",stdin);
//freopen(".out","w",stdout);
ll n,m,k,l,r,mid,ans;
 
int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    l=0;
    r=n*m+1;
    while(l+1<r)
    {
        mid=(l+r)/2;
        ans=0;
        for(int i=1; i<=n; ++i) ans+=min(m,mid/i);
        if(ans<k) l=mid;
        else r=mid;
    }
    printf("%lld",r);
 
 
 
return 0;
}