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


int n; 

int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    vector<int> path; 
    cin >> n; 
    for (int i = 1; i <= n / 2; i++) {
    	path.push_back(i);
    	path.push_back(n - i + 1); 
    }
    if (n % 2 == 1)
    	path.push_back(n / 2 + 1); 
    int res = 0; 
    for (int i = 0; i < path.size() - 1; i++) {
    	res += (path[i] + path[i + 1]) % (n + 1); 
    }
    cout << res; 
    return 0;
}