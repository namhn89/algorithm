using namespace std;
#include<bits/stdc++.h>

int main() {
  #define TASK "test"
  freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, k;
  cin >> n >> k; 
  vector <vector <int>> a(n); 
  for (int i = 0; i < n; ++i) {
    int sz; 
    cin >> sz; 
    a[i].resize(sz); 
    for (int j = 0; j < sz; ++j) {
      cin >> a[i][j]; 
    }
  }
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y; 
    cout << a[x][y] << endl; 
  }
  return 0;
}