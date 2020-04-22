using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k ;
    string n ;
    cin >> n >> k ;
   // int x = atoi(n) ;
    int p10 = 1 , ans = 0 ;
    for(int i = 1 ; i <= k ; ++i ) p10 *= 10 ;
    //if (p10 >= x && x % 10 != 0 ) { cout << -1 << endl; return 0 ; }
    for(int i = n.size() - 1 ; i >= 0 ; --i ) {
         if (n[i] != '0') {
            ans++;
         }
         else k--;
         if (k == 0 ) break ;
    }
    int zero = 0 ;
    for(int i = 0 ; i < n.size() ; ++i ) if (n[i] == '0') zero++;
    if (k > 0 && zero == 0) { cout << -1 << endl; return 0 ;}
    if (k > 0 ) { cout << n.size() - 1 << endl ; return 0 ;}
    cout << ans << endl;

    return 0;
}
