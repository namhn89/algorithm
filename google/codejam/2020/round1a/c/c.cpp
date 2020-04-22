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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1}; 
int r, c; 
int a[N][N]; 
void solve() { 
  cin >> r >> c; 
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> a[i][j]; 
    }
  }
  
  bool change = true; 
  long long ans = 0;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      ans += a[i][j]; 
    }
  }

  bool ok = false; 
  while(1) {
    vector <pair<int, int>> eliminated; 

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (a[i][j] == 0) continue; 
        vector <int> z; 
        z.clear(); 
        for (int k = 0; k < 4; ++k) {
          int xx = i + dx[k]; 
          int yy = j + dy[k]; 
          if (xx < 0 || yy < 0 || xx >= r || yy >= c) continue;
          if (a[xx][yy] == 0) continue;  
          z.push_back(a[xx][yy]); 
        }
        if (z.size() == 0) continue;
        int s = 0; 
        for (int v: z) s += v;
        if (s > a[i][j] * z.size()) {
          eliminated.push_back(make_pair(i, j)); 
        }
      }
    }

    if (eliminated.size() == 0) {
      ok = true;
      break;   
    }

    if (ok) break;

    for (auto v: eliminated) {
      int x = v.st, y = v.nd; 
      a[x][y] = 0; 
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        ans += a[i][j]; 
      }
    }
  }

  cout << ans << "\n"; 
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  cin >> t; 
  for(int iTest = 0; iTest < t; ++iTest) { 
    cout <<"Case #"<< iTest + 1 <<": ";
    solve(); 
  }   
  return 0;
}