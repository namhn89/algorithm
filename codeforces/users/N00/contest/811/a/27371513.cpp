#include <bits/stdc++.h> 
using namespace std; 


int main() {
	//freopen ("in.inp", "r", stdin); freopen ("in.out", "w", stdout); 
	int a, b; 
	cin >> a >> b; 
	int step = 0; 
	while (a >= 0 && b >= 0) {
		step++; 
		if (step % 2 == 1) a -= step; 
		else b -= step;  
	}		
	if (a < 0) cout << "Vladik"; 
	else cout << "Valera"; 
}