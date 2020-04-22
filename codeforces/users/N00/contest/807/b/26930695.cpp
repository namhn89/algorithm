#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;
#define RemoveDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

int p, real_x, y; 

bool can (int r) {
	int i = r % 475; 
	int t = 25; 
	while (t--) {
		i = (i * 96 + 42) % 475; 	
		if (26 + i == p) return true; 
	}
	return false; 
}


int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    cin >> p >> real_x >> y; 
    for (int x = real_x; x >= y; x -= 50) {
    	if (can(x / 50)) return cout << 0, 0; 
    } 
    for (int x = real_x, add = 0; ; x += 50, add++) {
    	if (can(x / 50)) return cout << (add + 1) / 2, 0;  
    }
    return 0;
}