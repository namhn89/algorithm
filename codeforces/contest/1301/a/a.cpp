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


void solve() {
  string a, b, c;
  cin >> a; 
  cin >> b;
  cin >> c; 
  int n = a.size();
  bool ans = true;  
  for (int i = 0; i < n; ++i) {
    bool res = (c[i] == b[i]) | (a[i] == c[i]);
    ans = ans & res;  
  }
  if (ans) {
    cout << "YES" << endl; 
  }
  else {
    cout << "NO" << endl; 
  }
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  cin >> t;
  while (t--) {
    solve();
  }
 
  return 0;
}