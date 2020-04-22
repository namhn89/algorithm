#include <bits/stdc++.h> 
using namespace std; 
  

int n, m; 
int a[10005]; 
int has[10005]; 
int main() {
  //freopen ("in.inp", "r", stdin); freopen ("in.out", "w", stdout); 
  cin >> n >> m; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  while (m--) {
    int l, r, x; 
    cin >> l >> r >> x;
    memset(has, 0, sizeof(has));  
    for (int i = l; i <= r; i++) {
      has[a[i]]++; 
    }
    vector<int> v; 
    for (int i = 1; i <= n; i++) {
      if (has[i]) v.push_back(i); 
    }
    if (v[x - l] == a[x]) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}