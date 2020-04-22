using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e2 + 1;
const int MOD = 1e9 + 7; 

int r[N], c[N], o[N], a[N][N]; 
int res = 0; 

void dfs (int i, int j) {
  if (i == 9) {
    res += 1;  
    return; 
  }
  if (a[i][j] != 0) {
    if (j == 8) {
      dfs(i + 1, 0); 
    }
    else
    {
      dfs(i, j + 1); 
    }
    return; 
  }

  int mask = r[i] | c[j] | o[3 * (i / 3) + (j / 3)]; 

  for (int t = 1; t <= 9; ++t) {
    if (((mask >> t) & 1) == 0) {
      a[i][j] = t; 
      r[i] |= 1 << t; 
      c[j] |= 1 << t; 
      o[3 * (i / 3) + (j / 3)] |= 1 << t; 

      if (j == 8) {
        dfs(i + 1, 0); 
      }
      else {
        dfs(i, j + 1); 
      }
      // reset 
      a[i][j] = 0; 
      r[i] ^= (1 << t); 
      c[j] ^= (1 << t); 
      o[3 * (i / 3 ) + (j / 3)] ^= (1 << t); 
    }
  }

}

int countSodokuSolve(std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        a[i][j] = matrix[i][j];
        r[i] |= 1 << a[i][j];
        c[j] |= 1 << a[i][j];
        o[3 * (i / 3) + j / 3] |= 1 << a[i][j];
    }
    dfs(0, 0);
    return res;
}


 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}