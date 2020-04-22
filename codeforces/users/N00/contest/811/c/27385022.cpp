#include <bits/stdc++.h> 
using namespace std; 
	
long long n; 
long long a[5005]; 
long long f[5005];
vector<long long> was[5005];  
long long first[5005], last[5005]; 
long long cxor[5005][5005]; 
bool has[5005]; 
int main() {
	//freopen ("in.inp", "r", stdin); freopen ("in.out", "w", stdout); 

	cin >> n; 
	for (long long i = 1; i <= n; i++) {
		cin >> a[i]; 
		was[a[i]].push_back(i); 
	}
	for (long long value = 0; value <= 5000; value++) {
		if (was[value].empty()) continue; 
		first[value] = was[value].front(); 
		last[value] = was[value].back(); 
	}
	for (long long i = 1; i <= n; i++) {
		for (long long value = 0; value <= 5000; value++) has[value] = false; 
		for (long long j = i; j <= n; j++) {
			if (has[a[j]] == false) {
				has[a[j]] = true; 
				cxor[i][j] = cxor[i][j - 1] ^ a[j]; 
			}
			else {
				cxor[i][j] = cxor[i][j - 1];
			}
		}
	}
	for (long long r = 1; r <= n; r++) {
		f[r] = max(f[r], f[r - 1]); 
		if (r != last[a[r]]) continue;
		long long minp = first[a[r]];
		bool can = true;   
		for (long long l = r; l >= 1; l--) {
			minp = min(minp, first[a[l]]);
			if (last[a[l]] > r) { can = false; break; }
			if (minp >= l) {
				f[r] = max(f[r], f[l - 1] + cxor[l][r]);
			} 
		}
	}
	cout << f[n]; 
}