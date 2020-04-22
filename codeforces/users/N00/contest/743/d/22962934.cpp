#include<bits/stdc++.h>
using namespace std;

#define uni(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));
#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

typedef long long llint;

const int MAXN = 2e5 + 10;
const llint inf = 1e18 + 10;

struct TEdge {
    int x, y;
    TEdge (int x = 0, int y = 0) : x(x), y(y) {}
    int getadj (int u) { return x + y - u; }
} e[MAXN];

llint sub[MAXN];
llint maxsub[MAXN];
llint a[MAXN];
int n;
llint best = -inf;
vector <int> g[MAXN];
void dfs (int x, int parent) {
    maxsub[x] = -inf;
    sub[x] = a[x];
    foreach (id, g[x]) {
        int y = e[*id].getadj(x);
        if (y == parent) continue;
        dfs (y, x);
        sub[x] += sub[y];
        maxsub[x] = max(maxsub[x], maxsub[y]);
    }
    llint res = -inf;
    int maks = -1;
    foreach (id, g[x]) {
        int y = e[*id].getadj(x);
        if (y == parent) continue;
        if (maks == -1 || maxsub[maks] < maxsub[y]) {
            maks = y;
        }
    }
    foreach (id, g[x]) {
        int y = e[*id].getadj(x);
        if (y == parent || y == maks) continue;
        res = max(res, maxsub[y] + maxsub[maks]);
    }
    //cout << res << endl;
    best = max(best, res);
    maxsub[x] = max(maxsub[x], sub[x]);
}

int main(){
    #define file "ChloeAndPleasantPrizes"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    cin >> n;
    for (int x = 1; x <= n; x++) cin >> a[x];
    for (int id = 1; id < n; id++) {
        int x, y;
        cin >> x >> y;
        e[id] = TEdge (x, y);
        g[x].push_back(id);
        g[y].push_back(id);
    }
    best = -inf;
    dfs (1, 0);
    //for (int x = 1; x <= n; x++) cout << sub[x] << endl;
    if (best == -inf) return cout << "Impossible", 0;
    cout << best;
    return 0;
}
