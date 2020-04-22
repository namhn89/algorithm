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

#define remove_duplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

typedef long long longint;

const int MAXN = 4e5 + 10;

int n;
vector<int> tree[MAXN], children[MAXN];
int dad[MAXN];
int color[MAXN];
void dfs (int x) {
    for (int y : tree[x]) {
        if (y == dad[x]) continue;
        children[x].push_back(y);
        dad[y] = x;
        dfs(y);
    }
}
void coloring (int x) {
    map<int, bool> mark;
    mark[color[x]] = 1;
    mark[color[dad[x]]] = 1;
    int can = 1;
    for (int y : children[x]) {
        for (; can <= n; can++) {
            if (not mark[can]) {
                color[y] = can;
                mark[can] = 1;
                break;
            }
        }
        coloring(y);
    }
}


int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    cin >> n;
    for (int idx = 1; idx < n; idx++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs (1);
    color[1] = 1;
    coloring(1);
    set<int> sol;
    for (int x = 1; x <= n; x++) sol.insert(color[x]);
    cout << sol.size() << endl;
    for (int x = 1; x <= n; x++) cout << color[x] << " ";
    return 0;
}
