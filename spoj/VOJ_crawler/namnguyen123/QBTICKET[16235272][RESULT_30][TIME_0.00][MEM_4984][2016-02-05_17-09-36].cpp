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
const int MAXN=1e5+100;
const int INF =10000000000000+1;
ll min(ll a , ll b) {return (a < b) ? a : b ;}
ll a[MAXN],f[MAXN];
int l1,l2,l3,c1,c2,c3,s,n,e;
int d(int i , int j){ return a[i] - a[j] ; }
int main()
{//
   //  freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3 ;
    cin >> n ;
    cin >> s >> e;
    FORE(i, 2 ,n) cin >> a[i];
    a[1] = 0;
    sort(a+1,a+n+1);
    if(s > e ) swap(s,e);
    f[s]=0;
    FORE(i, s+1 , e)
    {
        f[i]=INF;
        FORD(j, i-1 ,s)
        {
            ll v;
            if (d(i,j) > l3) break ;
            if (d(i,j) > l2) v = c3;
            else if (d(i,j) > l1) v = c2 ;
            else v = c1;
            f[i]=min(f[i], f[j]+v);
        }
    }
    cout<<f[e]<<endl;

    return 0;
}
