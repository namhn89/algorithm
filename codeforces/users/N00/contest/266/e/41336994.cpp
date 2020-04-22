using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int MAXK = 7 ;
int n , q ;
long long a[MAXN] ;
long long Tree[8 * MAXN][MAXK] , pw[8 * MAXN][MAXK] , c[7][7] , Spw[MAXN][MAXK] , pwl[MAXN][MAXK] , lazy[8 * MAXN] ;
void Init () {
   for (int i = 0; i < MAXK; ++i)
	{
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j] ;
	}

	pw[0][0] = 1 ;
	for (int i = 1; i <= n; ++i) {
		pw[i][0] = pwl[i][0] = 1;
		Spw[i][0] = i;
	}
    for(int k = 1 ; k < MAXK ; ++k) {
        for (int i = 1; i <= n; ++i) {
            pw[i][k] = (1LL * pw[i][k - 1] * i) % MOD ;
            pwl[i][k] = ((pwl[i][k - 1] * (1 - i) % MOD) + MOD) % MOD ;
            Spw[i][k] = (Spw[i - 1][k] + pw[i][k]) % MOD ;

        }
    }
}
void build (int k , int l , int r) {
    if (l == r) {
        for(int p = 0 ; p < 6 ; ++p ) Tree[k][p] = (1LL * a[l] * pw[l][p]) % MOD ;
        return ;
    }
    int mid = (l + r) / 2 ;
    build (2 * k , l , mid) ;
    build (2 * k + 1 , mid + 1 , r) ;
    for(int p = 0 ; p < 6 ; ++p ) Tree[k][p] = (Tree[2 * k][p] + Tree[2 * k + 1][p]) % MOD ;
}
void push_down (int k , int l , int r) {
    if (lazy[k] == -1) return ;
    int x = lazy[k] ;
    for(int p = 0 ; p < 6 ; ++p ) Tree[k][p] = (1LL * x % MOD  * (Spw[r][p] - Spw[l - 1][p] + MOD) % MOD ) % MOD ;
    lazy[2 * k] = lazy[2 * k + 1] = lazy[k] ;
    lazy[k] = -1 ;
}
void update (int k , int l , int r , int u , int v , int x) {
     push_down(k , l , r) ;
     if (r < u || l > v) return ;
     if (u <= l && r <= v) {
            lazy[k] = x ;
            push_down(k , l , r) ;
            return ;
     }
     int mid = (l + r) / 2 ;
     update (2 * k , l , mid , u , v , x) ;
     update (2 * k + 1 , mid + 1 , r , u , v , x) ;
     for(int p = 0 ; p < 6 ; ++p ) Tree[k][p] = (Tree[2 * k][p] + Tree[2 * k + 1][p]) % MOD ;
}
long long query (int k , int l , int r , int u , int v , int x) {
    push_down(k , l , r) ;
     if (r < u || l > v) return 0;
     if (u <= l && r <= v) {
          long long res = 0 ;
          for(int p = 0 ; p <= x ; ++p) {
             res = (res + (1LL * (1LL * c[x][p] * pwl[u][x - p] % MOD) * Tree[k][p]) % MOD) % MOD ;
          }
          return res ;
     }
     int mid = (l + r) / 2 ;
     return (query (2 * k , l , mid , u , v , x) + query(2 * k + 1 , mid + 1 , r , u , v , x)) % MOD ;
}

int main()
{
#define TASK "QUERRYARR"
     //  freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n ,&q) ;
    Init() ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%lld", &a[i]) ;
    for(int i = 1 ; i < 4 * n ; ++i ) lazy[i] = -1 ;
    build(1 , 1 , n) ;
    while(q--) {
        int l , r , x ;
        char type ;
        //scanf("%d %d %d %d",&type , &l , &r , &x) ;
        cin >> type >> l >> r >> x ;
        if (type == '=') {
            update (1 , 1 , n , l , r , x) ;
        }
        else {
            long long ans = query (1 , 1 , n , l , r , x) ;
            if (ans < 0) ans += MOD ;
            printf("%lld\n" , ans) ;
        }
    }



    return 0;
}