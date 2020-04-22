#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int INF = 1000000007;

int n, m, k, q;
int x[N * N], y[N * N], t[N * N];
int st[4 * N * N];
int a[N][N];
int ans;

void build(int lx, int ly, int rx, int ry, int k) {
  if (lx > rx || ly > ry) return;
  if (lx == rx && ly == ry) {
    st[k] = a[lx][ly];
    return;
  }
  int mx = (lx + rx) >> 1;
  int my = (ly + ry) >> 1;
  build(lx, ly, mx, my, (k << 2) - 2);
  build(lx, my + 1, mx, ry, (k << 2) - 1);
  build(mx + 1, my + 1, rx, ry, (k << 2) + 0);
  build(mx + 1, ly, rx, my, (k << 2) + 1);
  st[k] = max(st[(k << 2) - 2], max(st[(k << 2) - 1], max(st[(k << 2) + 0], st[(k << 2) + 1])));
}

void upd(int lx, int ly, int rx, int ry, int k, int x, int y, int v) {
  if (lx > rx || ly > ry || x < lx || x > rx || y < ly || y > ry) return;
  if (lx == x && rx == x && ly == y && ry == y) {
   st[k] = v;
    return;
  }
  int mx = (lx + rx) >> 1;
  int my = (ly + ry) >> 1;
  upd(lx, ly, mx, my, (k << 2) - 2, x, y, v);
  upd(lx, my + 1, mx, ry, (k << 2) - 1, x, y, v);
  upd(mx + 1, my + 1, rx, ry, (k << 2) + 0, x, y, v);
  upd(mx + 1, ly, rx, my, (k << 2) + 1, x, y, v);
  st[k] = max(st[(k << 2) - 2], max(st[(k << 2) - 1], max(st[(k << 2) + 0], st[(k << 2) + 1])));
}

void get(int lx, int ly, int rx, int ry, int k, int x, int y, int u, int v) {
  if (lx > rx || ly > ry || u < lx || x > rx || v < ly || y > ry) return;
  if (x <= lx && u >= rx && y <= ly && v >= ry) {
    ans = max(ans, st[k]);
    return;
  }
  int mx = (lx + rx) >> 1;
  int my = (ly + ry) >> 1;
  get(lx, ly, mx, my, (k << 2) - 2, x, y, u, v);
  get(lx, my + 1, mx, ry, (k << 2) - 1, x, y, u, v);
  get(mx + 1, my + 1, rx, ry, (k << 2) + 0, x, y, u, v);
  get(mx + 1, ly, rx, my, (k << 2) + 1, x, y, u, v);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = INF;
  build(1, 1, n, m, 1);
  for (int i = 1; i <= q; i++) {
    cin >> x[i] >> y[i] >> t[i];
    upd(1, 1, n, m, 1, x[i], y[i], t[i]);
  }
  int res = INF;
  for (int i = 1; i + k - 1 <= n; i++)
    for (int j = 1; j + k - 1 <= m; j++) {
      ans = -1;
      get(1, 1, n, m, 1, i, j, i + k - 1, j + k - 1);
      res = min(res, ans);
    }
  if (res == INF) res = -1;
  cout << res;
  return 0;
}

