using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e5 + 100;
const int MOD = 998244353; 

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
 
int fact[N], infact[N]; 
 
int nCr(int n, int r) {
  int ans = fact[n]; 
  ans = mul(ans, infact[r]); 
  ans = mul(ans, infact[n - r]);
  return ans; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m; 
  cin >> n >> m; 
  fact[0] = fact[1] = 1; 
  for (int i = 1; i <= m; ++i) fact[i] = mul(fact[i - 1], i); 
  for (int i = 1; i <= m; ++i) infact[i] = inv(fact[i]); 
  int ans; 
  if (n <= 2) {
    cout << 0; 
    return 0; 
  }
  ans = nCr(m, n - 1);
  ans = mul(ans, power(2, n - 3)); 
  ans = mul(ans, n - 2); 
  cout << ans; 


     
  return 0;
}