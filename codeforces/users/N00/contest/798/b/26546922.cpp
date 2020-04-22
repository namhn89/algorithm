#include <iostream>
#include <cstdio>

using namespace std;

const int N = 55;
const int INF = (int) 2e9 + 9;

string x[N];
int n;

void minimize(int &compare, string sys) {
  int moved = 0;
  for (int i = 1; i <= n; i++) {
    bool checked = false;
    int total = 0;
    if (x[i] == sys) continue;
    for (int j = 0; j < x[i].size() - 1; j++) {
      string y = x[i].substr(j + 1, x[i].size() - j + 1) + x[i].substr(0, j + 1);
      if (y == sys) {
        checked = true;
        moved += j + 1;
        break;
      }
    } 
    if (checked == false) {
      moved = INF;
      break;
    }
  }
  compare = min(compare, moved);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  int res = INF;
  for (int i = 1; i <= n; i++) {
    minimize(res, x[i]);
  }
  printf("%d", res == INF ? -1 : res);
  return 0;
}