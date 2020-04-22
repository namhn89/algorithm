using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
char next (char c) {
  int x = c - '0' ;
  x-- ;
  return char (x + '0') ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s ;
    bool ok = false ;
    cin >> s ;
    int l = -1 , r = -1 ;
    for(int i = 0 ; i < s.size() ; ++i) if (s[i] != 'a'){
        l = i ;
        ok = true ;
        break ;
    }
    r = l ;
    while(s[r + 1] != 'a' && r < s.size()) r++;
    if (!ok) {
       s[s.size() - 1] = 'z' ;
       for(int i = 0 ; i < s.size() ; ++i) cout << s[i] ;
    }
    else {
        for(int i = l ; i <= r ; ++i ) s[i] = next(s[i]) ;
        for(int i = 0 ; i < s.size() ; ++i) cout << s[i] ;
    }

    return 0;
}
