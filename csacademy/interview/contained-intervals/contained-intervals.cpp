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

struct Interval {
    int l, r;
	bool operator < (const Interval& other) const {
		return l < other.l || (l == other.l and r > other.r); 
	}

	bool operator == (const Interval& other) const {
		return l == other.l and r == other.r; 
	}
};

int containedIntervals(vector<Interval>& intervals) {
	sort(intervals.begin(), intervals.end()); 
	int n = intervals.size(); 
	int maxR = intervals[0].r; 
	int count = 0; 
	for (int i = 0; i < intervals.size(); ++i) {
		if (i + 1 < n && intervals[i + 1] == intervals[i]) count++; 
		else {
			if (i > 0 && maxR >= intervals[i].r) {
				count++; 
			}
		}
		maxR = max(maxR, intervals[i].r); 
	}
	return count; 
    
}


 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);

  	return 0;
}