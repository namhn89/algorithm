using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e3 + 5;
const int MOD = 1e9 + 7; 

int n, source, sink;
int G[N][N], F[N][N];
bitset<N> visited;
int change[N], trace[N], Q[N];

bool bfs() {
    visited.reset();
    int first(0), last(0);
    Q[first] = source;
    visited[source] = true;
    while (first <= last) {
        int u = Q[first++];
        for (int i=1; i<=n; i++) if (!visited[i]) {
            if (G[u][i] > F[u][i]) {
                change[i] = min(change[u], G[u][i] - F[u][i]);
                trace[i] = u;
            } else if (F[i][u] > 0) {
                change[i] = min(change[u], F[i][u]);
                trace[i] = -u;
            } else continue;

            if (i == sink) return true;
            Q[++last] = i;
            visited[i] = true;
        }
    }
    return false;
}

void update_flow() {
    int v = sink;
    while (v != source) {
        int u = trace[v];
        if (u > 0) F[u][v] += change[sink];
        else {
            u = -u;
            F[v][u] -= change[sink];
        }
        v = u;
    }
}

int max_flow() {
    change[source] = 1e9;
    int flow = 0;
    while (bfs()) {
        flow += change[sink];
        update_flow();
    }
    return flow;
}

int maxEfficiencies(std::vector<int> jobBenefits, std::vector<std::vector<int>> jobDependencies){
  n = jobBenefits.size(); 
  source = n + 1; 
  sink = n + 2; 
  int res = 0; 
  for (int i = 1; i <= n; ++i) {
      int v = jobBenefits[i - 1]; 
      if (v >= 0) {
        G[source][i] = v; 
        res += v; 
      }
      else {
        G[i][sink] = -v; 
      }
  }
  int m = jobDependencies.size(); 
  for (int i = 0; i < m; ++i) {
    int u = jobDependencies[i][0]; 
    int v = jobDependencies[i][1]; 
    G[u][v] = res + 1; 
  }
  n = n + 2;
  return res - max_flow();
} 

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <int> c {10, 4, -5, 3, -1, -2}; 
  vector <vector<int>> a {{2, 3}, {2, 5}, {6, 5}, {4, 3}};
  cout << maxEfficiencies(c, a) << endl; 
     
  return 0;
}