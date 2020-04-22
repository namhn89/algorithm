#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() == 1) {
    puts("YES");
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i * 2 < s.size(); i++) {
    if (s[i] != s[s.size() - i - 1]) {
      ++cnt;
    }
  }
  puts(cnt == 1 || (cnt == 0 && s.size() % 2 == 1) ? "YES" : "NO");
  return 0;
}