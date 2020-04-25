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
const ll INF=1e9+7;
const int MAXN=1e5+1;
/*int nghiem(int x,int y,int z)
{
    ll delta=y*y-4*x*z;
    if(delta<0)
    {
        return 0;
    }
  else if(delta==0)
    {
        return 1;
    }
  else if (delta>0)
    {
        return 2;
    }
}*/
int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    ll b,n,x,y,t,delta;
    cin>>b>>n;
    ll res=0;
    FORE(i,1,2*n)
    {
        t=1ll*b*i*i;
        x=1ll*2*b*n*i;
        y=1ll*n*n;
        delta=(x-t)%y;
        if(delta==0)
        {
            delta=x-t;
            if(delta>0)res++;
        }
    }
    cout<<res<<endl;
    return 0;
}
