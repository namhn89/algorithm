using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 20 + 5 ;
int half ;
map <long long , long long> f[MAXN][MAXN] ;
long long n , m , k ;
long long a[MAXN][MAXN] ;
long long ans = 0 ;
int f1 , f2 ;
void dfs (int x , int y , long long val) {
    if (x > n || y > m) return ;
    val ^= a[x][y] ;
    if (x + y == half ) {
        f[x][y][val] ++ ;
        return ;
    }
    dfs(x + 1 , y , val) ;
    dfs(x , y + 1 , val) ;
}
void dfs_again (int x , int y , long long val) {
    if (x < 1 || y < 1) return ;
    if (x + y == half ) {
        ans += f[x][y][k ^ val] ;
        return ;
    }
    val ^= a[x][y] ;
    dfs_again(x - 1 , y , val) ;
    dfs_again(x , y - 1 , val) ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%lld %lld %lld", &n , &m , &k) ;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j) scanf("%lld", &a[i][j]) ;
    half = (n + m + 2) / 2 ;
    dfs(1 , 1 , 0) ;
    dfs_again(n , m , 0) ;
    cout << ans ;

    return 0;
}
