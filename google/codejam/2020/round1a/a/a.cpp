using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 100 + 10;
const int MOD = 1e9 + 7; 
string a[N]; 
int n; 

void solve() {
  cin >> n; 
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  string st = "";
  string ed = ""; 
  string mid = ""; 

  for (int i = 1; i <= n; ++i) {

    string z = a[i]; 
    int src = -1; 
    int dst = z.size();

    for (int j = 0; j < z.size(); ++j) {
      if (z[j] == '*') break;
      src = j;
    }

    if (src != z.size() - 1) {
      for (int j = z.size() - 1; j >= 0; --j){
        if (z[j] == '*') break; 
        dst = j; 
      }
    }

    for (int j = src + 1; j < dst; ++j) {
      if (z[j] == '*') continue; 
      mid = mid + z[j]; 
    }

    for (int j = 0; j <= src; ++j) {
      if (j >= st.size()) {
        st = st + z[j]; 
      }
      else if (st[j] != z[j]) {
        cout << "*\n";
        return ;  
      }
    }

    for (int j = z.size() - 1; j >= dst ; --j) {
      int pos = z.size() - j - 1; 
      if (pos >= ed.size()) {
        ed = ed + z[j]; 
      }
      else if (ed[pos] != z[j]) {
        cout << "*\n"; 
        return; 
      }
    }

  }
  reverse(ed.begin(), ed.end()); 

  cout << st + mid + ed << endl; 
}
 
int main() {
  #define TASK "test"
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