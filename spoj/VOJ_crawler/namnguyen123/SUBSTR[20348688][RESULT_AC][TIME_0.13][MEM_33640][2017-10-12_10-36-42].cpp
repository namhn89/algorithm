using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
unsigned long long Hash[MAXN] , pw[MAXN] ;
unsigned long long BASE = 1097 ;
char a[MAXN] , b[MAXN] ;
unsigned long long Get_Hash (int l , int r) {
   return Hash[r] - Hash[l - 1] * pw[r - l + 1] ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> a + 1 ;
    cin >> b + 1 ;
    int n = strlen(a + 1) ;
    pw[0] = 1 ;
    for(int i = 1 ; i <= n ; ++i ) pw[i] = pw[i - 1] * BASE ;
    int t = strlen(b + 1) ;
    for(int i = 1 ; i <= n ; ++i ) {
        Hash[i] = Hash[i - 1] * BASE + (a[i] - '0') ;
    }
    unsigned long long HashT = 0 ;
    for(int i = 1 ; i <= t ; ++i ) {
        HashT = HashT * BASE + (b[i] - '0') ;
    }
    for(int i = 1 ; i <= n - t + 1 ; ++i ) {
        if (Get_Hash(i , i + t - 1) == HashT) {
            cout << i << " " ;
        }
    }

    return 0;
}
