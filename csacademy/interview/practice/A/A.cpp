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
long long n, m, x, y; 
long long ans = -1; 

bool check (long long value) {
	long long sell = n - value; 
	if (sell * y + m >= value * x) return true; 
	return false; 
}


 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> x >> y; 
	ans = 0; 
	long long l = 1, r = n; 
	while(l <= r) {
		long long mid = (l + r) / 2; 
		if (check(mid)) {
			ans = mid; 
			l = mid + 1; 
		}
		else {
			r = mid - 1; 
			/* code */
		}
	}
	cout << ans; 
     
  	return 0;
}