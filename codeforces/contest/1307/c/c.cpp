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

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s; 
  cin >> s; 
  int n = s.size(); 
  vector < vector<long long> > res(26, vector <long long> (26));
  vector <long long> cnt(26); 
  for (int i = 0; i < s.size(); ++i) {
    int id = int(s[i] - 'a');
    for (int j = 0; j < 26; ++j) { 
      res[j][id] += cnt[j]; 
    }
    cnt[id] += 1; 
  }
  long long ans = 0; 
  for(long long x: cnt) ans = max(ans, x); 
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      ans = max(ans, res[i][j]); 
    }
  } 
  cout << ans << endl; 
 
  return 0;
}