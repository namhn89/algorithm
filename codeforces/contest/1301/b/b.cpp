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
  int n; 
  cin >> n;
  vector <int> a(n); 
  for (int &b: a) cin >> b; 
  vector <int> b; 
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) continue; 
    if (i && a[i - 1] == -1) b.push_back(a[i]);
    if (i < n - 1 && a[i + 1] == -1) b.push_back(a[i]);  
  }
  if (b.size() == 0) {
    cout << 0 << " " << 0 << endl; 
    return; 
  }
  else
  {
    sort(b.begin(), b.end()); 
    int x = (b[0] + b[b.size() - 1]) / 2;
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1) {
        a[i] = x; 
      }
    }
    int ans = 0; 
    for (int i = 1; i < n; ++i) {
      ans = max(ans, abs(a[i] - a[i - 1])); 
    }
    cout << ans << " " << x << endl; 
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