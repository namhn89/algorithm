using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e6 + 1;
const int MOD = 1e9 + 7; 
int a[N], b[N], n, m, p; 
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  t = 1; 
  while (t--) {
    cin >> n >> m >> p; 
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    for (int i = 0; i < m; ++i) cin >> b[i]; 
    int idxA = 1, idxB = 1; 
    for (int i = 0; i < n; ++i) {
      if (a[i] % p != 0) {
        idxA = i; 
        break; 
      }
    }
    for (int i = 0; i < m; ++i) {
      if (b[i] % p != 0) {
        idxB = i; 
        break; 
      }
    }
    cout << idxA + idxB << endl; 
  }
     
  return 0;
}