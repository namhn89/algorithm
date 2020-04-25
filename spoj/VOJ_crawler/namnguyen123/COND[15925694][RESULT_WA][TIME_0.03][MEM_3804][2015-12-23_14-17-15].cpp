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
const int MAXN=1e5+1;
int a[MAXN];
ll gt(int n)
{
    ll s=1;
    FORE(i,1,n)s*=i;
    return s;
}
int main()
{
    //freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    int n;
    int t=1;
    while(t)
    {
        cin>>n;
        if(n==2)cout<<3<<endl;
        else if(n!=-1)cout<<gt(n)*2*(n-2)+1<<endl;
        else t=0;
    }
    return 0;
}
