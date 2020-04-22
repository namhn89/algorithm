#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int n;
  cin >> n;
  int run = 0;
  for (int i = 1; i <= n; i++) {
    cout << (run < 2 ? 'a' : 'b');
    run = (run + 1) % 4; 
  }
  return 0;
}