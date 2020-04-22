#include <bits/stdc++.h>
using namespace std;

int main() {
 // freopen("vao.nhivd", "r", stdin);
  int n, b, d;
  int cur = 0, res = 0;
  scanf("%d %d %d", &n, &b, &d);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x > b) continue;
    cur += x;
    if (cur > d) {
      cur = 0;
      res++;
    }
  }
  printf("%d", res);
  return 0;
}
