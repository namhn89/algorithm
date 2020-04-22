using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e2 + 1;
const int MOD = 1e9 + 7; 

vector <int> g[N]; 
int color[N][N][N][3]; 
int nChild[N][N][N][3];   

struct Data {
  int x, y, z, t, c;
  Data () {}; 
  Data (int x, int y, int z, int t, int c) : x(x), y(y), z(z), t(t), c(c) {}

}; 

struct State {
  int m, c, c2, t;
  State () {}; 
  State (int m, int c, int c2, int t) : m(m), c(c), c2(c2), t(t) {} 
} a[N];

int nparent = 0;   

void parent(int m, int c, int c2, int t) {
  nparent = 0; 
  if (t == 0) {
    for (int i = 0; i < g[c2].size(); ++i) {
      a[nparent] = State(m, c, g[c2][i], 2); 
      nparent++; 
    }
  }
  if (t == 1) {
    for (int i = 0; i < g[m].size(); ++i) {
      a[nparent] = State(g[m][i], c, c2, 0); 
      nparent++; 
    }
  }
  if (t == 2) {
    for (int i = 0; i < g[c].size(); ++i) {
      a[nparent] = State(m, g[c][i], c2, 1);
      nparent++;  
    }
  } 
}

int safeCells(int n, std::vector<std::vector<int>> connections, std::vector<int> locations) {
  for (int i = 0; i < n; ++i) g[i].push_back(i);
  for (int i = 0; i < connections.size(); ++i) {
      int u = connections[i][0];
      int v = connections[i][1];
      u--, v--; 
      g[u].push_back(v);
      g[v].push_back(u); 
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        nChild[i][j][k][0] = g[i].size();
        nChild[i][j][k][1] = g[j].size();
        nChild[i][j][k][2] = g[k].size(); 
      }
    }
  }

  queue<Data> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int t = 1; t <= 2; ++ t){
        if (t == 1) {
          for (int v: g[i]){
            color[v][i][j][t] = 1; 
            q.push(Data(v, i, j, t, 1)); 
          }
        }
        if (t == 2) {
          for (int v: g[j]) {
            color[v][i][j][t] = 1;
            q.push(Data(v, i, j, t, 1));
          }
        }
      }
    }
  }
  
  while(!q.empty()) {
    Data curData = q.front(); 
    q.pop(); 
    int mouse = curData.x; 
    int cat = curData.y;
    int cat2 = curData.z;
    int turn = curData.t; 
    int colorcurrent = curData.c;
    parent(mouse, cat, cat2, turn); 
    for (int i = 0; i < nparent; ++i) {
      int m = a[i].m; 
      int c = a[i].c; 
      int c2 = a[i].c2; 
      int t = a[i].t ; 
      if (color[m][c][c2][t] == 0) {
        if (colorcurrent == 1 && (t == 1 || t == 2)) {
          color[m][c][c2][t] = colorcurrent; 
          q.push(Data(m, c, c2, t, colorcurrent)); 
        }
        else if (colorcurrent == 2 && t == 0) {
          color[m][c][c2][t] = colorcurrent; 
          q.push(Data(m, c, c2, t, colorcurrent)); 
        }
        else
        {
          nChild[m][c][c2][t] -= 1; 
          if (nChild[m][c][c2][t] == 0) {
            if (t == 1 || t == 2) {
              color[m][c][c2][t] = 2; 
              q.push(Data(m, c, c2, t, 2)); 
            }
            else
            {
              color[m][c][c2][t] = 1; 
              q.push(Data(m, c, c2, t, 1)); 
            }   
          }
        }
      }
    } 
  }
  int x = locations[0], y = locations[1]; 
  x--, y--;
  int ans = 0; 
  for (int i = 0; i < n; ++i) {
      bool ok = true; 
      if (color[i][x][y][0] == 1) {
        ok = false; 
      }
      if (ok) {
        ans += 1; 
      }
  } 
  return ans; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  return 0;
}