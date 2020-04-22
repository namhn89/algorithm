using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e7 + 5;
const int MOD = 1e9 + 7; 
int f[N]; 
int countWaySum(int n, int a, int b)
{ 
  f[0] = 1; 
  for (int i = 1; i <= n; ++i) {
    if (i >= a) {
      f[i] = (f[i] + f[i - a]) % MOD; 
    }
    if (i >= b) {
      f[i] = (f[i] + f[i - b]) % MOD; 
    }
  }
  if (n == 0) return 0; 
  return f[n]; 
}
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, a, b; 
  cin >> n >> a >> b;
  cout << countWaySum(n, a, b) << endl; 
  return 0;
}