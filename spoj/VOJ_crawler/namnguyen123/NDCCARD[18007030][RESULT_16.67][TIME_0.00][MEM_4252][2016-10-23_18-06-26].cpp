using namespace std;
#include <bits/stdc++.h>
#define for1(i,a,b) for(int i=a,_b=(b);i<_b;i++)
#define for2(i,a,b) for(int i=a,_b=(b);i<=_b;i++)
#define op freopen("in.inp","r",stdin);freopen("ou.out","w",stdout);
#define TR(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define m(s) memset(s,0,sizeof s);
#define fd(i,a,b) for(int i=a,_b=(b);i>=_b;i--)
#define st first
#define nd second
#define TASK ...
typedef long long ll;
typedef pair<int,int> II;
const int MAXN=2e5+1;
const int INF=1e9+9;
int a[MAXN];
int main(){
     int n,m;cin>>n>>m;
     for2(i,1,n)scanf("%d",&a[i]);
     sort(a+1,a+n+1);
     int best=0;
     for(int i=1;i<=n;++i)
     for(int j=1;j<=n;++j){
        int pos = upper_bound(a+1 , a+n+1 , m-a[i]-a[j])-a;
        pos--;
        if(pos==n)continue;
        if(a[i]+a[j]+a[pos] > best && i!=j && j!=pos && i!=pos) best = a[i]+a[j]+a[pos];
        if(a[i]+a[j]+a[pos] == m && i!=j && j!=pos && i!=pos){cout<<m;return 0;}
     }
     cout<<best;


}
