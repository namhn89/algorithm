using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e2 + 1;
const int MOD = 1e9 + 7; 

int a[N][N]; 
int n; 
void solve() { 
  cin >> n;
  int k = 0, r = 0, c = 0; 
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j]; 
    }
  }
  for (int i = 0; i < n; ++i) k += a[i][i]; 
  for (int i = 0; i < n; ++i) {
    set<int> sr, sc; 
    sr.clear(), sc.clear(); 
    for (int j = 0; j < n; ++j) { 
      sr.insert(a[i][j]); 
      sc.insert(a[j][i]);
    } 
    if (sr.size() != n) r++; 
    if (sc.size() != n) c++;  
  } 
  
  cout << k << " " << r << " " << c << '\n'; 
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