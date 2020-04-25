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
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
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
const int MAXN=1e6+5;
int a[MAXN];
int l[MAXN],r[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int n;
    cin >> n ;
    FORE(i, 1, n) cin >> a[i];
    stack<int> sl;
    sl.push(0);
    for (int i=1;i<=n;i++)
    {
        while(!sl.empty() && a[i]<=a[sl.top()])sl.pop();
        if(!sl.empty())        l[i]=sl.top();
        sl.push(i);
    }
    stack<int> sr;
    sr.push(n+1);
    for (int i=n;i>0;i--)
    {
        while(!sr.empty() && a[i]<=a[sr.top()]) sr.pop();
        if(!sr.empty())        r[i]=sr.top();
        sr.push(i);
    }
    int res=0;
    for (int i=1;i<=n;i++)
        if(r[i]-l[i]-1 >= a[i]) res=max(res,a[i]);
    printf("%d",res);

    return 0;
}
