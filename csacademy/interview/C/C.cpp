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
void noGapsArrays(int N) {
    vector <int> a(N); 
	for (int i = 1; i <= N; ++i) a[i - 1] = i; 
	do {
		for (int i = 1; i <= N; ++i) cout << a[i - 1] << " "; cout << endl; 
	} while (next_permutation(a.begin(), a.end())) ; 
}

 
int main() {
    #define TASK "TASK"	
	// freopen(TASK".inp","r",stdin);
	// freopen(TASK".out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N; 
	cin >> N; 
	noGapsArrays(N); 
     
  	return 0;
}