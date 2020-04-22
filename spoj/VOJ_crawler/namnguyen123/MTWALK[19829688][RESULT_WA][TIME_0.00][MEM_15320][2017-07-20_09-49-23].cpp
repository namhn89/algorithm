#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 1;
int h[MAXN][MAXN], vis[MAXN][MAXN];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
queue< pair<int, int> > q;
int n;

int check(int d) {
    memset(vis, 0, sizeof vis);
    q.push({0, 0}); vis[0][0] = 1;
    int ok = 0, x = 0, y = 0, nx, ny;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(x == n - 1 && y == n - 1) ok = 1;
        for(int i = 0; i < 4; i++) {
            nx = x + dr[i];
            ny = y + dc[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[nx][ny] == 0 && abs(h[x][y] - h[nx][ny]) <= d) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if(ok) return 1;
    else return 0;
}

int Bsearch(int l, int r) {
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(check(mid)) return Bsearch(l, mid);
    else return Bsearch(mid + 1, r);
}

int main() {
#define task "1."
    //freopen(task"inp", "r", stdin); freopen(task"out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) scanf("%d", &h[i][j]);

    int minH = h[0][0], maxH = h[n - 1][n - 1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            minH = min(minH, h[i][j]);
            maxH = max(maxH, h[i][j]);
        }
    
    printf("%d\n", Bsearch(0, maxH - minH));
    return 0;
}
