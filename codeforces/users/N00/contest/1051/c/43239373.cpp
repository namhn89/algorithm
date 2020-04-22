using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int a[MAXN] ;
int cnt[MAXN]  , p[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n ;
    cin >> n ;
    set <int> myset ;
    int Max = 0 ;
    for (int i = 1 ; i <= n ; ++i ) {cin >> a[i] ; cnt[a[i]] ++ ; myset.insert(a[i]) ; Max = max(Max , a[i]) ;  }
    for (int i = 1 ; i <= n ; ++i ) p[a[i]]++ ;

    int cnt_one = 0 ;
    for (int i = 1 ; i <= Max ; ++i ) if (cnt[i] == 1) cnt_one ++ ;
    int two_more = 0 ;
    for (int i = 1 ; i <= Max ; ++i ) if (cnt[i] > 2) {
        two_more = i ;
        break ;
    }
    if (cnt_one & 1 && two_more == 0) {
        cout << "NO" ; return 0 ;
    }
    else {
        cout << "YES" << endl;
        int z = (cnt_one + 1) / 2 ;
        if (cnt_one % 2 == 0) {
        for (int i = 1 ; i <= n ; ++i ) {
            if (cnt[a[i]] >= 1) {
                if (z > 0 && a[i] != two_more) {
                    cout << "A" ;
                    cnt[a[i]]--;
                    if (p[a[i]] == 1) z-- ;
                }
                else cout << "B" ;
            }
        }
        }
        else {
            z-- ;
            for (int i = 1 ; i <= n ; ++i ) {
                if ((z > 0 && cnt[a[i]] == 1) || a[i] == two_more) {
                    cout << "A" ;
                    if (two_more == a[i]) two_more = -1 ;
                    if (p[a[i]] == 1) z-- ;
                }
                else cout << "B" ;
            }

        }
    }

    return 0;
}
