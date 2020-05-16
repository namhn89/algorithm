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

void sort(vector<int>& v, int M) {
    int n = v.size(); 
    priority_queue<int> q; 
    int pos = 0; 
    for (int i = 0; i < n; ++i) {
        while (pos <= min(n - 1, i + M)) q.push(-v[pos++]);
        printf("%d ", -q.top());
        q.pop();
    }
}

 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector <int> a{4, 1, 5, 2, 3, 9, 6, 7, 8}; 
	int d = 3 ; 
	sort(a, d); 
        
  	return 0;
}