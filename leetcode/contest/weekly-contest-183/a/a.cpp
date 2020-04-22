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
int numSteps(string s) {
  int carry = 0; 
  int ans = 0; 
  for(int i = s.size() - 1; i >= 0; --i) {
    if (i == 0 && carry == 0) break; 
    if (i == 0 && carry == 1) {
      ans += 1; 
    } 
    if (s[i] == '0' && carry == 0) continue; 
    if (s[i] == '1' && carry == 1) {
      s[i] = '0';
      continue;  
    }
    if (s[i] == '0' && carry == 1) {
      ans += 1; 
    }
    if (s[i] == '1' && carry == 0) {
      s[i] = '0'; 
      carry = 1; 
      ans += 1; 
    }
  }
  ans += s.size() - 1;
  return ans;  
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << numSteps("1101") << endl; 
  return 0;
}