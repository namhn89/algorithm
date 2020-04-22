using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 3e8 + 5 ;
const int N = 3e8 ;
bitset <MAXN> P ;
void prev() {
    for(int i = 3 ; i * i <= N ; i += 2){
         if (P[i] == 0) for(int j = i * i ; j <= N ; j += 2 * i ) P[j] = 1 ;
    }
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    prev() ;
    int L , R ;
    cin >> L >> R ;
    int ans = 0 ;
    for(int i = 5 ; i <= R ; i += 4) {
         if (i >= L && P[i] == 0) ans++;
    }
    if (L <= 2 && R >= 2 ) ans++;
    cout << ans << endl;
    return 0;
}
