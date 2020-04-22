using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 2012 ;
const int MAXN = 1e5 + 5 ;
const int N = 60 ;

int n , x , step ;
vector < pair <int , int>  > Edeges ;
struct Matrix
{
    long long data[62][62] ;
    Matrix() {
       memset(data , 0 , sizeof(data)) ;
    }
    Matrix operator * (Matrix g)
    {
        Matrix res ;
        Matrix t = *this;
        FORE (x , 0 , N)
        {
            FORE (y , 0 , N)
            {
                FORE (z , 0 , N)
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
        p--;
        Matrix res = t;
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
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> x >> step ;
    for(int i = 1 ; i <= n ; ++i ) {
        int j = (i == n ? 1 : i + 1) ;
        Edeges.push_back(make_pair(i , j)) ;
        Edeges.push_back(make_pair(j , i)) ;
        Edeges.push_back(make_pair(i + n , j + n)) ;
        Edeges.push_back(make_pair(j + n , i + n)) ;
        Edeges.push_back(make_pair(i , i + n)) ;
        Edeges.push_back(make_pair(i + n , i )) ;
    }
    Matrix base , res ;
    for(int i = 0 ; i <= N ; ++i )
        for(int j = 0 ; j <= N ; ++ j) base.data[i][j] = 0 , res.data[i][j] = 0;
    for(int i = 0 ; i < Edeges.size() ; ++i )
         for(int j = 0 ; j < Edeges.size() ; ++j ) {
            int u = Edeges[i].st , v = Edeges[i].nd;
            int x = Edeges[j].st , y = Edeges[j].nd ;
            if (u != y && x == v) base.data[i][j] = 1 ;
    }
    for(int i = 0 ; i < Edeges.size() ; ++i) if (Edeges[i].st == x) base.data[N][i] = 1 ;
    res.data[0][N] = 1 ;
    long long ans = 0 ;
    base = base.power(step) ;
    res = res * base ;
    for(int i = 0 ; i < Edeges.size() ; ++i ) {
        if (Edeges[i].nd != 1) continue ;
        ans = (ans + res.data[0][i]) % MOD ;
    }
    cout << ans << endl;



    return 0;
}
