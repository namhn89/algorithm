#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = (int) 1e5 + 10;

int n;
int x[N];

inline int gcd(int a, int b) {
  while (a > 0  && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

int main() {
  cin >> n;
  int ttt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    ttt = gcd(ttt, x[i]);
  }
  if (ttt > 1) {
    printf("YES\n0");
    return 0;
  }
  int res = 0;
  for (int i = 1; i < n; i++) {
    if (x[i] & 1) {
      if (x[i + 1] & 1) {
        int a = x[i];
        int b = x[i + 1];
        x[i] = abs(a - b);
        x[i + 1] = a + b;
        res++;
      } else {
        int a = x[i];
        int b = x[i + 1];
        x[i] = abs(a - b);
        x[i + 1] = a + b;
        a = x[i];
        b = x[i + 1];
        x[i] = abs(a - b);
        x[i + 1] = a + b;
        res += 2;
      }
    } 
  }
  if (x[n] & 1) {
    int a = x[n - 1];
    int b = x[n];
    x[n - 1] = abs(a - b);
    x[n] = a + b;
    a = x[n - 1];
    b = x[n];
    x[n - 1] = abs(a - b);
    x[n] = a + b;
    res += 2;
  }
  printf("YES\n%d", res);
  return 0; 
}