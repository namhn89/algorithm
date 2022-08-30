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

class Solution{
	public: 
		vector <string> generateParenthesis(int n) {
			vector<string> res;
			function<void(int, int, string)> dfs = [&](int i, int j, string s) {
				if (i < 0 || j < 0 || i < j) return; 
				if (i == 0 and j == 0) res.push_back(s); 
				dfs(i - 1, j, s + ")"); 
				dfs(i, j - 1, s + "("); 
			};
			dfs(n, n, ""); 
			return res; 
		}
}; 


 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  	return 0;
}