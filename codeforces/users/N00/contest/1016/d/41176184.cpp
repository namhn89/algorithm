#include <bits/stdc++.h>
using namespace std;

#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

const long long N = 105; 

long long nr, nc;
long long a[N], b[N];  
long long c[N][N], d[N][N]; 

long long getbit (long long mask, long long p) { return (mask >> p) & 1; }

bool solve (long long i) { 
	memset(d, 0, sizeof(d));
	for (long long x = 1; x <= nr - 1; x++) { 
		for (long long y = 1; y <= nc - 1; y++) { 
			d[x][y] = 1; 
		}
	} 
	long long hc = 0; 
	for (long long x = 1; x <= nr - 1; x++) { 
		long long has = (nc - 1) % 2;
		d[x][nc] = getbit(a[x], i) ^ has;
		hc += d[x][nc];   
	}
	long long hr = 0; 
	for (long long y = 1; y <= nc - 1; y++) { 
		long long has = (nr - 1) % 2; 
		d[nr][y] = getbit(b[y], i) ^ has;
		hr += d[nr][y];  
	}
	/*cout << "d" << endl; 
	for (long long x = 1; x <= nr; x++) { 
		for (long long y = 1; y <= nc; y++) { 
			cout << d[x][y] << " "; 
		}
		cout << endl; 
	}*/
	if ((getbit(a[nr], i) ^ (hr % 2)) != (getbit(b[nc], i) ^ (hc % 2))) {
		return false; 
	} 
	d[nr][nc] = getbit(a[nr], i) ^ (hr % 2); 
	for (long long x = 1; x <= nr; x++) { 
		for (long long y = 1; y <= nc; y++) { 
			c[x][y] += (d[x][y] << i);
		}
	}
	//cout << endl << endl; 
	return true; 
}

int main()
{
    #define file "D"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    cin >> nr >> nc; 
    for (long long i = 1; i <= nr; i++) cin >> a[i]; 
    for (long long i = 1; i <= nc; i++) cin >> b[i]; 
    for (long long p = 0; p <= 29; p++) { 
    	if (not solve(p)) { 
    		cout << "NO"; 
    		return 0; 
    	} 
    }
    cout << "YES" << endl; 
    for (long long x = 1; x <= nr; x++) {
    	for (long long y = 1; y <= nc; y++) { 
    		cout << c[x][y] << " "; 
    	}
    	cout << endl; 
    }
    /*for (long long x = 1; x <= nr; x++) {
    	long long ret = 0; 
    	for (long long y = 1; y <= nc; y++) { 
    		ret ^= c[x][y]; 
    	}
    	cout << ret << endl; 
    }
    for (long long y = 1; y <= nc; y++) { 
    	long long ret = 0; 
    	for (long long x = 1; x <= nr; x++) { 
    		ret ^= c[x][y]; 
    	}
    	cout << ret << endl; 
    }*/
    return 0;
}

