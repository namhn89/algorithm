#include<bits/stdc++.h>
using namespace std;
int n,b[2010],dem,res;
pair<int,int>a[2010];
map<int,int>c,d,v;
int main()
{
   // freopen("seq198.inp","r",stdin);
//freopen("seq198.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
      {
        int p;
        cin>>p;
        if(d[p]==0)
        {
            dem++;
            c[p]=dem;
            b[dem]=p;
            a[dem].second=p;
        }
        d[p]++;
      }
    for(int i=1;i<=dem;i++)
      {
        a[c[b[i]+1]].first+=d[b[i]];
        a[c[b[i]-1]].first+=d[b[i]];
        a[c[b[i]+8]].first+=d[b[i]];
        a[c[b[i]-8]].first+=d[b[i]];
        a[c[b[i]+9]].first+=d[b[i]];
        a[c[b[i]-9]].first+=d[b[i]];
      }
    sort(a+1,a+dem+1);
    int kt=0;
    int i=dem;
    while(kt==0)
    {
        v[a[i].second]=1;
        res+=d[a[i].second];
        kt=1;
        for(int j=1;j<=dem-1;j++)
        if(v[a[j].second]==0)
        {
            for(int h=j+1;h<=dem;h++)
            if(v[a[h].second]==0)
                {
                     int p=abs(a[j].second-a[h].second);
                     if(p==1||p==8||p==9) {kt=0;break;}
                }
            if(kt==0) break;
         }
         i--;
    }
    cout<<res;
    return 0;
}
