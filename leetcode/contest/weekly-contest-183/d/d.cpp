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
string stoneGameIII(vector<int>& A) {
  int n = A.size();
  vector<int> dp(n, -1e9);
  for (int i = n - 1; i >= 0; --i) {
    for (int k = 0, take = 0; k < 3 && i + k < n; ++k) {
        take += A[i + k];
        dp[i] = max(dp[i], take - (i + k + 1 < n ? dp[i + k + 1] : 0));
      }
    }
    if (dp[0] > 0) return "Alice";
    if (dp[0] < 0) return "Bob";
    return "Tie";
  }

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <int> b = {1,2,3,6}; 
  cout << stoneGameIII(b) << endl; 
  return 0;
}