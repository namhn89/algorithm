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
  int n; 
  cin >> n;
  int z = 1;
  cout << endl; 
  if (n == 1) {
    cout << "1" << " 1" << endl; 
  }
  else if (n == 2) {
    cout << "1" << " 1" << endl; 
    cout << "2" << " 2" << endl; 
    n = 0;  
  } 
  else {
    cout << "1" << " 1" << endl; 
    cout << "2" << " 2" << endl; 
    z = 2;
    n -= 2; 
    while(n > 0) {
      if (n >= z) {
        n -= z; 
        cout << z + 1 << " " << (z > 1 ? "2" : "1") << endl; 
        z += 1; 
      }
      else {
        for (int i = z; i <= (n + z - 1); ++i) {
          cout << i << " " << "1" << endl; 
       }
      n = 0; 
      }
    }
  }
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