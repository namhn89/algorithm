using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
pair <long long , int> a[MAXN] ;
int n ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i ) {
        int x , y , z , k ;
        cin >> x >> y >> z >> k ;
        a[i].st = x + y + z + k ;
        a[i].nd = -i ;
    }
    sort(a + 1, a + n + 1) ;
    reverse(a + 1 , a + n + 1) ;
    for(int i = 1 ; i <= n ;  ++i) {
        if (a[i].nd == -1) {
            cout << i  ;
            return 0 ;
        }
    }


    return 0;
}
