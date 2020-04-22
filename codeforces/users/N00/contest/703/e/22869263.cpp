using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e3 + 5 ;
const int MAXM = 7e3 + 10 ;
int n ;
long long a[MAXN], k ;
long long divisor[MAXM] ;
pair <int, long long >  f[MAXN][MAXM] ;
long long b[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k ;
    long long t = k ;
    FORE(i, 1, n) cin >> a[i], t /= __gcd(t, a[i]), b[i] = __gcd(a[i], k) ;
    if (t != 1) cout << -1 << endl;
    else
    {
        if (k == 1)
        {
            cout << 1 << " " << min_element(a + 1, a + n + 1) - a << endl;
        }
        else
        {
            int cnt = 0 ;
            for(long long i = 1 ; i * i <= k ; ++ i )
            {
                if(k % i == 0)
                {
                    divisor[++cnt] = i ;
                    if (i * i != k)
                    {
                        divisor[++cnt] = k / i ;
                    }
                }
            }
            sort(divisor + 1, divisor + cnt + 1) ;
            memset( f[0] , 0x3f , sizeof(f[0]) ) ;
            f[0][1] = make_pair(0, 0 ) ;
            FORE(i, 1, n)
            {
                FORE(j, 1, cnt )
                {
                    int v = lower_bound(divisor + 1, divisor + cnt + 1, divisor[j] / __gcd( divisor[j] , b[i] ) ) - divisor ;
                    f[i][j] = min(f[i - 1][j], make_pair(f[i - 1][v].st + 1, f[i - 1][v].nd + a[i]) );
                }
            }
            cout << f[n][cnt].st << endl;
            for(int i = n, j = cnt ; i != 0 ; i--)
            {
                if (f[i - 1][j] != f[i][j] )
                {
                    j = lower_bound(divisor + 1, divisor + cnt + 1, divisor[j] / __gcd ( divisor[j] , b[i] ) ) - divisor ;
                    cout << i << " ";
                }
            }
        }
    }


    return 0;
}
