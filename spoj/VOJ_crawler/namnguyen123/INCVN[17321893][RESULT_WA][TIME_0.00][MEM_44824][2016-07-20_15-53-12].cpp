using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
const int MOD = 5e6;
const int MAXN = 1e5 + 5 ;
ll f[51][MAXN];
ll a[MAXN];
int n, K ;
ll t[MAXN];
ll getf(int i)
{
    ll res = 0 ;
    while (i <= n )
    {
        res = (t[i] + res )%MOD;
        i += i&(-i);
    }
    return res ;
}
void change (int v, ll value)
{
    while(v > 0 )
    {
        t[v] =  (t[v] + value)% MOD  ;
        v -= (v&(-v));
    }
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&K);
    FORE(i, 1, n ) scanf("%d",&a[i]);
    /* FORE(i, 1, n )
     {
         f[i][1] = 1 ;
         FOR(j, 1, i )
         {
             if(a[i] > a[j] )
             {
                 FOR(k, 1, K )
                 {
                     f[i][k+1] += (f[j][k]%MOD);
                     f[i][k+1] %= MOD;
                 }
             }
         }
     }
     ll ans = 0 ;
     FORE(i , 1 , n ){
     ans = (ans + f[i][K]) % MOD ;
     }
     printf("%lld\n",ans);

     */

    ll ans =  0;
    FORE(i, 1, n ) f[1][i] = 1;
    FORE(i, 2, K )
    {
        FORE(j, 1, n ) t[j] = 0;
        FORD(j, n, 1 )
        {
            f[i][j] = getf(a[j] + 1);
            change(a[j], f[i-1][j]);
        }
    }
    //FORE(i, 1, n ) cout << f[K][i] << " " ;
   // cout << endl;
    FORE(i, 1, n )
    {
        ans = (ans + f[K][i]) % MOD ;
    }
    printf("%lld\n",ans);


    return 0;
}
