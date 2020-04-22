using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e6 + 100;
const int MOD = 1e9 + 7; 
int dp[N]; 
int bestFriend(std::vector<int> a, std::vector<int> b) {
  int m = b[0], n = b[1];
  int an = a.size(); 
  sort(a.begin(), a.end());
  dp[0] = 0; 
  for (int i = 1; i <= an; ++i) dp[i] = an + 1;  
  for (int i = 1; i <= an; i++) {
    if (i >= 2) {
      int ma = max(m, n); 
      int mi = min(m, n); 
      if (ma >= a[i - 1] && mi >= a[i - 2]) {
        dp[i] = min(dp[i], dp[i - 2] + 1); 
      }
    }
    int ma = max(m, n); 
    int mi = min(m, n); 
    if (ma >= a[i - 1] || mi + ma >= a[i - 1]) {
      dp[i] = min(dp[i - 1] + 1, dp[i]); 
    }
  }
  return dp[an]; 
}


 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}