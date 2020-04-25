#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;
int a[MAXN],b[MAXN];
int c[MAXN],f[MAXN];
//..............................................
void qsort(int a[], int b[], int l, int r)
{
  int x = b[(l+r)/2];
  int i = l, j = r;
  while(i<=j)
  {
    while(b[i]<x) i++;
    while(b[j]>x) j--;
    if(i<=j)
    {
      swap(a[i], a[j]);
      swap(b[i], b[j]);
      i++; j--;
    }
  }
  if(i<r) qsort(a, b, i, r);
  if(l<j) qsort(a, b, l, j);
}
//...............................................
int main()
{
//freopen("NKREZ2.inp","r",stdin);
int n;
long long res=0;
cin>>n;
for(int i=0;i<n;++i)
    { cin >> a[i]>> b[i];
      c[i]=b[i]-a[i];
    }
qsort(a,b,0,n-1);
f[0]=b[0]-a[0];
int MAX;
for(int i=0;i<n;++i){
        MAX=0;
    for(int j=0;j<i;++j){
            if (MAX<f[j] && b[j]<=a[i]) {
                    MAX=f[j];
            }
            else break;
     f[i] = max(b[i]-a[i]+MAX,f[i-1]);
}
}
for(int i=0;i<n;i++) if(f[i]>res) res=f[i];
cout<<res;
return 0;
}
