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
public:
    map<int, int> mp; 
    int findLucky(vector<int>& arr) {
    	for (int c : arr) {
    		mp[c]++; 
      	}
		int ans = -1; 
		for (auto p : mp) {
			if (p.first == p.second) {
				ans = p.first; 
			}
		}
		return ans; 
    }
};

 
int main() {
	#define TASK "TASK"
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
     
	return 0;
}