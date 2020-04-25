using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const long long MOD = 456123123551 ;
const int MAXN = 1e5 + 10 ;
const int N = 1e5 ;
const long long BASE = 31 ;
int n, k ;
char a[61][MAXN] ;
long long Hash[61][MAXN] ;
long long powmod[MAXN] ;
int len[61] ;
inline long long get( int l ,  int r , int row )
{
    return (Hash[row][r] - Hash[row][l - 1] * powmod[r - l + 1] + MOD * MOD) % MOD ;
}
bool check(int d_len )
{
  set <long long> S ;
  set <long long> :: iterator it ;
  map <long long , int > f ;
  FORE(i , 1 , n)
  {
    S.clear() ;
    for(int j = 1 ; j + d_len - 1 <= len[i]; ++j) S.insert( get( j , j + d_len - 1 , i) ) ;
    for(it = S.begin(); it != S.end(); ++ it)
    {
      f[*it]++ ;
      if(f[*it] >= k) return true ;
    }
  }
  return false ;
}
int main()
{
#define TASK "NAME"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    scanf("%d %d", &n , &k ) ;
    powmod[0] = 1 ;
    FORE(i , 1 , n ) scanf("%s", a[i] + 1) ;
    FORE(i , 1 , n ) len[i] = strlen(a[i] + 1) ;
    FORE(i , 1 , *max_element(len + 1 , len + n + 1) ) powmod[i] = (powmod[i - 1] * BASE) % MOD ;
    FORE(i , 1 , n)
        for(int j = 1; j <= len[i] ; ++j) Hash[i][j] = (Hash[i][j - 1] * BASE + a[i][j] - 'A') % MOD ;
    int l = 0 , r = *max_element(len + 1 , len + n + 1) , ans = 0 ;
    while(l <= r)
    {
        int mid = (l + r) / 2   ;
        if(check(mid)) ans = mid , l = mid + 1 ;
        else r = mid - 1 ;
    }
    printf("%d\n", ans) ;
    return 0;
}
