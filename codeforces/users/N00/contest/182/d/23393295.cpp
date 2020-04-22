using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const long long MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;
const int BASE = 1097 ;
char S[MAXN] ;
char T[MAXN] ;
long long HashS[MAXN] , HashT[MAXN] , powmod[MAXN] ;
long long getHashS (int L , int R ) {
    return ( HashS[R] - HashS[L - 1]  * powmod[R - L + 1] + MOD * MOD ) % MOD ;
}
long long getHashT (int L , int R ) {
    return ( HashT[R] - HashT[L - 1]  * powmod[R - L + 1] + MOD * MOD ) % MOD ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%s", S + 1) ;
    scanf("%s", T + 1) ;
    int n = strlen(S + 1) ;
    int m = strlen(T + 1) ;
    powmod[0] = 1 ;
    FORE(i , 1 , max(m , n) ) powmod[i] = (powmod[i - 1] * BASE) % MOD ;
    FORE(i , 1 , n ) HashS[i] = (HashS[i - 1] * BASE + (S[i] - '0')) % MOD ;
    FORE(i , 1 , m ) HashT[i] = (HashT[i - 1] * BASE + (T[i] - '0')) % MOD ;
    vector <int> len ;
    for(int i = 1 ; i <= min(m , n) ; ++i ) if (n % i == 0 && m % i == 0) len.push_back(i) ;
    int ans = 0 ;
    for(int i = 0 ; i < len.size() ; ++ i ) {
        bool checkS = true ;
        bool checkT = true ;
        long long X = getHashS(1 , len[i]) ;
        long long Y = getHashT(1 , len[i]) ;
        if (X != Y) continue ;
        for(int j = len[i] ; j + len[i] <= n ; j += len[i] ) if (getHashS(j + 1 , j + len[i]) != X ) {checkS = false ; break; }
        for(int j = len[i] ; j + len[i] <= m ; j += len[i] ) if (getHashT(j + 1 , j + len[i]) != Y ) {checkT = false ; break; }
        if (checkS && checkT) ans++;
    }
    printf("%d", ans);

    return 0;
}
