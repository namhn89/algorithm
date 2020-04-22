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
int tong[100] = {0}; 
int a[100] = {0}; 
int sl[100] = {0};
int c, n, kl, i, j, d;
int main(){
  // freopen(".inp","r",stdin);
  // freopen(".out","w",stdout);
    cin >> c >> n;
    for (i = 0; i < n; i++ )
    {
        cin >> a[i] ;
    }
    for ( j=0;j < n; j++)
    {
        d = 1;
        for (i = j; i < n; i++)
        {
            tong[j] = a[i] + tong[j];
            sl[j]++ ;
            d++ ;
            if ( tong[j] > c)
            {
                tong[j] = tong[j] - a[i] ;
                sl[j]--;
            }
            if ( i+1 == n)
                i = i- n;
            if (d == n) break;
        }
    }
    kl = 0;
    for( i = 0; i < n; i++ )
        if ( tong[i] > kl )
        {
            kl = tong[i] ;
            j = i;
        }

    cout << kl << endl;


return 0;
}
