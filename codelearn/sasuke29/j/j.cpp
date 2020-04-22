using namespace std;
#include<bits/stdc++.h>
 
const int N = 10;

int n; 
int c[N], x[N], y[N], z[N]; 
int xs, ys, zs, s, k; 


bool check (int index) {
  if (x[0] < 0 || y[0] < 0 || z[0] < 0) { 
    return false;
  }
  if (index > 1) { 
    if (x[index - 1] + y[index - 1] + z[index - 1] > k) {
      return false; 
    }
  }
  if (index == n + 1) {
    return true; 
  }

  if (x[0] * 9 + y[0] * 3 + z[0] < c[0]) {
    return false;
  }

  int sum = c[index]; 
  int nx = (sum + 8) / 9; 
  nx = min(nx, x[0]);

  for (; nx >= 0; nx--) {

    x[index] = nx;
    x[0] -= x[index];
    sum -= x[index] * 9;
    int ny = (sum + 2) / 3;

    if (sum <= 0) ny = 0;
    ny = min(ny, y[0]);

    for (; ny >= 0; ny--) {

      y[index] = ny;
      y[0] -= y[index];
      sum -= y[index] * 3;
      z[index] = max(0, sum);
      z[0] -= z[index];
      c[0] -= c[index];

      int ok = check(index + 1);
      if (ok) return true;

      c[0] += c[index];
      z[0] += z[index];
      y[0] += y[index];
      sum += y[index] * 3;
    }
    sum += x[index] * 9;
    x[0] += x[index];
  }
  return false;
}


int mutaliskAttack(std::vector<int> scvs ) {
  n = scvs.size(); 
  sort(scvs.begin(), scvs.end(), greater<int>());  
  c[0] = 0; 
  for (int i = 0; i < n; i++) c[i + 1] = scvs[i]; 
  for (int i = 1; i <= n; i++) c[0] += c[i];   
  int l = c[0] / 13 , r = 41, res;
  while (l <= r) {
    /* code */
    int mid = (l + r) >> 1;
    k = x[0] = y[0] = z[0] = mid; 
    int ok = check(1);  
    if (ok) {
      res = mid; 
      r = mid - 1; 
    }
    else {
      l = mid + 1; 
    }
  }
  return res; 
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << mutaliskAttack(vector<int> ({54,18,6})) << endl; 
    
  return 0;
}