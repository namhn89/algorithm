#include <iostream>
#include <cstdio>

using namespace std;

const int N = (int) 1e5 + 10;

int a[N], b[N], n;

int main() {
  cin >> n;
  bool dec = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] != b[i]) {
      cout << "rated";
      return 0;
    }
    if (a[i] > a[i - 1] && i > 1) {
      dec = true;
    }
  }
  if (dec == false) {
    cout << "maybe";
  } else {
    cout << "unrated";
  }
  return 0;
}