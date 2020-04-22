#include<stdio.h>
#include<algorithm>
using namespace std;
double vc=1000005;
struct bi
{
int id;
double h; //he so goc tan anpha
};

bool Timcap(bi *B,int L,int R,int &p,int &q) //giong quicksort nhung de tim 2 cap giong nhau
{
if(L>=R) return false;
swap(B[L],B[(L+R)/2]);
int i=L;
for(int j=L+1;j<=R;j++)
{
if(B[L].h==B[j].h) {p=L;q=j;return true;}
if(B[j].h<B[L].h) {i++; swap(B[i],B[j]);}
}
if(Timcap(B,L+1,i,p,q)) return true;
if(Timcap(B,i+1,R,p,q)) return true;
return false;
}

int main()
{
int n,k,p,q;
long x[2005],y[2005];
bi B[2005];
scanf("%d",&n);
k=2*n;
for(int i=1;i<=k;i++) scanf("%ld%ld",&x[i],&y[i]);
for(int i=1;i<=n;i++)
{
for(int j=n+1;j<=k;j++)
{
if(x[i]==x[j]) B[j].h=vc; else B[j].h=double(y[j]-y[i])/(x[j]-x[i]);
B[j].id=j;
}
if(Timcap(B,n+1,k,p,q)) {printf("%d %d %d",i,B[p].id,B[q].id); return 0;}
}
for(int i=n+1;i<=k;i++)
{
for(int j=1;j<=n;j++)
{
if(x[i]==x[j]) B[j].h=vc; else B[j].h=double(y[j]-y[i])/(x[j]-x[i]);
B[j].id=j;
}
if(Timcap(B,1,n,p,q)) {printf("%d %d %d",i,B[p].id,B[q].id); return 0;}
}
printf("-1");
}