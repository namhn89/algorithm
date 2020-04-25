using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e6 + 1;
const int M = 1e3 + 1; 
const long long P = 1e6; 

int n, m; 
long long mod;

long long mul (long long a, long long b) {
  long long x = a / P;
  long long y = a % P; 
  long long xx = b / P; 
  long long yy = b % P; 
  long long ans = (x * xx) % mod; 
  ans = (ans * P) % mod; 
  ans = (ans * P) % mod; 
  ans = (ans + (x * yy * P) % mod) % mod; 
  ans = (ans + (y * xx * P) % mod) % mod; 
  ans = (ans + (y * yy) % mod) % mod;
  return ans; 
}
int cnt[N], f[N]; 

void sieve() {
  for(int i = 1; i <= N; ++i) f[i] = i; 
  for(int i = 2; i * i <= N; ++i) {
    if (f[i] == i) {
      for (int j = 2 * i; j < N; j += i) {
        f[j] = i;
      }
    }
  }
}

long long power (long long a, long long n) {
  long long ans = 1; 
  while (n) {
    /* code */
    if (n & 1LL) {
      ans = mul(ans, a); 
    }
    a = mul(a, a); 
    n >>= 1LL; 
  }
  return ans; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> m >> n >> mod; 
  sieve(); 
  int k = m * m - n * n; 
  for (int i = 1; i <= k; ++i) {
    int z = i; 
    while(z != 1) {
      int t = f[z]; 
      while(z % t == 0) {
        z /= t; 
        cnt[t]++; 
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (i > m - n && j > m - n) { 
        continue; 
      }
      int row = m - i; 
      int col = m - j; 
      if (j > (m - n)) {
        row = max(0, row - n); 
      }
      if (i > (m - n)) {
        col = max(0, col - n); 
      }
      long long z = col + row + 1; 
      while(z != 1) {
        int t = f[z]; 
        while(z % t == 0) {
          cnt[t]--; 
          z /= t; 
        }
      }
    }
  }
  long long ans = 1;  
  for (int i = 1; i <= k; ++i) {
    if (cnt[i] > 0) {
      // cout << i << " " << cnt[i] << endl; 
      ans = mul(ans, power(i, cnt[i])); 
    }
  }
  cout << ans << "\n"; 

     
  return 0;
}