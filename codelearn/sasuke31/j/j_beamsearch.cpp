using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 50 + 1;
const int M = 10; 
const int MOD = 1e9 + 7; 
const int oo = 1e9 + 2000; 
const int K = 500; 
int dist[N][N]; 
int d[N][N]; 

using State = tuple<int, int, int>; 
using PairCost = tuple<int, State>; 

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

bool check (int maskx, int masky) {
    int nbitx = __builtin_popcount(maskx); 
    int nbity = __builtin_popcount(masky);
    int z = nbitx - nbity;
    if (z < 0 || z > w) return false; 
    return true; 
}

int solveBeamSearch() {

    set<PairCost> curSet, nxtSet; 
    for (int i = 0; i < n; ++i) {
        State state = make_tuple(i, 1 << i, 0);
        int cost = dist[source][i]; 
        curSet.insert(make_tuple(cost, state));  
    }   
    // cout << "Step " << 0 << " : " << endl; 
    // for (auto p: curSet) {
    //     State s; 
    //     int cost; 
    //     tie(cost, s) = p; 
    //     int lst, maskx, masky; 
    //     tie(lst, maskx, masky) = s; 
    //     cout << cost << " " << lst << " " << maskx << " " << masky << endl;
    // }
    // cout << endl;

    for (int step = 1; step < 2 * n; ++step) {
        nxtSet.clear(); 
        for (auto v : curSet) {
            int val; 
            State state; 
            tie(val, state) = v; 
            int lst, maskx, masky; 
            tie(lst, maskx, masky) = state; 
            if (check(maskx, masky) == false) continue;
            for (int i = 0; i < n; ++i) {
                if (i != lst && !(maskx & getmaskx(i))) {
                    int newMaskx = maskx ^ getmaskx(i); 
                    if (check(newMaskx, masky) && dist[lst][i] != oo) {
                        int cost = dist[lst][i] + val; 
                        State nxtState = make_tuple(i, newMaskx, masky); 
                        nxtSet.insert(make_tuple(cost, nxtState)); 
                        if (nxtSet.size() == K + 1) nxtSet.erase(--nxtSet.end());
                    }
                }
            }
            for (int i = n; i < 2 * n; ++i) {
                if (i != lst && !(masky & getmasky(i))) {
                    int newMasky = masky ^ getmasky(i); 
                    if (check(maskx, newMasky) && dist[lst][i] != oo) {
                        int cost = dist[lst][i] + val; 
                        State nxtState = make_tuple(i, maskx, newMasky); 
                        nxtSet.insert(make_tuple(cost, nxtState)); 
                        if (nxtSet.size() == K + 1) nxtSet.erase(--nxtSet.end());
                    }
                }
            }                
        }
        // cout << "Step " << step << " :  " << endl; 
        // for (auto p: nxtSet) {
        //     State s; 
        //     int cost; 
        //     tie(cost, s) = p; 
        //     int lst, maskx, masky; 
        //     tie(lst, maskx, masky) = s; 
        //     cout << cost << " " << lst << " " << maskx << " " << masky << endl; 
        // } 
        // while (nxtSet.size() > K) nxtSet.erase(--nxtSet.end());
        curSet.swap(nxtSet); 
    }
    int ans = oo; 
    vector<PairCost> tmp;
    tmp.assign(curSet.begin(), curSet.end());
    for (auto &v : tmp) {
        ans = min(ans, get<0>(v)); 
    }
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

  int ans = solveBeamSearch(); 
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