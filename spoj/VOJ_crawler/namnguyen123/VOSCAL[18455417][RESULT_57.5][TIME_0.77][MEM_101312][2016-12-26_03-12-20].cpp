using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MAXM = 5e3 + 5 ;
int c[MAXM][MAXM] ;
const int X = 5001 ;
int n, m, mod ;
void sub12 ()
{
    for(int i = 0 ; i < X ; ++i ) c[i][i] = 1, c[i][0] = 1 ;
    for(int i = 2 ; i < X ; ++i )
    {
        for(int j = 1 ; j < i ; ++j )
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod ;
        }
    }
}
long long moduloInverse(long long a, long long m)
{
    long long q, r, y0 = 0, y1 = 1, y, m0 = m  ;
    while (a > 0)
    {
        q = m / a;
        r = m % a;
        if (!r) return (y % m0 + m0) % m0;
        y = y0 - y1 * q ;
        y0 = y1 ;
        y1 = y ;
        m = a ;
        a = r ;
    }
}
long long power(long long a, long long n )
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1) res = (res * a) % mod ;
        a = (a * a) % mod ;
        n >>= 1 ;
    }
    return res ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> n >> m >> mod ;
    int N = m + n - 1 ;
    int R = m - 1 ;
    if (max(N , R) <= 5000 )
    {
        sub12() ;
        cout << c[N][R] << endl;
    }
    else
    {
        if (N < R) cout << 0 << endl;
        else
        {
            long long ans = 1;
            for (int i = 1 ; i <= R ; ++ i ) ans = (ans * (N - R + i) ) % mod ;
            for (int i = 1 ; i <= R ; ++ i ) ans = (ans * power(i , mod - 2 ) ) % mod ;
            cout << ans << endl;
        }
    }
    return 0;
}
