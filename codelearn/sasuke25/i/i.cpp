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
const int INF = 0x3f3f3f3f; 

int dist[N];
int visit[N];  
int nVertex; 

vector <pair<int, pair<int, int>>> Edges ; 


void addEdge (int u, int v, int w) {
 Edges.push_back(make_pair(u, make_pair(v, w)));  
}


int bellmanford (int src, int dst) {
  for (int i = 0; i <= nVertex; ++i) dist[i] = INT_MAX;
  dist[src] = 0;
  for (int i = 0; i <= nVertex; ++i) {
    for(int j = 0; j < Edges.size(); ++j) {
      int u = Edges[j].st; 
      int v = Edges[j].nd.st; 
      int w = Edges[j].nd.nd; 
      if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w; 
      }
    }
  } 

  return dist[dst]; 
}


int rainnyDays(int n, std::vector<std::vector<int>> predictions) {
  nVertex = n; 
  for (int i = 0; i < predictions.size(); ++i) {
    int u = predictions[i][0]; 
    int v = predictions[i][1]; 
    int w = predictions[i][2];
    addEdge(u - 1, v, w);  
    addEdge(v, u - 1, -w); 
  }

  for (int i = 0; i < n; ++i) {
    addEdge(i + 1, i, 0);
    addEdge(i, i + 1, 1);  
  }
  int maxAns = bellmanford(0, n); 
  int minAns = -bellmanford(n, 0); 


  return minAns + maxAns; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <vector<int>> a; 
  vector <int> a1 = {1, 2, 1}; 
  vector <int> a2 = {2, 3, 1}; 
  a.push_back(a1);
  a.push_back(a2); 
  cout << rainnyDays(3, a) << endl; 
  
 
  return 0;
}