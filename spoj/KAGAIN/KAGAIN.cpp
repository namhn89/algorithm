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
int a[N], l[N], r[N]; 

 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; 
	cin >> T;
	while (T--) {
		/* code */
		int n;
		cin >> n; 
		for (int i = 1; i <= n; ++i) {
			cin >> a[i]; 
		}
		for (int i = 1; i <= n; ++i) {
			l[i] = i; 
			while(a[l[i] - 1] >= a[i]) l[i] = l[l[i] - 1]; 
		}
		for (int i = n; i >= 1; --i) {
			r[i] = i; 
			while(a[r[i] + 1] >= a[i]) r[i] = r[r[i] + 1];
		}
		int ans = -1, ansL, ansR; 
		for (int i = 1; i <= n; ++i) {
			if (ans < (r[i] - l[i] + 1) * a[i]) {
				ans = (r[i] - l[i] + 1) * a[i];
				ansL = l[i]; 
				ansR = r[i]; 
			}
		}
		printf("%d %d %d\n", ans, ansL, ansR); 
	}
	
     
  	return 0;
}