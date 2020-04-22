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

const int MAXN = 1e5 + 10;



struct TEdge {
    int x, y;
    string operation;
    int t;
    TEdge (int x = 0, int y = 0, string operation = "", int t = 0) : x(x), y(y), operation(operation), t(t) {}
    int getadj (int u) { return x + y - u; }
};


int n, nBit;
string s[MAXN];
map<string, int> value;
vector<int> g[MAXN];
int degin[MAXN];
bool vis[MAXN];
vector<TEdge> e;
vector<int> topo;
int bit[MAXN];
int dfs_topo (int x) {
    for (int idx : g[x]) {
        int y = e[idx].getadj(x);
        if (not vis[y]) {
            vis[y] = 1;
            dfs_topo(y);
        }
    }
    topo.push_back(x);
}

string rmax, rmin;

int calc (int pos, int b) {
    for (int x = 1; x <= n; x++) bit[x] = 0;
    for (int x = 1; x <= n; x++) {
        if (s[x] != "") bit[x] = s[x][pos] - '0';
    }
    bit[value["?"]] = b;
    //for (int x = 1; x <= n; x++) cout << bit[x] << " "; cout << endl;
    for (int i = 0; i < topo.size(); i++) {
        int x = topo[i];
        for (int idx : g[x]) {
            int y = e[idx].getadj(x);
            if (e[idx].operation == "XOR") bit[y] = bit[x] ^ bit[e[idx].t];
            else if (e[idx].operation == "OR") bit[y] = bit[x] | bit[e[idx].t];
            else bit[y] = bit[x] & bit[e[idx].t];
        }
    }
    int res = 0;
    for (int x = 1; x <= n; x++) if (x != value["?"]) res += bit[x];
    //for (int x = 1; x <= n; x++) cout << bit[x] << " "; cout << endl;
    return res;
}



int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    cin >> n >> nBit;
    int nString = 0;
    for (int i = 1; i <= n; i++) {
        string var, a, b, operation;
        cin >> var >> a >> a;
        if (value[var] == 0) {
            value[var] = ++nString;
        }
        if (value[a] == 0 && not isdigit(a[0])) {
            value[a] = ++nString;
        }
        //cout << var << " " << a << endl;
        if (not isdigit(a[0])) {
            cin >> operation >> b;
            if (value[b] == 0) value[b] = ++nString;
            g[value[a]].push_back(e.size());
            e.push_back(TEdge(value[a], value[var], operation, value[b]));
            g[value[b]].push_back(e.size());
            e.push_back(TEdge(value[b] , value[var], operation, value[a]));
            degin[value[var]]++;
        }
        else {
            reverse(a.begin(), a.end());
            s[value[var]] = a;
        }
    }
    //cout << value["a"] << " " << value["bb"] << " " << value["cx"] << " " << value["d"] << " " << value["e"] << " " << value["?"] << " " << endl;
    /*for (int idx = 0; idx < e.size(); idx++) {
        cout << e[idx].x << " " << e[idx].operation << " " << e[idx].t<< " " << e[idx].y << endl;
    }*/
    n++;
    for (int x = 1; x <= n; x++) {
        if (not degin[x]) {
            dfs_topo(x);
        }
    }
    reverse(topo.begin(), topo.end());
    //for (int i = 0; i < topo.size(); i++) cout << topo[i] << " "; cout << endl;
    for (int p = 0; p < nBit; p++) {
        int r0 = calc(p, 0);
        int r1 = calc(p, 1);
        if (r1 < r0) rmin += '1';
        else rmin += '0';
        if (r1 > r0) rmax += '1';
        else rmax += '0';
    }
    reverse(rmin.begin(), rmin.end());
    reverse(rmax.begin(), rmax.end());
    cout << rmin << endl << rmax << endl;
    return 0;
}
