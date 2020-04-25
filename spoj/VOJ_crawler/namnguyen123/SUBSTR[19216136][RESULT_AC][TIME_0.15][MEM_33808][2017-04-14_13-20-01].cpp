using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const unsigned long long BASE = 1097 ;
unsigned long long Hash[MAXN] , power[MAXN] ;
unsigned long long HashT = 0 ;
int n , m ;
string S , T ;
unsigned long long getHash(int l, int r)
{
    return Hash[r] - Hash[l - 1] * power[r - l + 1] ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    cin >> S >> T ;
    int m = T.size() ;
    int n = S.size() ;
    T = " " + T ;
    S = " " + S ;
    power[0] = 1 ;
    for(int i = 1 ; i <= n ; ++i) power[i] = power[i - 1] * BASE ;
    for(int i = 1 ; i <= m ; ++i) HashT = HashT * BASE + (T[i] - '0') ;
    for(int i = 1 ; i <= n ; ++i) Hash[i] = Hash[i - 1] * BASE + (S[i] - '0') ;
    for(int i = 1 ; i <= n - m + 1 ; ++i) if(getHash(i , i + m - 1) == HashT) cout << i << " ";
    return 0;
}
