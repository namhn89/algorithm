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

string convert (string s, int n, int k) {
  string head = s.substr(k - 1, n - k + 1); 
  string tail = s.substr(0, k - 1); 
  if (head.size() % 2) {
    reverse(tail.begin(), tail.end()); 
  } 
  string result = head + tail; 
  return result; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  cin >> t;
  while(t--) {
    string s; 
    int n; 
    cin >> n; 
    cin >> s; 
    string result = s;  
    int ans = 1; 
    for (int k = 2; k <= n; ++k) {
      string x = convert(s, n, k); 
      if (result > x){
        ans = k; 
        result = x;
      }
    }
    cout << result << endl; 
    cout << ans << endl; 
  }
     
  return 0;
}