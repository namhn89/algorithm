
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
const int MAXN = 10000001;
int a[MAXN];
int f[MAXN];
int b[MAXN];
int F[MAXN];
int main()
{
    // freopen("test.inp","r",stdin);
      // freopen(".out","w",stdout);
  /* FORE(i, 3, 200)
    {
        FORE(j, i + 1,200)
        {
            FORE(k, j + 1, 200)
            {
                if (i*i + j*j == k*k)
                {
                    f[i+j+k]++;
                }
            }
        }
    }
    FORE(i, 1, 300)
    {
        if (f[i] == 1)
        {
            F[i] = F[i-1] + 1 ;
        }
        else F[i] = F[i-1];

    }*/
    FORE( x, 2, 4000)
    {
        for(int y = x % 2 ? 2 : 1 ; y < x && x *( x + y ) < MAXN ; y += 2)
        {
            if(__gcd( x, y) > 1) continue;
            int u = x *( x + y );
            int v = u ;
            while(u < MAXN )
            {
                a[u] ++, u+=v ;
            }
        }
    }
    FORE(i , 6 , MAXN)
    {
        if (a[i] == 1)
        {
            b[i] = b[i-1] + 1;
        }
        else b[i] = b[i-1];
    }
    int x ;
    while(cin >> x)
    {
        printf("%d\n",b[x/2]);
        //cout << F[x] ;
       // cout << endl;
    }
    return 0;
}
