using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const int N = 1e6 + 1;
const int MAXD = 30 ;
const int D = 25 ;
int P[MAXN] ;
int F[MAXN][MAXD] ;

void sieve ()
{
    P[1] = 1;
    for(int i = 2 ; i <= N ; ++i )
    {
        if (!P[i]) for(int j = i ; j <= N ; j += i ) P[j] = i ;
    }
}

void prev () {
   for(int i = 0 ; i <= D ; ++i ) F[0][i] = 2 ;
   for(int i = 0 ; i <= N ; ++i ) F[i][0] = 1 ;
   for(int i = 1 ; i <= N ; ++i ) {
     for(int j = 1 ; j <= D ; ++j ){
         F[i][j] = (F[i][j - 1] + F[i - 1][j]) % MOD ;
     }
   }
}

long long solve (int r , int n) {
    long long res = 1 ;
    while(n != 1) {
        int p = P[n] ;
        int cnt = 0 ;
        while(n % p == 0) n /= p , cnt ++ ;
        res = (res * F[r][cnt]) % MOD;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    memset(P , 0 , sizeof(P)) ;
    sieve()  ;
    prev() ;
    int Q ;
    scanf("%d",&Q) ;
    while(Q--){
        int r , n ;
        scanf("%d %d",&r ,&n) ;
        printf("%lld\n",solve(r , n)) ;
    }
    return 0;
}
