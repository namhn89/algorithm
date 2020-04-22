using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 3e5 + 5 ;
long long n , k ;
long long a[MAXN] , b[MAXN] , c[MAXN] , S[MAXN] ;
int m ;
long long Add (long long u , long long v) {
   if (u + v >= k ) return k ;
   else return u + v ;
}
long long Mul (long long u , long long v) {
    if (v == 0 ) return 0 ;
    if (u >= (k + v - 1) / v) return k ;
    else return (long long) (u * v) ;
}
struct Matrix
{
    long long data[20][20] ;
    void Reset ()
    {
        for(int i = 0 ; i <= 15 ; ++i )
            for(int j = 0 ; j <= 15 ; ++j ) data[i][j] = 0 ;
    }
    Matrix operator * (Matrix b)
    {
        Matrix res ;
        res.Reset() ;
        Matrix a = *this ;
        for(int i = 1 ; i <= 15 ; ++i )
            for(int j = 1 ; j <= 15 ; ++j )
                for(int k = 1 ; k <= 15 ; ++k ) res.data[i][j] = Add(res.data[i][j] , Mul(a.data[i][k] , b.data[k][j])) ;
        return res ;
    }
    Matrix power (long long n)
    {
        Matrix res ;
        Matrix a = *this ;
        res.Reset() ;
        for(int i = 1 ; i <= 15 ; ++i ) res.data[i][i] = 1 ;
        while(n)
        {
            if (n & 1) res = (res * a) ;
            a = a * a ;
            n >>= 1 ;
        }
        return res ;
    }
};
int main()
{
#define TASK "test"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%lld %lld", &n , &k) ;
    for(int i = 1 ; i <= n ; ++i ) scanf("%lld", &a[i]) ;
    m = n ;
    int pos = 1;
    while (a[pos] == 0) ++pos;
    int cnt = 0 ;
    for (int i = pos ; i <= m ; ++i) a[++cnt] = a[i];
    n = cnt ;
    if (n > 10)
    {
        int ans = 0 ;
        while(1)
        {
            for(int i = 1 ; i <= n ; ++i ) {
                if (a[i] >= k) {
                    cout << ans ;
                    return 0 ;
                }
                a[i] += a[i - 1] ;
            }
            ans++ ;
        }
    }
    else {
        Matrix base ;
        Matrix T ;
        base.Reset() ;
        T.Reset() ;
        for(int i = 1 ; i <= n ; ++i ) T.data[1][i] = a[i] ;
        for(int i = 1 ; i <= n ; ++i ) {
            for(int j = i ; j <= n ; ++j ) base.data[i][j] = 1 ;
        }
        long long ans , Low = 0 , High = k ;
        while(Low <= High) {
            long long Mid = (Low + High) / 2 ;
            Matrix res ;
            res.Reset() ;
            res = T * base.power(Mid) ;
            bool ok = false ;
            for(int i = 1 ; i <= n ; ++i ) if (res.data[1][i] >= k) ok = true ;
            if (ok) { ans = Mid , High = Mid - 1 ; }
            else Low = Mid + 1 ;
        }
        cout << ans ;
    }
    return 0;
}
