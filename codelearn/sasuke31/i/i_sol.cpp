#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
using namespace std;

typedef long long LL;
#define FOR(i, x, y) for (int i = 0; i < (y); ++i)

const int maxm = 1 << 8, maxn = 20 + 5;
const LL MOD = 1E9 + 7;
const int M2[6][2] = {{7, 1}, {7, 4}, {1, 7}, {4, 7}, {2, 7}, {7, 2}};
const int M3[6][3] = {{1, 1, 3}, {2, 2, 3}, {3, 1, 1}, {3, 2, 2}, {2, 3, 2}, {1, 3, 1}};
int T, n, m, ALL;
int G[maxn];
string s;
int f[maxn][maxm][maxm];
bool call[maxn][maxm][maxm];

int go(int r, int a, int b, int c) {
    if (a == ALL) {
        if (r == n) return 1;
        if (call[r][b][c]) return f[r][b][c];
        call[r][b][c] = true;
        int& ret = f[r][b][c];
        return ret = go(r + 1, b, c, G[r + 3]);
    }
    LL ret = 0;
    LL target = 1;
    while (a & target) target <<= 1;
    FOR (i, 0, m - 2)
        FOR (t, 0, 6) {
            int m1 = M2[t][0] << i;
            int m2 = M2[t][1] << i;
            if (!(m1 & target) || (a & m1) || (b & m2)) continue;
            ret += go(r, a | m1, b | m2, c);
        }
    FOR (i, 0, m - 1)
        FOR (t, 0, 6) {
            int m1 = M3[t][0] << i;
            int m2 = M3[t][1] << i;
            int m3 = M3[t][2] << i;
            if (!(m1 & target) || (a & m1) || (b & m2) || (c & m3)) continue;
            ret += go(r, a | m1, b | m2, c | m3);
        }
    return ret % MOD;
}

int fillBoard(std::vector<std::string> g) {
    n = (int)g.size(), m = (int)g[0].size();
    // cerr << n << ' ' << m << endl;
    ALL = (1 << m) - 1;
    FOR(i, 0, n)
        FOR(j, 0, m)
            if (g[i][j] == '#') G[i] |= 1 << j;
    G[n] = G[n + 1] = ALL;
    return go(0, G[0], G[1], G[2]);
}
