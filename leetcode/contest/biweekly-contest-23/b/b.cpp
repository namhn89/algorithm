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
bool canConstruct(string s, int k) {
        vector<int> cnt(27, 0); 
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i] - 'a'] += 1; 
        }
        int minS = 0, maxS = 0; 
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) continue; 
            if (cnt[i] & 1) {
                minS += 1; 
                maxS += cnt[i];
            } 
            else {
                maxS += cnt[i];
            }
        }
        cout << minS << " " << maxS << endl; 
        if (k >= minS && k <= maxS) return true; 
        else return false; 
        
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << canConstruct("qlkzenwmmnpkopu", 15) << endl; 
     
  return 0;
}