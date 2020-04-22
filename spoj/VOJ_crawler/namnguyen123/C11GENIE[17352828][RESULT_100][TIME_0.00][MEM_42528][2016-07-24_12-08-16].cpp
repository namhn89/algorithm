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
const int MOD = 1e9 + 7 ;
const int MAXN = 1e7 + 5 ;
int f[MAXN];
vector <int> b ;
inline void sang(int n )
{
    for (int i = 2; i <= n ; i++)
    {
        if (f[i] == 0)
        {
            b.push_back(i);
            for (int j=2; j*i<= n; j++)
                f[i*j] = 1;
        }
    }
}
inline int power(int p, int n)
{
    int res=1, t = p;
    while(n)
    {
        if(n&1) res = (1ll * res * t )%MOD;
        t = (1ll * t * t )%MOD;
        n>>=1;
    }
    return res;
}
inline int get (int p, int n)
{
    int res = 0;
    int t = p;
    while(t <= n)
    {
        res += n/t ;
        t *= p;
    }
    return res;
}
int main()
{
    // freopen("test.inp","r",stdin);
    // freopen(".out","w",stdout);
    int n ;
    scanf("%d",&n);
    sang(n);
    ll res = 1 ;
    // FOR(i , 0 , b.size()) cout << b[i] << endl;
    FOR(i, 0, b.size())
    {
        //cout << power(b[i],get(b[i], n )&~1) << endl;
        res = res * power(b[i],get(b[i], n)&~1)%MOD;
    }
    printf("%lld\n",res);

    return 0;
}
