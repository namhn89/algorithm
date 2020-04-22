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

bool isPrime(int n) { 
  if (n <= 1)  return false; 
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  } 
  return true; 
} 

int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; 
  cin >> n; 
  vector <int> ans; 
  set<int> myset;
  if (n == 1) {
    // cout << 1 << endl; 
    // cout << 1; 
    return 0; 
  }  
  for (int i = 2; i <= n; ++i) {
    if (isPrime(i) == true) {
      for (int j = i; j <= n; j *= i) myset.insert(j); 
    }
  }
  for(auto it: myset) {
    ans.push_back(it); 
  }
  sort(ans.begin(), ans.end()); 
  cout << ans.size() << endl; 
  for (auto it: ans) {
    cout << it << " "; 
  }
     
  return 0;
}