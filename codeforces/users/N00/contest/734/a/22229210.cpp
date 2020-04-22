#include <bits/stdc++.h> 

using namespace std;

#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define FOR(i, a, b) for(int i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(int i = a, _b = (b) ; i >= _b ; i--)

typedef long long int64;

int n; 
char c; 

int main() {
    #define file "in"
    //freopen(file".INP","r",stdin); freopen(file".OUT","w", stdout);
    int A = 0, D = 0; 
    cin >> n; 
    for (int i = 1; i <= n; i++) {
    	cin >> c; 
    	A += (c == 'A');
    	D += (c == 'D');
    }
   	if (A > D) cout << "Anton" << endl; 
   	else if (A < D) cout << "Danik" << endl; 
   	else cout << "Friendship" << endl; 
    return 0; 	
}