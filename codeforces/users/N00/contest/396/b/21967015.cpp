using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define PI 2 * acos(0)
#define TASK test

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef pair<ll,ll> LL;
typedef vector<int> VI ;
typedef vector<II> VII;
typedef vector< VI> VVI;

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 12 ;
const ll LNF = 1e18;
const int INF = 1e9 + 10 ;
const int BASE = 31 ;
/*struct VP
{
    int x, y, num ;
    VP() {}
    VP(int x, int y, int num) : x(x), y(y), num(num) {}
};
vector<VP> T ;
*/
int f[MAXN] ;
vector <int> prime ;
LL add(LL a, LL b)
{
    ll mau = (a.nd) * (b.nd) ;
    ll tu  = (a.st) * (b.nd) + (b.st) * (a.nd) ;
    ll gcd = __gcd(mau,tu);
    return LL(tu / gcd, mau / gcd);
}
void sang()
{
    for(int i = 2 ; i <= 700010 ; ++i) f[i] = 1 ;
    for(int i = 2 ; i <= sqrt(700010) ; ++i)
    {
        if(f[i])
        {
            for(int j = 2 ; j * i <= 700010 ; ++j)
            {
                f[i*j] = 0 ;
            }
        }
    }
    for(int i = 2 ; i <= 700010 ; ++i) if(f[i])prime.push_back(i);
}
LL F[MAXN] ;
LL sum[MAXN] ;
bool is_prime(long long n )
{
    for (int i = 2; i * i <= n ; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}
int main()
{
    //freopen("VPSUMOFFRACS.inp","r",stdin);
    //freopen("VPSUMOFFRACS.out","w",stdout);
    /* sang();
     int x = 1 ;
     for(int i = 0 ; i < prime.size() - 1 ; ++i)
     {
         for(int j = prime[i] ; j < prime[i + 1] ; ++j )
         {
             x++;
             F[x] = II(1ll, (1ll*prime[i] * prime[i+1]) ) ;
         }
     }
     sum[2] = F[2] ;
     for(int i = 3 ; i <= x ; ++i ) sum[i] = add(sum[i-1], F[i] ) ;
        */
     int Test ;
    scanf("%d",&Test);
    while(Test--)
    {
        long long x ;
        scanf("%lld",&x);
        x++;
        long long u = x , v = x + 1 ;
        while(!is_prime(u)) u--;
        while(!is_prime(v)) v++;
        //cout << u << " " << v << endl;
        long long a =  u * v - 2 * v + 2 * (x - u) ;
        long long b =  2 * u * v ;
        long long d = __gcd(a,b);
        cout << a/d << "/" << b/d << endl;
        // printf("%lld/%lld\n",sum[x].st,sum[x].nd);
    }

    return 0;
}
