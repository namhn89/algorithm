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
const int INF =1e9;
int a[MAXN];
int main ()
{
      //freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int n,m ;
    cin >> n >> m;
    FORE( i, 1, n ) scanf("%d",&a[i]);
    int MAX = 0;
    sort(a + 1 , a + n + 1 );
    FORD ( i , n , 1 )
    {
        FORD(j , i - 1 , 1 )
        {
            {
               if(a[i] + a[j] >= m ) break ;
               int it = lower_bound(a + 1 , a + j - 1    , m - a[i] - a[j] ) - a;
               if (a[it] + a[i] + a[j] >= MAX && a[i] + a[j] + a[it] <= m) {
                    MAX = a[it] + a[i] + a[j];
                     //cout << a[it] << " " << a[j] <<" " << a[i] <<" " << MAX <<endl;
               }

            }

        }
    }
    printf("%d\n",MAX);
    return 0;
}
