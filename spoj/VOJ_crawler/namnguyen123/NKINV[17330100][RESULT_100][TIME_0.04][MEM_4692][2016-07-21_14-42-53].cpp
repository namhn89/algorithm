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
const int MAXN=1e5+5;
pair<int, int>  a[MAXN];
int f[MAXN];
int t[MAXN];
int b[MAXN];
int n,q;
int  getf(int i)
{
    ll ret = 0 ;
    while (i > 0)
    {
        ret+=f[i];
        i-=i&(-i);
    }
    return ret ;
}
void change (int v, int value)
{
    while(v<=n)
    {
        f[v]+= value ;
        v += (v&(-v));
    }
}

int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    ll ans = 0;
    scanf("%d",&n);
    FORE(i , 1 , n ) {scanf("%d",&a[i].st);a[i].nd = i ; }
    sort(a + 1 , a + n + 1);
    FORE(i , 1 , n ) a[i].st = i ;
    FORE(i , 1 , n ) b[a[i].nd] = a[i].st ;
    FORD(i , n , 1) {
        ans +=  getf(b[i]);
        change (b[i] + 1 , 1 );
    }
    cout << ans << endl;
    return 0;
}
