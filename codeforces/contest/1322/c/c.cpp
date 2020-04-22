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

 
int main() {
  #define TASK "test"
  //freopen(TASK".inp","r",stdin);
  //freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  cin >> t; 
  while(t--) {
    int n, m;
    cin >> n >> m; 
    vector <long long> a(n);
    vector <vector<int>> g(n);  
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    for (int i = 0; i < m; ++i) {
      int u, v; 
      cin >> u >> v;
      u--, v--; 
      g[v].push_back(u); 
    }
    map<vector<int>, long long> f;
    f.clear(); 
    for (int i = 0; i < n; ++i) {
      vector <int> tmp; 
      for (int u: g[i]) {
        tmp.push_back(u); 
      } 
      sort(tmp.begin(), tmp.end());  
      if (tmp.size() == 0) continue;   
      f[tmp] += a[i]; 
    }
    long long ans = 0;  
    for (auto &e: f) {
        ans = __gcd(ans, e.second); 
    }
    cout << ans << '\n'; 
  }
     
  return 0;
}