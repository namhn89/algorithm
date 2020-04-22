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
#define NAME TASK
#define openfile freopen("TASK.inp","r",stdin);freopen("TASK.out","w",stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD=1e9+7;
const int MAXN=1e3+1;
int a[MAXN];
int f[MAXN];
/*int Binary_Search(int x,int n)
{
    int l=1, r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]==x) return mid;
        if(a[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return -1;
}*/
int main()
{
//  freopen(".inp","r",stdin);
// freopen(".out","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        f[i]=1;
        for(int j=1; j<i; j++)
        {
            int toado=binary_search(a+1,a+n+1,a[i]-a[j]);
            if(toado>=1)
            {
                if(2*a[j]!=a[i]&&f[j]+1>f[i])
                    f[i]=f[j]+1;
               else {
                    if(a[toado+1]==a[toado] || a[toado-1]==a[toado]&&f[j]+1>f[i])
                       f[i]=f[j]+1;
               }
            }
        }
        if(f[i]>ans) ans=f[i];
    }
    cout<<ans;

    return 0;
}
