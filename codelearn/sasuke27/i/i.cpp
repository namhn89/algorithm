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

string a, b;
int c1;  
int cntA = 0; 
int cntB = 0;

bool process(int i, int j) {
  for (int k = 0; k <= i; ++k) if (a[k] == '1') cntA++;
  int cnt = c1; 
  bool ok = true; 
  for(int k = j; k < b.size(); ++k) {
    if (b[k] == '1') {
      if (cnt % 2 == 0) {
        if (cntA > 0) {
          cntA -= 1;  
        }
        else {
          ok = false; 
        }
      }
      else {
        cnt += 1; 
      }
    }
    else {
      if (cnt % 2) {
        if (cntA > 0) {
          cnt -= 1; 
          cntA -= 1; 
        }
        else {
          ok = false; 
        }
      } 
    }
  }
  return ok; 
}

bool convBinaryString(std::string p, std::string l) {
  a = p; 
  b = l; 
  int n = a.size(); 
  int m = b.size(); 
  c1 = 0; 
  for (int i = 1; i <= n; ++i) c1 += (a[i - 1] == '1');
  for (int len = 0; len <= n; ++len) {
      string S = a.substr(n - len, len); 
      string T = b.substr(0, len); 
      if (S == T) {
        if (process(n - len - 1, len)) 
          return true; 
      }
  } 
  return false; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string a, b;
  cin >> a >> b; 
  cout << convBinaryString(a, b) << endl; 
     
  return 0;
}