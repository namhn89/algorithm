using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
string s ;
int dp[MAXN] ;
bool check (int i , int j) {
    int len = j - i + 1 ;
    string a = s.substr(i , len) ;
    string t = a ;
    reverse(t.begin() , t.end()) ;
    if (t == a) return true ;
    else return false ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s ;
    int n = s.size() ;
    s = " " + s ;
    for(int i = 1 ; i <= n ; ++i )
    {
        dp[i] = i ;
        for(int j = 1 ; j <= i - 1 ; ++j ) if ( check(j , i) ) dp[i] = min(dp[i] , dp[j - 1] + 1) ;
    }
    cout << dp[n] << endl;
    return 0;
}
