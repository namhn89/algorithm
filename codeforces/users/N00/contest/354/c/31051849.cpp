using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const int oo = 1e9 ;
int cnt[MAXN] , n , k , a[MAXN] ;
int Min , Max ;
int main()
{
#define TASK "354C"
    // freopen(TASK".inp","r",stdin);
     //freopen(TASK".out","w",stdout);
    Min = oo ;
    Max = 0 ;
    scanf("%d %d" ,&n , &k) ;
    for(int i = 1 ; i <= n ; ++i ) {
        scanf("%d" , &a[i]) ;
        cnt[a[i]]++ ;
        Min = min(Min , a[i]) ;
        Max = max(Max , a[i]) ;
    }
    if (k + 1 >= Min) {
        cout << Min << endl ;
        return 0 ;
    }
    for (int i = 1 ; i <= Max ; ++i ) cnt[i] += cnt[i - 1] ;
    for (int ans = Max ; ans >= k ; --ans) {
        int D = Max / ans ;
        int h = 0 ;
        for(int i = 1 ; i <= D ; ++i ) {
            int r = min(i * ans + k , Max) ;
            int l = i * ans ;
            h += cnt[r] - cnt[l - 1] ;
        }
        if (h == n) {
            cout << ans ;
            return 0 ;
        }
    }


    return 0;
}
