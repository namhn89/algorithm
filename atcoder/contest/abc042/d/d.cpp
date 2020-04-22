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

class Binomial {
  vector <int> fact, inv; 
  int n; 
  public:
    Binomial() {};
    Binomial(int sz) : n(sz), fact(sz + 1), inv(sz + 1) {
      fact[0] = fact[1] = inv[0] = inv[1] = 1;
        for (int i = 2; i <= n; ++i) {
            fact[i] = 1LL * fact[i - 1] * i % MOD;
            inv[i] = (MOD - 1LL * (MOD / i) * inv[MOD % i] % MOD) % MOD;
        }
        for (int i = 2; i <= n; ++i) inv[i] = 1LL * inv[i] * inv[i - 1] % MOD;
    };
    int operator() (int y, int x) { // x<=y; x>=0
        if (x > y) return 0;
        return 1LL * fact[y] * inv[x] % MOD * inv[y - x] % MOD;
    }
} nCr(N);

int solve (int n, int r) {
    return nCr(n + r, r); 
}

int calc (int a, int b, int c, int d) {
    int res = mul(solve(a, b), solve(c, d)); 
    return res; 
}


int main() {
    #define TASK "TASK"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int h, w, a, b;  
    cin >> h >> w >> a >> b;
    int ans = 0; 
    for (int i = b; i < w; ++i) {
        ans = add(ans, calc(i, h - a - 1, w - i - 1, a - 1));
    }
    cout << ans; 
    return 0;
}