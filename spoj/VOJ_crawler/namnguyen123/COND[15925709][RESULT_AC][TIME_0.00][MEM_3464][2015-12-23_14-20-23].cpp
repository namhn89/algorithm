#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long LL;
const int MAXN = 10;
const int INF = 1000000001;
int n;
LL f[MAXN+10][MAXN+10];
LL g[MAXN+10];
int main(){
f[0][0] = 1;
for (int i=1;i<=MAXN;i++)
for (int j=1;j<=i;j++)
f[i][j] = f[i-1][j-1]+j*f[i-1][j];
g[0] = 1;
for (int i=1;i<=MAXN;i++)
g[i] = g[i-1]*i;
scanf("%d", &n);
while(n>=0){
      LL res = 0;
      for (int k=1;k<=n;k++)
res += f[n][k]*g[k];
      printf("%lld\n", res);
      scanf("%d", &n);
}
return 0;
}
