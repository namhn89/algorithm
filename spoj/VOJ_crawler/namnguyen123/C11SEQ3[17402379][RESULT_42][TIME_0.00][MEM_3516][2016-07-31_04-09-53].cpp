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
int f[MAXN],a[MAXN];
void sort1(int x)
{
    FORE(i,1,x)
    {
        FORE(j,i+1,x)
        if(a[i]>a[j])
            swap(a[i],a[j]);
    }
}
int solve(int x)
{
    int i=0;
    int j=x;
    while(j>0)
    {
        i++;
        a[i]=j%10;
        j=j/10;
    }
    sort1(i);
    x=0;
    FORE(j,1,i)x=x*10+a[j];
    return x;
}


int main()
{
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    int n;
    cin>>n;
    f[1]=1;
    FORE(i,2,50)f[i]=solve(2*f[i-1]);
    if(n<=50)cout<<f[n]<<endl;
    else cout<<f[50+(n-50)%6]<<endl;

    return 0;
}
