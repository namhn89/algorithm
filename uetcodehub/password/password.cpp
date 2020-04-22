using namespace std;
#include<bits/stdc++.h>

int main() {
  #define TASK "test"
  freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; 
  map<string, int> f; 
  for (int i = 0; i < n; ++i) {
    string s; 
    cin >> s;
    string revS = s; 
    reverse(revS.begin(), revS.end()); 
    if (f[revS] == 1) {
      cout << s.size() << " " << s[s.size() / 2];
      return 0; 
    }
    else {
      f[s] = 1; 
    }
  }
     
  return 0;
}