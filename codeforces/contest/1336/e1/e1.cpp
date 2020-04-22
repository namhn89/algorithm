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
const int MOD = 998244353; 

int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m; 
  cin >> n >> m; 
  vector <long long> basis;
  vector <long long> a;  
  for (int i = 0; i < n; ++i) {
    long long x; 
    cin >> x; 
    for (long long b: basis) {
      if ((x ^ b) < x) {
        x ^= b; 
      }
    }
    if (x > 0) {
      for (long long &b : basis) {
        if ((b ^ x) < b) {
          b ^= x; 
        }
      }
      basis.push_back(x);
      sort(basis.begin(), basis.end()); 
      reverse(basis.begin(), basis.end()); 
    }
  }
  for (long long &b : basis) {
    for (int i = m; i >= 0; --i) {
      if (b & (1LL << i)) {
        b ^= (1LL << i); 
        break; 
      }
    }
  }
  /*
  for (long long &b : basis) {
    cout << bitset<4>(b) << endl; 
  }
  */

  map<pair<long long, int>, int> f; 
  f[{0LL, 0}] = 1;
  for (long long b: basis) {
    vector <tuple<long long, int, int>> nextSet; 
    for (auto it: f) {
      long long nextVal = it.first.first ^ b; 
      int nkeys = it.first.second + 1; 
      nextSet.push_back(make_tuple(nextVal, nkeys, it.second)); 
    }
    for (auto it: nextSet) {
      long long val = get<0>(it); 
      int keys = get<1>(it); 
      f[{val, keys}] = (f[{val, keys}] + get<2>(it)) % MOD;
    }
  }

  vector <long long> ans(m + 1, 0); 
  for (auto it: f) {
    int z = __builtin_popcountll(it.first.first) + it.first.second;
    ans[z] = (ans[z] + it.second) % MOD;  
  }

  long long mul = 1; 
  for (int i = 0; i < n - basis.size(); ++i) mul = (mul * 2) % MOD; 

  // ans = p{i} ^ 2 ^ (n - k) 
  
  for (int i = 0; i <= m; ++i) {
    cout << (ans[i] * mul) % MOD << " "; 
  }

  return 0;
}