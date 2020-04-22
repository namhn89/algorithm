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
const int mod = 1e9 + 7;
long long dp[N];  
struct Comb {
    int n;
    vector<int> fact, inv;
    Comb() {};
    Comb(int _n): n(_n), fact(_n + 5, 0), inv(_n + 5, 0) {
        fact[0] = fact[1] = inv[0] = inv[1] = 1;
        for (int i = 2; i <= n; ++i) {
            fact[i] = 1LL * fact[i - 1] * i % mod;
            inv[i] = (mod - 1LL * (mod / i) * inv[mod % i] % mod) % mod;
        }
        for (int i = 2; i <= n; ++i) inv[i] = 1LL * inv[i] * inv[i - 1] % mod;
    };
    int operator()(int x, int y) { // x<=y; x>=0
        if (x > y) return 0;
        return 1LL * fact[y] * inv[x] % mod * inv[y - x] % mod;
    }
} C(N); 

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m; 
  cin >> n >> m; 
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      int z = n / i; 
      dp[i] = C(m - 1, z - 1); 
    }
  }
  for (int i = n; i >= 1; --i) {
    if (dp[i] == 0) continue; 
    for (int j = 2 * i; j <= n; j += i) {
      dp[i] = (dp[i] - dp[j] + mod) % mod; 
    }
  } 
  cout << dp[1] << endl; 
     
  return 0;
}