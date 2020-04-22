using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))

const int N = 1e5 + 1; // careful
const int MOD = 1e9 + 7;
int moveX [] = {-1, 1, 0, 0};
int moveY [] = {0, 0, -1, 1};
int a[55][55];
int id[55][55];
int d[55][55];
const int NMAX = 505;
const int UNMATCH = -1;
int c[NMAX][NMAX], n;
int XX[NMAX], YY[NMAX], pre[NMAX], vis[NMAX];
vector<pair<int, int> > g[NMAX];
void match(int u, int v){
  XX[u] = v;
  YY[v] = u;
}
int aug(int u, int Lim){
  queue<int> q;
  for(int v = 1; v <= n; v++) vis[v] = 0;
  q.push(u);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto e : g[u]){
      int v = e.first;
      int l = e.second;
      if(v == XX[u] || vis[v] || l > Lim) continue;
      vis[v] = 1;
      if(YY[v] == UNMATCH){
        pre[v] = u;
        return v;
      }
      else {
        pre[v] = u;
        q.push(YY[v]);
      }
    }
  }
  return -1;
}
void enlarge(int v){
  while(true){
    int u = pre[v];
    if(XX[u] == UNMATCH){
      match(u, v);
      return;
    }
    int t = XX[u];
    match(u, v);
    YY[t] = UNMATCH;
    v = t;
  }
}
void greedy(int Lim){
  for(int u = 1; u <= n; u++){
    if(XX[u] == UNMATCH){
      for(auto e : g[u]){
        int v = e.first;
        int l = e.second;
        if(l > Lim) continue;
        if(YY[v] == UNMATCH){
          match(u, v);
          break;
        }
      }
    }
  }
}
bool Check(int Lim){
  for(int u = 1; u <= n; u++) XX[u] = UNMATCH;
  for(int v = 1; v <= n; v++) YY[v] = UNMATCH;
  greedy(Lim);
  memset(pre, 0, sizeof(pre));
  for(int u = 1; u <= n; u++){
    if(XX[u] == UNMATCH){
      int v = aug(u, Lim);
      if(v == -1) continue;
      enlarge(v);
    }
  }
  for(int u = 1; u <= n; u++){
    if(XX[u] == UNMATCH) return false;
  }
  return true;
}
bool inRange (int x, int y, int rows, int cols) {
    return min(x, y) >= 1 && x <= rows && y <= cols;
}
int treasurePath(std::vector<std::string> islandMap)
{
    int rows, cols;
    rows = islandMap.size();
    cols = islandMap[0].size();
    int cnt = 0;
    int cnt2 = 0;
    int xs, ys;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {

            a[i][j] = islandMap[i - 1][j - 1] - '0';
            if (a[i][j] == 3) {
            	id[i][j] = ++cnt;
            } else if (a[i][j] == 4) {
                id[i][j] = ++cnt2;
            } else if (a[i][j] == 0) {
                xs = i;
                ys = j;
            }
        }
    }
    /*cout << xs << " " << ys << endl;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cout << id[i][j] << " ";
        }
        cout << endl;
    }*/
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (a[i][j] == 3) {
                queue<pair<int, int> > q;

                q.push(pair<int, int> (i, j));
                for (int x = 1; x <= rows; x++) {
                	for (int y = 1; y <= cols; y++) {
                		d[x][y] = -1;
                	}
                }
                d[i][j] = 0;
                q.push(make_pair(i, j));
                while (not q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                    	int x2 = x + moveX[dir];
                    	int y2 = y + moveY[dir];
                    	if (inRange(x2, y2, rows, cols) && a[x2][y2] != 2 && d[x2][y2] == -1) {
                            d[x2][y2] = d[x][y] + 1;
                            q.push(pair<int, int>(x2, y2));
                    	}
                    }
                }
                //cout << endl;
                //cout << "table" << endl;
                /*for (int x = 1; x <= rows; x++) {
                    for (int y = 1; y <= cols; y++) {
                        cout << d[x][y] << " ";
                    }
                    cout << endl;
                }
                cout << endl;*/
                for (int x = 1; x <= rows; x++) {
                    for (int y = 1; y <= cols; y++) {
                        if (d[x][y] != -1 && d[xs][ys] != -1 && a[x][y] == 4) {
                            //cout << id[i][j] << " " << id[x][y] << " " << d[x][y] + d[xs][ys] << endl;
                            g[id[i][j]].push_back(make_pair(id[x][y], d[x][y] + d[xs][ys]));
                        }
                    }
                }
            }
        }

    }
    n = cnt;
    int lo = 0, hi = 1000000, res = -1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (Check(mi)) {
            res = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    return res;
}


