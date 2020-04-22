using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e3 + 1;
const int MOD = 1e9 + 7; 

set<int> s; 
int n; 
int deg[N]; 
int cnt[N][N]; 
int ans = 0; 
vector <int> g[N]; 
int label[N * N]; 

void dfs (int u, int path, bool op) {
  if (ans < path) {
    ans = path; 
  }
  vector <int> nt; 
  for (int v: g[u]) {
    if (cnt[u][v] > 0) {
        nt.push_back(v); 
    }
  }
  sort(nt.begin(), nt.end(), [] (int a, int b) {
      return deg[a] < deg[b]; 
  }); 
  if (op) {
    reverse(nt.begin(), nt.end()); 
  }
  for (int v: nt) {
    cnt[u][v] -= 1; 
    cnt[v][u] -= 1; 
    deg[u] -= 1, deg[v] -= 1;
    dfs(v, path + 1, op); 
    cnt[u][v] += 1; 
    cnt[v][u] += 1; 
    deg[u] += 1; 
    deg[v] += 1; 
  }

}

int longestDominoChain(std::vector<std::vector<int>> tiles) {
  for(auto p: tiles) {
    for(int a: p) {
      s.insert(a); 
    }
  }
  vector <int> idx; 
  for (int v: s) {
    idx.push_back(v);
    // cout << v << " "; 
  }
  // cout << endl; 
  n = idx.size(); 
  for (int i = 0; i < n; ++i) label[idx[i]] = i;  
  for (auto p: tiles){
    int u = label[p[0]], v = label[p[1]]; 
    // cout << u << " " << v << endl; 
    deg[u]++, deg[v]++; 
    cnt[u][v]++; 
    cnt[v][u]++; 
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (cnt[i][j] > 0) {
        g[i].push_back(j); 
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    dfs(i, 0, true); 
    dfs(i, 0, false); 
  }
  return ans; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <vector<int>> a = {{2, 4}, {4, 5}, {2, 4}, {4, 5}};
  cout << longestDominoChain(a) << endl; 
     
  return 0;
}