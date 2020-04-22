#include <bits/stdc++.h> 

using namespace std;

#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define FOR(i, a, b) for(int i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(int i = a, _b = (b) ; i >= _b ; i--)

typedef long long int64;

int main() {
    #define file "in"
    //freopen(file".INP","r",stdin); freopen(file".OUT","w", stdout);

    int64 n2, n3, n5, n6;
 	cin >> n2 >> n3 >> n5 >> n6; 
 	int64 n256 = min(n2, min(n5, n6));   
    int64 n32 = min(n2 - n256, n3);
    cout << n256 * 256 + n32 * 32; 
    return 0; 	
}