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
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end()); 
    int n = satisfaction.size(); 
    int pos = n, time = 0, s = 0, ans = 0;  
    for (int i = 0; i < n; ++i) {
      if (satisfaction[i] >= 0) {
        pos = min(pos, i); 
        s += satisfaction[i]; 
        time += 1 ; 
        ans = ans + satisfaction[i] * time; 
      }
    }
    //cout << pos << endl; 
    //for (int i = 0; i < n; ++i) cout << satisfaction[i] << " "; cout << endl; 
    for(int i = pos - 1; i >= 0; --i) {
      int ansnew = ans + (s + satisfaction[i]); 
      //cout << ansnew << endl; 
      if (ansnew < ans) {
        break; 
      }
      else {
        ans = ansnew ; 
        s += satisfaction[i]; 
      }
    }
    return ans; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <int> a = {-1,-8,0,5,-7}; 
  cout << maxSatisfaction(a) << endl; 
  return 0;
}