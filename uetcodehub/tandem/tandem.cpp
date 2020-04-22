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
const long long MOD = 1e9 + 7; 
const long long BASE = 89; 
int n, m; 
string s;
long long hashS[N], pw[N];  

long long getHash (int l, int r) {
  return (hashS[r] - hashS[l - 1] * pw[r - l + 1] + MOD * MOD) % MOD; 
}

 
int main() {
  #define TASK "test"
  freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n >> m; 
  pw[0] = 1; 
  for (int i = 1; i <= n; ++i) pw[i] = (pw[i - 1] * BASE) % MOD; 
  cin >> s;
  for (int i = 1; i <= n; ++i) {
    hashS[i] = (hashS[i - 1] * BASE + (s[i - 1] - '0')) % MOD; 
  }
  for (int i = 0; i < m; ++i) {
    int l, r; 
    cin >> l >> r; 
    int len = r - l + 1;
    long long hashC = getHash(l ,r); 
    int k = 1; 
    while(true) {
      // cout << l << " " << r << " " << l + len * k << " " << l + len * (k + 1) - 1 << endl; 
      if (hashC == getHash(l + len * k, l + len * (k + 1) - 1)) k++;
      else {
        break;
      } 
    }
    cout << k << endl; 
  } 
     
  return 0;
}