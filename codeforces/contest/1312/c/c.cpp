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
const long long inf = 1e16; 

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  cin >> t; 
  while (t--) {
    long long n, k;
    cin >> n >> k; 
    vector <long long> a(n);
    vector <int> used(100);  
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    for (int i = 0; i < n; ++i) {
      int x = 0; 
      while(a[i]) {
        used[x] += a[i] % k; 
        a[i] /= k; 
        x++;
      }
    }
    bool ans = true; 
    for (int v: used) {
      if (v > 1) ans = false; 
    }
    if (ans) {
      cout << "YES" << endl; 
    }
    else {
      cout << "NO" << endl; 
    }  
  }
     
  return 0;
}