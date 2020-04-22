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
int n, k; 
int a[N]; 

bool check (int l) {
  int s = 0 ;
  for (int i = 0; i + 1< n ; ++i) {
    int dif = a[i + 1] - a[i]; 
    s += (dif - 1) / l ; 
  }
  return s <= k; 
}

void solve() {
  int l = 1, r = 1e9, res; 
  while(l <= r) {
    int mid = (l + r) / 2; 
    if (check(mid)) {
      r = mid - 1; 
      res = mid; 
    }
    else {
      l = mid + 1; 
    }
  }
  cout << res << '\n'; 
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int nTest;
  cin >> nTest; 
  for (int iTest = 1; iTest <= nTest; ++iTest) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    cout << "Case #" << iTest << ": ";
    solve(); 
  }
     
  return 0;
}