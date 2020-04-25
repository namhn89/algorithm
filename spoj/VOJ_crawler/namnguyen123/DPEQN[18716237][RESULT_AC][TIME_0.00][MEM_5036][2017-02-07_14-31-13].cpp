using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define FOR(i,a,b) for(int i=(a),b_=(b);i<b_;++i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
typedef pair < long long, long long > LL ;

long long gcd(long long a, long long b)
{
    if (a == 0) return b;
    else return gcd(b % a, a);
}

LL extended_gcd(long long  a, long long b)
{
    LL M, N ;
    if (b == 0 ) return LL (1, 0);
    else
    {
        M = LL (a / b, a % b);
        N = extended_gcd(b, M.nd);
        return LL(N.nd, N.st - M.st * N.nd);
    }
}

long long g[MAXN], x[MAXN];
vector <long long> c ;
vector <long long> ans ;

bool congruenceEquation (vector <long long> a , long long b , long long m , vector<long long> &res)
{
    int n = a.size();
    a.push_back(m);
    g[0] = a[0];
    FORE(i , 1 , n ) g[i] = gcd(g[i - 1] , a[i]);
    res.clear();
    if (b % g[n]) return false;
    int val = b / g[n] ;
    FORD(i , n , 1 )
    {
        LL W = extended_gcd (g[i - 1], a[i]);
        x[i] = (W.nd * val) % m;
        val = (W.st * val) % m;
    }
    x[0] = val;
    FORE(i , 0 , n ) x[i] = (x[i] + m) % m;
    FOR(i , 0 , n ) res.push_back(x[i]);
    return true;
}

int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    long long n , b , m , Test ;
    scanf("%lld",&Test) ;
    while(Test--)
    {
        c.clear() ;
        scanf("%lld", &n);
        for(int i = 1 ; i <= n ; ++i )
        {
            long long x ;
            scanf("%lld",&x) ;
            c.push_back(x) ;
        }
        scanf("%lld %lld", &b , &m) ;
        if (congruenceEquation(c , b , m , ans) )
        {
            TR(ans , it) printf("%lld ", *it) ; printf("\n") ;
        }
        else printf("NO\n") ;
    }
    return 0;
}
