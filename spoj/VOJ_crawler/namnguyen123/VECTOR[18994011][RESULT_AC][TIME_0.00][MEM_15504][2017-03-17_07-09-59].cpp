using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e2 + 5 ;
int n, x[MAXN], y[MAXN], a[MAXN], b[MAXN] , U , V;
map < pair < int, int> , int> F;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout) ;
    cin >> n ;
    int S1 = n / 2 ;
    int S2 = (n + 1) / 2 ;
    for(int i = 0 ; i < S1 ; ++i ) cin >> x[i] >> y[i] ;
    for(int i = 0 ; i < S2 ; ++i ) cin >> a[i] >> b[i] ;
    cin >> U >> V ;
    for(int mask = 0 ; mask < (1 << S1) ; ++mask )
    {
        int S_x = 0, S_y = 0 ;
        for(int i = 0 ; i < S1 ; ++i) if ( (mask >> i) & 1 ) S_x += x[i], S_y += y[i] ;
        F[make_pair(S_x, S_y)]++;
    }
    long long ans = 0 ;
    for(int mask = 0 ; mask < (1 << S2) ; ++mask )
    {
        int S_x = 0, S_y = 0 ;
        for(int i = 0 ; i < S2 ; ++i) if ( (mask >> i) & 1 ) S_x += a[i], S_y += b[i] ;
        ans += F[make_pair(U - S_x , V - S_y)] ;
    }
    cout << ans << endl;
    return 0;
}
