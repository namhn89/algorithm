using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int get (int n, int p)
{
    int res = 0 ;
    while(n)
    {
        res += n / p ;
        n /= p ;
    }
    return res ;
}
int patern[MAXN] ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s ;
    cin >> s ;
    int n = s.size() ;
    int cnt2 = get(n , 2) , cnt5 = get(n , 5) ;
    for(int i = 0 ; i < n ; ++i ) patern[s[i] - 'a']++;
    for(int i = 0 ; i <= 25 ; ++i ) {
        cnt2 -= get(patern[i] , 2 ) ;
        cnt5 -= get(patern[i] , 5 ) ;
    }
    cout << min(cnt2 , cnt5) << endl ;


    return 0;
}
