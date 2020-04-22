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
  string s ;
  cin >> s ;
  int n = s.size(); 
  bool close = true;
  int open_parenthesis = 0;
  int parenthesis = 0;   
  string ans = ""; 
  for (int i = 0; i < n; ++i) {
    if (s[i] != '0') {
      int x = int(s[i] - '0'); 
      if (parenthesis <= x) {
        int need_open = x - parenthesis; 
        for (int i = 0 ; i < need_open; ++i) ans = ans + '(';
        ans = ans + s[i];
        parenthesis = x; 
      }
      else {
        int need_close = parenthesis - x; 
        for (int i = 0; i < need_close; ++i) ans = ans + ')'; 
        ans = ans + s[i]; 
        parenthesis = x; 
      }
    }
    else {
      for (int i = 0; i < parenthesis; ++i) ans = ans + ')'; 
      ans = ans + s[i]; 
      parenthesis = 0; 
    }
  }
  if (parenthesis) {
    for (int i = 0; i < parenthesis; ++i) ans = ans + ')'; 
  }
  cout << ans << '\n'; 
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