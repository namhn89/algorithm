using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const long long MOD = 1e9 + 7 ;
const int MAXN = 2e5 + 5 ;
const int N = 2e5 + 1 ;
long long power(long long a, long long n)
{
    a %= MOD ;
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1;
    }
    return res ;
}
long long infact[MAXN], fact[MAXN] ;
long long ans[MAXN] ;
long long calc (int x, int y, int u, int v )
{
    int a = u - x  ;
    int b = v - y  ;
    long long res = fact[a + b] ;
    res = (res * infact[a]) % MOD ;
    res = (res * infact[b]) % MOD ;
    return res ;
}
int main()
{
#define TASK "TASK"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    fact[0] = infact[0] = 1 ;
    for(int i = 1 ; i <= N ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    for(int i = 1 ; i <= N ; ++i ) infact[i] = (infact[i - 1] * power(i, MOD - 2) ) % MOD ;
    memset(ans, 0, sizeof (ans)) ;
    vector < pair <int, int> > node ;
    int n, m, k ;
    scanf("%d %d %d", &n, &m, &k ) ;
    for(int i = 1 ; i <= k ; ++i )
    {
        int x, y  ;
        scanf ("%d %d",&x, &y) ;
        node.push_back(make_pair(x, y)) ;
    }
    node.push_back(make_pair(n, m) ) ;
    sort(node.begin(), node.end()) ;
    for(int i = 0 ; i < node.size() ; ++i )
    {
        for(int j = 0 ; j < i ; ++ j )
        {
            if (node[i].nd >= node[j].nd) ans[i] = (ans[i] - ans[j] * calc(node[j].st, node[j].nd, node[i].st, node[i].nd)) % MOD;
        }
        ans[i] = (ans[i] + calc(1, 1, node[i].st, node[i].nd) ) % MOD ;
    }
    printf("%lld\n", (ans[node.size() - 1] + MOD ) % MOD ) ;
    return 0;
}
