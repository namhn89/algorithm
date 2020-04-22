using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 5e2 + 5 ;
int n ;
long long a[MAXN][MAXN] , row[MAXN] , col[MAXN] , cnt1 = 0 , cnt2 = 0 ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n ;
    int x , y ;
    for(int i = 0 ; i < n ; ++i )
        for(int j = 0 ; j < n ; ++j )
        {
            cin >> a[i][j] ;
            if (a[i][j] == 0) x = i , y = j ;
            row[i] += a[i][j] ;
            col[j] += a[i][j] ;
            if (i == j) cnt1 += a[i][j] ;
            if (i + j == n - 1) cnt2 += a[i][j] ;
        }
    if (n == 1) {
        cout << 1 ; return 0 ;
    }
    long long ans = row[(x + 1) % n] - row[x] ;
    if (ans <= 0 ) {
        cout << -1 ; return 0 ;
    }
    row[x] += ans ;
    col[y] += ans ;
    if (x == y) cnt1 += ans ;
    if (x + y == n - 1) cnt2 += ans;
    if (cnt1 == cnt2) {
        long long val = cnt1 ;
        bool ok = true ;
        for(int i = 0 ; i < n ; ++i ) {
            if (col[i] == val && row[i] == val) continue ;
            ok = false ;
        }
        if (ok) cout << ans << endl;
        else cout << -1 << endl;
    }
    else cout << -1 << endl;
    return 0;
}
