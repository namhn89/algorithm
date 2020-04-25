using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXN = 1e5 + 5 ;
long long n ;
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
inline void read (long long &x)
{
    register char c = getchar();
    x = 0;
    bool neg = 0;
    for(; ((c < '0' || c > '9') && c != '-'); c = getchar());
    if (c == '-')
    {
        neg = 1;
        c = getchar();
    }
    for(; c >= '0' && c <= '9'; c=getchar())
        x = (x << 1) + (x << 3) + (c - '0');
    if(neg)
        x = -x;
}
void DFS(int u , int parent )
{
    P[u] = log10(a[u]) ;
    int pos = 0 ;
    double Max = 0.0000 ;
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
    f[0] = 1 ;
    P[0] = 0.0 ;
    read(n) ; read(mod) ;
    FORE(i , 1 , n ) read(a[i]) ;
    FORE(i , 1 , n - 1 )
    {
        long long u , v ;
        read(u) ; read(v) ;
        g[u].push_back(v) ;
        g[v].push_back(u) ;
    }
    DFS(1, 0) ;
    printf("%lld\n", f[1]) ;

    return 0;
}
