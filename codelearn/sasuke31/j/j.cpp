using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 40 + 1;
const int M = 10; 
const int MOD = 1e9 + 7; 
const int oo = 1e9 + 2000; 
int dist[N][N]; 
int d[N][N]; 

int dp[(2 * M)][(1 << M)][(1 << M)]; 

int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 
int w; 
int n; 
int source; 
vector <pair<int, int>> candidate; 

int getmaskx(int z) {
  if (z >= n) return 0; 
  return (1 << z); 
}
int getmasky(int z) {
  if (z < n) return 0; 
  z -= n; 
  return (1 << z); 
}

int solve() {

  for (int i = 0; i < 2 * n; ++i) {
    for (int maskx = 0; maskx < (1 << n); ++maskx) {
      for (int masky = 0; masky < (1 << n); ++masky) {
          dp[i][maskx][masky] = oo; 
      }
    }
  }
  // initialize dp  
  for (int i = 0; i < n; ++i) {
    dp[i][(1 << i)][0] = dist[source][i]; 
  }

 // for (int i = 0; i < 2 * n; ++i) {
    for (int maskx = 0 ; maskx < (1 << n); ++maskx) {
      for (int masky = 0 ; masky < (1 << n); ++masky) {
        for (int i = 0; i < 2 * n; ++i) {
        
        if (i < n && !(maskx & getmaskx(i)) ) continue; 
        if (i >= n && !(masky & getmasky(i)) ) continue; 

        int nbitx = __builtin_popcount(maskx); 
        int nbity = __builtin_popcount(masky);
       // cout << "Count bit : " << endl; 
       // cout << maskx << " " << nbitx << endl; 
       // cout << masky << " " << nbity << endl; 
        int z = nbitx  - nbity;  
        // if (i == 2 && maskx == 1 && masky == 1) cout << " ON " << endl; 
        if (z < 0 || z > w) continue; 
        int p = z - (i < n) + (i >= n);
        if (p < 0 || p > w) continue;  
        // if (i == 2 && maskx == 3 && masky == 1) cout << "ON" << endl; 
        for (int j = 0; j < 2 * n; ++j) {
          if (j != i && ((getmaskx(j) & maskx) || (getmasky(j) & masky)) ) {
            if (i < n) {
              if (dp[j][(maskx ^ getmaskx(i))][masky] == oo) continue; 
              dp[i][maskx][masky] = min(dp[i][maskx][masky], dp[j][(maskx ^ getmaskx(i))][masky] + dist[j][i]);
              //cout << i << " " << maskx << " " << masky << "  <---  " << j << " " << (maskx ^ getmaskx(i)) << " " << masky << endl;
            }
            else {
              if (dp[j][maskx][(masky ^ getmasky(i))] == oo) continue;
              dp[i][maskx][masky] = min(dp[i][maskx][masky], dp[j][maskx][(masky ^ getmasky(i))] + dist[j][i]); 
              //cout << i << " " << maskx << " " << masky << "  <---  " << j << " " << maskx << " " << (masky ^ getmasky(i)) << endl;
            }
          }  
        } 
      }
    }
  }
  int ans = oo; 
  for (int i = n; i < 2 * n; ++i) ans = min(ans, dp[i][(1 << n) - 1][(1 << n) - 1]); 
  if (ans == oo) return -1; 
  else return ans; 
}

int shortestRobotPath(std::vector<std::string> grid, int k) {
  w = k; 
  int nr = grid.size(); 
  int nc = grid[0].size(); 
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j] == '3') {
        candidate.push_back(make_pair(i, j)); 
      }
    }
  }

  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j] == '4') {
        candidate.push_back(make_pair(i, j)); 
      }
    }
  }

  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[i].size(); ++j) {
      if (grid[i][j] == '2') {
        candidate.push_back(make_pair(i, j)); 
      }
    }
  }

  n = (candidate.size() - 1) / 2; 
  source = candidate.size() - 1; 

  for (int src = 0; src <= 2 * n; ++src) {
    for (int x = 0; x < nr; ++x) {
      for (int y = 0; y < nc; ++y) {
        d[x][y] = oo; 
      }
    }
    int srcx = candidate[src].first; 
    int srcy = candidate[src].second;

    d[srcx][srcy] = 0;  
    queue<int> q; 
    q.push(srcx); 
    q.push(srcy); 

    while(!q.empty()) {
      int u = q.front(); q.pop(); 
      int v = q.front(); q.pop(); 
      for (int k = 0; k < 4; ++k) {
        int ux = u + dx[k]; 
        int uy = v + dy[k];
        if (ux < 0 || ux >= nr || uy < 0 || uy >= nc) continue; 
        if (grid[ux][uy] == '0') continue; 
        if (d[ux][uy] == oo) {
          d[ux][uy] = d[u][v] + 1; 
          q.push(ux);
          q.push(uy); 
        }/* condition */
      }
    }

    for (int dst = 0; dst <= 2 * n; ++dst) {
      int x = candidate[dst].first; 
      int y = candidate[dst].second; 
      dist[src][dst] = d[x][y];  
      // cout << src << " " << dst << " " << d[x][y] << endl;   
    }
  }

  int ans = solve(); 
  return ans; 
}
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <string> wh; 
  wh.push_back("11011"); 
  wh.push_back("20011"); 
  wh.push_back("10411"); 
  wh.push_back("10313");
  wh.push_back("11114"); 
  wh.push_back("11111"); 
  cout << shortestRobotPath(wh, 1) << endl; 
     
  return 0;
}