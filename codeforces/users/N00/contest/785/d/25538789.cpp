using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 4e5 + 5 ;
long long invfact[MAXN], fact[MAXN] ;
long long power (long long a, long long n)
{
    long long res = 1 ;
    while(n)
    {
        if (n & 1)  res = (res * a) % MOD ;
        a = (a * a) % MOD ;
        n >>= 1 ;
    }
    return res ;
}
long long nCr (int n, int r)
{
    if (r > n) return 0 ;
    return ( (fact[n] * invfact[n - r] % MOD ) * invfact[r] ) % MOD ;
}
int cnt_R[MAXN] , cnt_L[MAXN];
char s[MAXN] ;
long long calc (int x , int y ) { return nCr(x + y - 1, y - 1); }
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    fact[0] = invfact[0] = 1 ;
    for(int i = 1 ; i < MAXN ; ++i ) fact[i] = (fact[i - 1] * i) % MOD ;
    for(int i = 1 ; i < MAXN ; ++i ) invfact[i] = power(fact[i], MOD - 2) ;
    scanf("%s",s + 1) ;
    int n = strlen(s + 1) ;
    long long ans = 0 ;
    for(int i = 1 ; i <= n ; ++i ) cnt_L[i] = cnt_L[i - 1] + (s[i] == '(') ;
    for(int i = n ; i >= 0 ; --i ) cnt_R[i] = cnt_R[i + 1] + (s[i] == ')') ;
    for(int i = 1 ; i <= n ; ++i ) if (s[i] == '(') ans = (ans + calc(cnt_L[i], cnt_R[i]) ) % MOD ;
    cout << ans << endl ;
    return 0;
}
