using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int n ;
int x[MAXN] , y[MAXN] , U , V;
map < pair <int , int > , int> F ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL) ;
    cin >> n ;
    int n1 = n / 2 ;
    int n2 = (n + 1) / 2 ;
    for(int i = 0 ; i < n1 ; ++i ) {
        cin >> x[i] >> y[i] ;
    }
    for(int mask = 0 ; mask < (1 << n1) ; ++mask ) {
        int S = 0 , T = 0 ;
        for(int i = 0 ; i < n1 ; ++i ) {
            if ((mask >> i) & 1) {
                S += x[i] ;
                T += y[i] ;
            }
        }
        F[make_pair(S , T)] ++ ;
    }
    for(int i = 0 ; i < n2 ; ++i ) {
        cin >> x[i] >> y[i] ;
    }
    cin >> U >> V ;
    long long ans = 0 ;
    for(int mask = 0 ; mask < (1 << n2) ; ++mask) {
        int S = 0 , T = 0 ;
        for(int i = 0 ; i < n2 ; ++i ) {
            if ((mask >> i) & 1) {
                S += x[i] ;
                T += y[i] ;
            }
        }
        ans += F[make_pair(U - S , V - T)] ;
    }
    cout << ans ;

    return 0;
}
