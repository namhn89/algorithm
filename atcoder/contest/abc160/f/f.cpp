using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e5 + 1;
const int MOD = 1e9 + 7; 

int add (int a, int b) {
  return (a += b) >= MOD ? a - MOD : a;
}
 
int sub (int a, int b) {
  return (a -= b) < 0 ? a + MOD : a;
}
 
int mul (int a, int b) {
  return (long long) a * b % MOD;
}
 
int power(int a, long long n) {
  int res = 1;
  while(n) {
    if (n & 1LL) res = mul(res, a);
    a = mul(a, a);
    n >>= 1LL;
  }
  return res;
}
int inv(int a) {
  return power(a, MOD - 2);
}

 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; 

     
  	return 0;
}