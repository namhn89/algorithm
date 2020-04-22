using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int N = 1e6 + 1 ;
int F[N] ;
int a[MAXN] ;
int n, C ;
vector <int> g[MAXN] ;
int cnt[10][N] ;
long long ans[N] , c[10][10] , mul2[MAXN] , mulc[12] ;
long long power (long long a, long long n)
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
}
void Sang ()
{
    F[0] = F[1] = 1 ;
    for(int i = 2 ; i < N ;  ++i )
    {
        if (F[i] != 0 ) continue  ;
        for(int j = i ; j < N ; j += i) F[j] = i  ;
    }
}
void prev ()
{
    for(int i = 0 ; i < 9 ; ++ i ) c[0][i] = 1;
    for(int i = 1 ; i < 9 ; ++ i )
        for(int j = i ; j < 9 ; ++ j)
            c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % MOD ;
    mulc[0] = 1;
    mul2[0] = 1;
    for(int i = 1 ; i <= n; ++ i) mul2[i] = (mul2[i - 1] * 2 ) % MOD ;
    for(int i = 1 ; i < 11; ++ i) mulc[i] = (mulc[i - 1] * C ) % MOD;
}
int main()
{
#define TASK "VO17XXX"
  //   freopen(TASK".inp","r",stdin);
  //   freopen(TASK".out","w",stdout);
    Sang() ;
    scanf("%d %d", &n , &C);
    FORE(i , 1 , n ) scanf("%d",&a[i]) ;
    FORE(i , 1 , n )
    {
        while(a[i] > 1)
        {
            g[i].push_back(F[a[i]]) ;
            a[i] /= F[a[i]] ;
        }
        sort(g[i].begin() , g[i].end()) ;
        g[i].resize(unique(g[i].begin() , g[i].end()) - g[i].begin()) ;
    }
    FORE(i , 1 , n )
    {
        for(int mask = 0 ; mask < (1 << g[i].size()) ; ++mask)
        {
            int val = 1;
            for(int j = 0 ; j < g[i].size() ; ++j )
            {
                if ( (1 << j ) & mask ) val *= g[i][j] ;
            }
            cnt[__builtin_popcount(mask)][val] ++ ;
        }
    }
    prev() ;
    memset(ans, 0, sizeof (ans)) ;
    long long res = 0 ;
    for(int i = 8; i >= 0; -- i)
    {
        for(int j = 1 ; j < N ; ++ j) ans[i] += (mul2[cnt[i][j]] - 1) % MOD ;
        for(int j = i + 1 ; j <= 8 ; ++ j) ans[i] = ( (ans[i] - 1ll * c[i][j] * ans[j]) % MOD + MOD ) % MOD;
        res += (mulc[i] * ans[i]) % MOD ;
        res %= MOD ;
    }
    printf("%lld\n",res) ;
    return 0;
}
