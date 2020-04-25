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
double P[MAXN] ;
long long mul (long long a , long long n )
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
void DFS(int u , int parent )
{
    P[u] = log10(a[u]) ;
    int pos = 100001 ;
    double Max = -1.0 ;
    TR(g[u] , it )
    {
        if (*it == parent ) continue ;
        DFS(*it , u) ;
        if (Max < P[*it]) Max = P[*it] , pos = *it ;
    }
    P[u] += P[pos] ;
    f[u] = mul(a[u] , f[pos]) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    f[100001] = 1 ;
    P[100001] = 0 ;
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
