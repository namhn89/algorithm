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
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);

  
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; 
  cin >> n; 
  vector <int> a(n), b(n), c(n);  
  for (int i = 0; i < n; ++i) cin >> a[i]; 
  for (int i = 0; i < n; ++i) cin >> b[i]; 
  for (int i = 0; i < n; ++i) c[i] = a[i] - b[i]; 
  sort(c.begin(), c.end()); 
  int pos = n; 
  long long ans = 0; 
  for (int i = 0; i < n; ++i) {
    if (c[i] > 0) {
      ans += n - i - 1; 
      continue; 
    }
    while(pos > 0 && c[i] + c[pos - 1] > 0) {
      pos--; 
    }
    ans += n - pos; 
  }
  cout << ans; 
  return 0;
}