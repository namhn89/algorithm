using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e3 + 1;
const long long INF = 1e18 + 7; 

typedef pair <long long, int> LII ;
vector <LII> g[N] ;
long long dist[N]; 
int n, src, dst; 
int trace[N]; 
vector <pair<int, pair<int, int>>> Edges; 
vector <int> ans; 

long long convertInt (string s) {
  long long result = 0; 
  for (int i = 0; i < s.size(); ++i) {
    result = result * 10LL + (s[i] - '0'); 
  }
  return result; 
}
map<string, int> label; 

void bfs() {
  for (int i = 0; i < n; ++i) trace[i] = 100001;
  for (int i = 0; i < n; ++i) dist[i] = INF;  
  dist[dst] = 0;
  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < Edges.size(); ++j) {
      int v = Edges[j].st; 
      int u = Edges[j].nd.st; 
      int c = Edges[j].nd.nd;
      if (dist[u] != INF && dist[u] + c < dist[v]) {
        dist[v] = dist[u] + c; 
        trace[v] = u; 
      }
      else if (dist[u] != INF && dist[u] + c == dist[v]) {
        trace[v] = min(trace[v], u); 
      }
    }
  }
}

void bfs_again() {
  ans.push_back(src);
  int u = trace[src];  
  while (u != dst) {
    ans.push_back(u); 
    u = trace[u]; 
    /* code */
  }
  ans.push_back(dst); 
}

std::string travelPath(std::string x, std::string y, std::vector<std::vector<std::string>> paths) {
  vector <string> myVertex; 
  set<string> mySet; 
  mySet.insert(x); 
  mySet.insert(y);  
  removeDuplicate(myVertex);
  for (int i = 0; i < paths.size(); ++i) {
    mySet.insert(paths[i][0]);
    mySet.insert(paths[i][1]); 
  }
  for (auto v : mySet) {
    myVertex.push_back(v); 
  }
  sort(myVertex.begin(), myVertex.end());
  n = myVertex.size();  
  for (int i = 0; i < myVertex.size(); ++i) label[myVertex[i]] = i; 
  src = label[x]; 
  dst = label[y]; 
  for (int i = 0; i < paths.size(); ++i) {
    int u = label[paths[i][0]]; 
    int v = label[paths[i][1]]; 
    int c = convertInt(paths[i][2]); 
    //cout << u << " " << v << " " << c << endl; 
    g[u].push_back(make_pair(v, c)); 
    g[v].push_back(make_pair(u, c));
    Edges.push_back(make_pair(u, make_pair(v, c))); 
    // Edges.push_back(make_pair(v, make_pair(u, c))); 
  }
  bfs();
  // cout << n << " " << src << " " << dst << endl; 
  // cout << dist[src] << endl; 
  bfs_again();
  string result = ""; 
  for (int i = 0; i < ans.size(); ++i) {
   // cout << ans[i] << endl; 
    if (i == 0) {
      result = result + myVertex[ans[i]]; 
    }
    else {
      result = result + ";" + myVertex[ans[i]]; 
    }
  }
  return result; 
}

int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <vector<string>> p; 
  vector <string> a = {"0","1","4"};
  p.push_back(a); 
  a = {"1","3","5"};
  p.push_back(a);
  a = {"3","4","1"}; 
  p.push_back(a); 
  a = {"0","2","1"}; 
  p.push_back(a); 
  a = {"2","4","9"}; 
  cout << travelPath("0", "4", p) << endl;

 
  return 0;
}