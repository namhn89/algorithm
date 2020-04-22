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
int res;
for(int i=0;i<n;++i){
        f[i]=c[i];
    for(int j=0;j<i;++j){
            if (f[j]+(a[i].second - a[i].first)>f[i]&&a[j].second<=a[i].first) f[i]=f[j]+c[i];
}
}
for(int i=0;i<n;i++) if(f[i]>res) res=f[i];
cout<<res;
return 0;
}