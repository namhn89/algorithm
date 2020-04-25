using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 1 ;
long long f[MAXN][MAXN][MAXN][3] ;
int W , B , R , K , M ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> W >> B >> R >> K >> M ;
    ///  f[i][j][k][color] : i số màu xanh , j số màu đỏ , k số vị trí thỏa mãn , color thanh gỗ cuối cùng . 0 xanh , 1 đỏ
    for(int i = 1 ; i <= B ; ++i) f[i][0][0][0] = 1 ;
    for(int i = 1 ; i <= R ; ++i) f[0][i][0][1] = 1 ;
    for(int i = 1 ; i <= B ; ++i )
        for(int j = 1 ; j <= R ; ++j )
            for(int p = 1 ; p <= M ; ++p )
                 for(int color = 0 ; color <= 1 ; ++color ) {
                  if (color == 0) {
                    f[i][j][p][color] += f[i - 1][j][p][color] ;
                    f[i][j][p][color] += f[i - 1][j][p - 1][color ^ 1] ;
                  }
                  else {
                    f[i][j][p][color] += f[i][j - 1][p][color] ;
                    f[i][j][p][color] += f[i][j - 1][p - 1][color ^ 1] ;
                  }
                 f[i][j][p][color] %= MOD ;
                 // cout << i << " " << j << " " << p << " " << color << " " << f[i][j][p][color] << endl;
        }
    long long ans = f[B][R][M][0] + f[B][R][M][1] ;
    ans %= MOD ;
    cout << ans << endl;
    /// 0 10 10 8 3
    return 0;
    // 0 2 2 4 4
}
