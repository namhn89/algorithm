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
vector<int> minSubsequence(vector<int>& nums) {
  sort(nums.begin(), nums.end()); 
  reverse(nums.begin(), nums.end());
  int sum = 0; 
  for (int c : nums) sum += c;
  vector <int> ans; 
  int k = 0;   
  for (int i = 0; i < nums.size(); ++i) {
    k += nums[i]; 
    ans.push_back(nums[i]); 
    if (k * 2 > sum) break; 
  }        
  return ans; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}