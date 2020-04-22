using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e6 + 5 ;
const int N = 1e6 + 1 ;
int P[MAXN] , SUMDIV[MAXN] ;
void sieve () {
   for (int i = 2 ; i <= N ; ++i)
      for (int j = 2 * i ; j <= N ; j += i ) SUMDIV[j] += i ;
}
int main()
{
#define TASK "PHONGPHU"
     //freopen(TASK".inp" ,"r" ,stdin);
     //freopen(TASK".out" ,"w" ,stdout);
    sieve() ;
    int L , R , ans = 0 ;
    cin >> L >> R ;
    for(int i = L ; i <= R ; ++i ) if (SUMDIV[i] > i) ans ++ ;
    cout << ans ;
    return 0;
}
