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
const int MAXN=1e5+1;
const int INF =1e9+1;
ll a[MAXN],f[MAXN],l1,l2,l3,c1,c2,c3,s,n,m;
int main()
{
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3 ;
    cin >> n ;
    cin >> s >> m;
    a[1] = 0;
    FORE(i, 2 ,n)cin >> a[i] ;
    ll v,k;
    FORE(i, s+1 , m)
    {
        f[i]=INF;
        FORD(j, i-1 ,s)
        {
             k = a[i]-a[j];
            if (k > l3) break ;
            if (k > l2) v = c3;
            else if (k > l1) v = c2 ;
            else v = c1;
            f[i]=min(f[j]+v,f[i]);
        }
    }
    cout<<f[m]<<endl;

    return 0;
}
