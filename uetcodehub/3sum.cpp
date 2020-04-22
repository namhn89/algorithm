using namespace std;
#include<bits/stdc++.h>
 
const int N = 1e5 + 1; 
int a[N]; 
int n; 
int main() {
  #define TASK "test"
  freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n; 
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n); 
  for (int i = 0; i < n; ++i) {
      if (a[i] > 0) break; 
      if (i > 0 && a[i] == a[i - 1]) continue; 
      int left = i + 1, right = n - 1; 
      while(left < right) {
          int sum = a[i] + a[left] + a[right]; 
          if (sum < 0) {
              ++left; 
          }
          else if (sum > 0) {
              --right; 
          }
          else {
            cout << a[i] << " " << a[left] << " " << a[right] << endl; 
            int last_l = a[left]; 
            int last_r = a[right]; 
            while(left < right && a[left] == last_l) ++left; 
            while(left < right && a[right] == last_r) --right; 
          } 
      }
  }
  return 0;
}