using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 30 ;
long long dp[MAXN][MAXN][MAXN][MAXN] ;
long long A , B , D , K ;
vector <int> digit ;
long long calc (int x , int y , int z , int t) {
    if (z < 0) return 0 ;
    if (dp[x][y][z][t] != -1) return dp[x][y][z][t] ;
    if (x == 1) return dp[x][y][z][t] = 1 ;
    long long res = 0 ;
    if (t) {
        for(int i = 0 ; i < 10 ; ++i )
            res += calc( x - i , i , z - (abs(i - y) <= D) , t) ;
    }
    else {
        for(int i = 0 ; i <= digit[x - 1] ; ++i )
             if (i < digit[x - 1])  res += calc (x - i , i , z - (abs(i - y) <= D) , 1) ;
        else res += calc(x - i , i , z - (abs(i - y) <= D) , 0) ;
    }
    return dp[x][y][z][t] = res ;
}
long long solve (long long n) {
   if (n == 0) return 0 ;
   digit.clear() ;
   while (n) {
       digit.push_back(n % 10) ;
       n /= 10 ;
   }
   digit.push_back(0) ;
   long long ans = 0 ;
      for(int i = 1 ; i < digit.size() ; ++i) {
            if (i + 1 < digit.size()) {
                for(int j = 0 ; j < 10 ; ++j) ans += calc(i , j , K , 1) ;
            }
            else {
                for(int j = 1 ; j < digit[i] ; ++j) ans += calc(i , j , K , 1) ;
                ans += calc(i , digit[i] , K , 0) ;
            }
   }
   return ans ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(dp , 0xff , sizeof(dp)) ;
    cin >> A >> B >> D >> K ;
    cout << solve(B) - solve(A - 1) << endl ;
    return 0;
}
