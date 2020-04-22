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
string w; 

void dfs (string s, int len) {
  if (len == 2 || len == 3) {
    cout << s << " "; 
  }
  if (len == 3) {
    return; 
  }
  for (int i = 0; i < w.size(); ++i) {
    string newS = s + w[i]; 
    dfs(newS, len + 1);
  }
}
 
int main() {
  #define TASK "test"
  freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> w; 
  dfs("", 0); 
  cout << endl; 
     
  return 0;
}