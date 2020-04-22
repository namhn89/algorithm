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
#include <cstring> 

using namespace std;
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

const long long MAXN = 1e6 + 10; 
const long long mod = 1e9 + 7; 
char s[MAXN]; 

int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    scanf("%s", s + 1);
    long long n = strlen(s + 1);  
    long long nb = 0;
    long long res = 0;  
    for (long long i = n; i >= 1; i--) {
    	if (s[i] == 'a') {
    		res = (res + nb) % mod; 
    		nb = (nb * 2) % mod; 
    	}
    	else {
    		nb = (nb + 1) % mod;
    	} 
    }
    cout << res; 
    return 0;
}