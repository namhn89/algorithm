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
  vector <int> a(n + 1, 0); 
  for (int i = 1; i <= n; ++i) cin >> a[i]; 
  vector <int> ans (n + 1, -1); 
  vector <int> visited (n + 1, 0); 
  for (int i = 1; i <= n; ++i) {
    if (a[i] != a[i - 1]) ans[i] = a[i], visited[a[i]] = 1;  
  }

  int st = 1; 
  for (int i = 1; i <= n; ++i) {
    if (ans[i] == -1) {
      for(;visited[st]; st++);
      visited[st] = 1; 
      ans[i] = st; 
      if (ans[i] > a[i]) {
        cout << -1 << endl;  
        return ; 
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << " "; cout << endl; 
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