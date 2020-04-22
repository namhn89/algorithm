#include<cstdio>
using namespace std;
 
typedef long long int ll;
 
int main()
{
    int n,tg;
    ll max=0,m1=0,m2=0,m3;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&tg);
        m3=m1;
        if(m1<m2+tg) m1=m2+tg;
        if(m2<m3-tg) m2=m3-tg;
    }
    if(m1>max) max=m1;
    if(m2>max) max=m2;
    printf("%lld",max);
}