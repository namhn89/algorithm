using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

const int MOD = 1e9 + 7 ;
const int MAXN = 1e5 + 5 ;

int Q, T ;
long long N, K ;

inline string convers (int a)
{
  string res ;
  do { res.push_back(a % 10 + '0') ; a /= 10 ; } while(a) ;
  reverse(res.begin(), res.end()) ;
  return res ;
}

int sum (int a)
{
  int res = 0 ;
  do { res += a % 10 ; a /= 10 ; } while(a) ;
  return res ;
}

bool opera (int a , int b)
{
  string sa = convers(a) , sb = convers(b) ;
  for(int i = 0; i < min(sa.size() , sb.size()); ++i) return (sa[i] < sb[i]) ;
}

bool cmp (int a , int b)
{
  if(sum(a) != sum(b)) return sum(a) < sum(b) ;
  return opera(a , b) ;
}

int a[MAXN] , r[MAXN] ;

int main()
{
  for(int i = 1; i <= 500000 ; ++i) a[i] = i ;
  scanf("%d",&Q) ;
  while(Q--)
  {
    scanf("%d %lld %lld", &T , &N , &K) ;
    sort(a + 1 , a + 1 + N , cmp) ;
    FORE(i , 1 , N) r[a[i]] = i ;
    if(T == 0) printf("%d\n", r[K]) ;
    if(T == 1) printf("%d\n", a[K]) ;
  }
  return 0 ;
}
