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
class Solution {
	private: 
		struct Data {
			int num, cnt; 
			/* data */
			bool operator < (const Data &other) const {
				return cnt < other.cnt; 
			}
		};
		
	public:
    	vector<int> topKFrequent(vector<int>& nums, int k) {
			map<int, int> f; 
			for (int x: nums) {
				f[x] += 1; 
			}
			priority_queue<Data> q; 
			for (auto [x, y] : f) {
				q.push({x, y}); 
			}
			vector<int> res; 
			while(k--) {
				Data u = q.top(); 
				res.push_back(u.num);
				q.pop(); 
			}
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