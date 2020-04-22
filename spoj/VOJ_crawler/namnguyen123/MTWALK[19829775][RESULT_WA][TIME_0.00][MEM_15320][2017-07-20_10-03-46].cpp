#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 1;
int h[MAXN][MAXN], vis[MAXN][MAXN];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
queue< pair<int, int> > q;
int n;

void Reset() {
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++) vis[i][j] = 0;
}

int check(int d) {
    for(int l = 0; l <= 111 - d; l++) {
        int r = l + d;
        Reset();
        q.push({0, 0}); vis[0][0] = 1;
        int ok = 0, x = 0, y = 0;
        while(!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(x == n - 1 && y == n - 1) ok = 1;
            for(int i = 0; i < 4; i++) {
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(vis[nx][ny] == 0 && h[nx][ny] >= l && h[nx][ny] <= r) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        if(ok) return 1;
    }
    return 0;
}

int Bsearch(int l, int r) {
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(check(mid)) return Bsearch(l, mid);
    else return Bsearch(mid + 1, r);
}

int main() {
#define task "mtwalk."
    //freopen(task"inp", "r", stdin); freopen(task"out", "w", stdout);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) scanf("%d", &h[i][j]);

    printf("%d\n", Bsearch(0, 110));
    return 0;
}
