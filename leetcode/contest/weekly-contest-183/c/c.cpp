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
string longestDiverseString(int a, int b, int c) {
  vector< pair<int, char> > x; 
  x.push_back(make_pair(a, 'a')); 
  x.push_back(make_pair(b, 'b'));
  x.push_back(make_pair(c, 'c'));
  string ans = "";  
  while(x[0].st + x[1].st + x[2].st > 0) {
    sort(x.begin(), x.end()); 
    if (x[x.size() - 1].st == 0) break; 
    if (x[x.size() - 1].st > 2 && x[0].st == 0) break; 
    if (x[x.size() - 1].st >= 2) {
      x[x.size() - 1].st -= 2; 
      ans = ans + x[x.size() - 1].nd;
      ans = ans + x[x.size() - 1].nd; 
    }
    else ans = ans + x[x.size() - 1].nd, x[x.size() - 1].st -= 1; 
      
  }     
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}