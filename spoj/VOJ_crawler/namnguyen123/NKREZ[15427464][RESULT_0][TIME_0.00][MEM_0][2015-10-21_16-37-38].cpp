#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
pair<int, int>a[MAXN];
int c[MAXN],b[MAXN],f[MAXN];
int main(){
  freopen("NKREZ2.inp","r",stdin);
 // freopen(".out","w",stdout);
int n;
cin>>n;
for(int i=0;i<n;++i){cin>>a[i].first>>a[i].second;c[i]=a[i].second-a[i].first;}
sort(a,a+n);
int res,MAX;
f[0]=a[0].second-a[0].first;
for(int i=1;i<n;++i)
{
        MAX=0;
    for(int j=0;j<i;++j)
	    if(a[i].first>=a[j].second)
	     { if(MAX<f[j]) MAX=f[j];
	     }
        else break;
     f[i] = max(a[i].second-a[i].first+MAX,f[i-1]);

}
for(int i=0;i<n;i++) if(f[i]>res) res=f[i];
cout<<res;
return 0;
}
