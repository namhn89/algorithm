using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e3 + 1;
const int MOD = 1e9 + 7; 
int s[N], e[N], n; 
pair<pair<int, int>, int> a[N];
int dp[N][2], trace[N];   
void solve() {
  cin >> n; 
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first.second >> a[i].first.first;
    a[i].second = i;  
  }
  sort(a + 1, a + n + 1); 
  trace[a[1].second] = 0;
  int cur = 0, ans = 0;  
  for (int i = 2; i <= n; ++i) {
    if (a[i - 1].first.first > a[i].first.second) {
      if (cur > a[i].first.second) {
        cout << "IMPOSSIBLE\n"; 
        return; 
      }
      cur = a[i - 1].first.first; 
      ans = 1 - ans; 
    }
    trace[a[i].second] = ans; 
  }

  for (int i = 1; i <= n; ++i) cout << (trace[i] == 0 ? "C" : "J");
  cout << "\n";  
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  cin >> t; 
  for(int iTest = 0; iTest < t; ++iTest) { 
    cout <<"Case #"<< iTest + 1 <<": ";
    solve(); 
  }
     
  return 0;
}