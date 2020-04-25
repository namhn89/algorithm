using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 1e5 + 5 ;
int n ;
long long mod ;
vector <int> g[MAXN] ;
long long f[MAXN] ;
long long a[MAXN] ;
long long mul (long long a, long long n )
{
    a %= mod ;
    long long res = 0 ;
    while(n)
    {
        if (n & 1) res = (res + a) % mod ;
        a = (a + a) % mod ;
        n >>= 1 ;
    }
    return res ;
}
void DFS(int u, int parent )
{
    long long Max = 1 ;
    TR(g[u] , it )
    {
        if (*it == parent ) continue ;
        DFS(*it , u) ;
        Max = max(Max , f[*it]) ;
    }
    f[u] = mul(a[u] , Max) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %lld", &n, &mod );
    FORE(i , 1 , n ) scanf("%lld", &a[i]) ;
    FORE(i , 1 , n - 1 )
    {
        int u, v ;
        scanf("%d %d", &u, &v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    DFS(1, 0) ;
    cout << f[1] << endl;

    return 0;
}
