using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
string S ;
string a[MAXN] ;
int n, m, k ;
int dist_Haming (string S, string b)
{
    S = S + S ;
    int ans = n;
    for(int i = 0 ; i < S.size() / 2 ; ++i )
    {
        string a = S.substr(i, m) ;
        int cnt = 0 ;
        for(int i = 0 ; i < m ; ++i )
        {
            if (a[i] != b[i]) cnt++;
        }
        ans = min(ans, cnt) ;
    }
    return ans ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d %d", &n , &m , &k ) ;
    cin >> S ;
    FORE(i , 1 , k ) cin >> a[i] ;
    int ans = n ;
    FORE(i , 1 , k )
    {
        ans = min(ans , dist_Haming(S, a[i])) ;
    }
    cout << ans << endl;
    return 0;
}
