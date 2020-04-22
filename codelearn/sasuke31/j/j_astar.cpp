using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
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

using State = tuple<int, int, int>; 
using PairCost = tuple<int, int, State>; 
map<State, int> f; 

int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 
int w, n, source; 

vector <pair<int, int>> candidate;

int getmaskx(const int &z) {
  if (z >= n) return 0; 
  return (1 << z); 
}

int getmasky(const int &z) {
  if (z < n) return 0; 
  return (1 << (z - n)); 
}

bool check (const int &maskx, const int &masky) {
    int nbitx = __builtin_popcount(maskx); 
    int nbity = __builtin_popcount(masky);
    int z = nbitx - nbity;
    if (z < 0 || z > w) return false; 
    return true; 
}

int calculateHValue(const State &state) {
  /// Caculate heuristic function 
    int ed, maskx, masky; 
    tie(ed, maskx, masky) = state;
    int res = 0;
    // cout << "State Caculate : " << ed << " " << maskx << " " << masky << endl; 
    // cout << "Start : " << ed << endl;
    int bit_full = (1 << n) - 1;  
    while(true) {
        if (maskx == bit_full && masky == bit_full) break; 
        // cout << ed << " " << maskx << " " << masky; 
        int minD = oo, pos = -1; 
        for (int i = 0; i < n; ++i) {
            // check 
            if (i == ed) continue; 
            if (maskx & getmaskx(i)) continue;
            int newMaskx = maskx ^ getmaskx(i);
            if (check(newMaskx, masky) == false) continue;  

            if (minD > dist[ed][i] && dist[ed][i] != oo) {
                minD = dist[ed][i]; 
                pos = i;  
            } 
        }

        for (int i = n; i < 2 * n; ++i) {
            // check 
            if (i == ed) continue; 
            if (masky & getmasky(i)) continue;
            int newMasky = masky ^ getmasky(i);
            if (check(maskx, newMasky) == false) continue;

            if (minD > dist[ed][i] && dist[ed][i] != oo) {
                minD = dist[ed][i]; 
                pos = i;   
            }
        }
        if (pos < n) {
            maskx = maskx ^ getmaskx(pos); 
        }
        else { 
            masky = masky ^ getmasky(pos); 
        }
        ed = pos; 
        res += minD;
        // cout <<  " --> " << ed << " " << maskx << " " << masky << endl; 
        if (maskx == bit_full && masky == bit_full) break; 
    }
    // cout << "Result : " << res << endl; 
    // cout << endl; 
    return res; 
}


int solveAStarSearch() {
    priority_queue<PairCost, vector<PairCost>, greater<PairCost>> pq; 
    for (int i = 0; i < n; ++i) {
        State state = make_tuple(i, (1 << i), 0); 
        int cost = dist[source][i]; 
        PairCost base = make_tuple(cost, cost, state);
        pq.push(base); 
        f[state] = cost;  
    }
    int bit_full = (1 << n) - 1; 
    while(!pq.empty()) {
        int valf, valg; 
        State cur; 
        tie(valf, valg, cur) = pq.top(); 
        pq.pop();

        if (valg != f[cur]) continue;
        int maskx, lst, masky; 
        tie(lst, maskx, masky) = cur; 

        // cout << valf << " " << valg << " " << lst << " " << maskx << " " << masky << endl; 

        if (maskx == bit_full && masky == bit_full) {
            return valg; 
        }

        for (int i = 0; i < n; ++i) {
            // check 
            if (i == lst) continue;
            if (getmaskx(i) & maskx) continue;
            if (dist[lst][i] == oo) continue; 
            int newMaskx = getmaskx(i) ^ maskx;
            if (check(newMaskx, masky) == false) continue;  

            State newState = make_tuple(i, newMaskx, masky) ;
            int valh = calculateHValue(newState); 
            int newValg = valg + dist[lst][i] ; 
            // cout << "State ( " << i << ", " << newMaskx << ", " << masky << " )"  << " : " << valh << endl; 

            if (f.find(newState) == f.end() || newValg < f[newState]) {
                f[newState] = newValg; 
                int newValf = newValg + valh;
                // cout << " --> " << newValf << " " << newValg << " " << i << " " << newMaskx << " " << masky << endl;
                pq.push(make_tuple(newValf, newValg, newState));  
            }

        }

        for (int i = n; i < 2 * n; ++i) {
            // check 
            if (i == lst) continue;
            if (getmasky(i) & masky) continue; 
            if (dist[lst][i] == oo) continue; 
            int newMasky = getmasky(i) ^ masky;
            if (check(maskx, newMasky) == false) continue;   

            State newState = make_tuple(i, maskx, newMasky) ; 
            int valh = calculateHValue(newState); 
            int newValg = valg + dist[lst][i] ; 
            // cout << " --> " << valh + valf << " " << newValg << " " << i << " " << maskx << " " << newMasky << endl; 
            // cout << "State ( " << i << ", " << maskx << ", " << newMasky << " )"  << " : " << valh << endl; 
            if (f.find(newState) == f.end() || newValg < f[newState]) {
                f[newState] = newValg; 
                int newValf = newValg + valh;
                // cout << " --> " << newValf << " " << newValg << " " << i << " " << maskx << " " << newMasky << endl; 
                pq.push(make_tuple(newValf, newValg, newState));  
            }

        }
    }

    return -1; 
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

  int ans = solveAStarSearch(); 
  return ans; 
}

int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <string> wh;
   
  wh.push_back("10001"); 
  wh.push_back("11141"); 
  wh.push_back("11001"); 
  wh.push_back("21001");
  wh.push_back("11133"); 
  wh.push_back("11000");
  wh.push_back("11111"); 
  wh.push_back("11111"); 
  wh.push_back("11111");
  wh.push_back("14111");

  cout << shortestRobotPath(wh, 1) << endl; 
     
  return 0;
}