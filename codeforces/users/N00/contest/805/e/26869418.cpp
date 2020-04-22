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

const int MAXN = 3 * 1e5 + 10; 

int n, nType; 
int color[MAXN]; 
int vis[MAXN]; 
vector<int> typeAt[MAXN]; 
vector<int> g[MAXN]; 
int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin >> n >> nType; 
    for (int x = 1; x <= n; x++) {
    	int sz; 
    	cin >> sz; 
    	while (sz--) {
    		int type; 
    		cin >> type; 
    		typeAt[x].push_back(type); 
    	}
    }
    int pmax = 1; 
    for (int x = 2; x <= n; x++) {
    	if (typeAt[pmax].size() < typeAt[x].size()) pmax = x; 
    }
    for (int i = 0; i < typeAt[pmax].size(); i++) {
    	color[typeAt[pmax][i]] = i + 1; 
    }
    for (int ie = 1; ie < n; ie++) {
    	int x, y; 
    	cin >> x >> y; 
    	g[x].push_back(y); 
    	g[y].push_back(x); 
    }
    queue<int> q; 
    q.push(pmax);
    vis[pmax] = 1;  
    while (not q.empty()) {
    	int x = q.front(); q.pop(); 
    	//cout << x << endl; 
    	
    	for (int y : g[x]) {
    		if (vis[y]) continue; 
    		vis[y] = 1; 
			q.push(y); 
			set<int> has; 
			for (int i = 0; i < typeAt[y].size(); i++) has.insert(color[typeAt[y][i]]); 
			int ptr = 1; 
			for (int i = 0; i < typeAt[y].size(); i++) {
				if (color[typeAt[y][i]] == 0) {
					while (has.find(ptr) != has.end()) { ptr++; }
					has.insert(ptr);
					color[typeAt[y][i]] = ptr;  
				}
			}    		
    	}
    }

    for (int i = 1; i <= nType; i++) if (color[i] == 0) color[i] = 1; 
    int nColor = 0; 
    for (int i = 1; i <= nType; i++) nColor = max(nColor, color[i]); 
    cout << nColor << endl; 
    for (int i = 1; i <= nType; i++) cout << color[i] << " "; 
    return 0;
}