using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 5 ;
int n ;
long long a[MAXN] ;
long long k ;
struct Matrix
{
    long long data[103][103] ;
    Matrix() {
       memset(data , 0 , sizeof(data)) ;
    }
    Matrix operator * (Matrix g)
    {
        Matrix res ;
        Matrix t = *this;
        FORE (x , 0 , n)
        {
            FORE (y , 0 , n)
            {
                FORE (z , 0 , n)
                {
                    res.data[x][y] = (res.data[x][y] + t.data[x][z] * g.data[z][y]) % MOD;
                    res.data[x][y] %= MOD;
                }
            }
        }
        return res;
    }
    Matrix power(long long p)
    {
        Matrix t = *this ;
        Matrix res ;
        for(int i = 0 ; i < n ; ++i ) res.data[i][i] = 1 ;
        while (p)
        {
            if (p & 1LL) res = (res * t);
            t = t * t;
            p >>= 1LL;
        }
        return res;
    }
};
int main()
{
    Matrix base ;
    cin >> n >> k ;
    for(int i = 0 ; i < n ; ++i ) cin >> a[i] ;
    for(int i = 0 ; i < n ; ++i )
        for(int j = 0 ; j < n ; ++j ) if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0) base.data[i][j] = 1 ;
    base = base.power(k - 1) ;
    long long ans = 0 ;
    for(int i = 0 ; i < n ; ++i )
        for(int j = 0 ; j < n ; ++j ) ans = (ans + base.data[i][j]) % MOD ;
    cout << ans << endl;
    return 0;
}
