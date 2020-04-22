using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e6 + 1;
const int MOD = 1e9 + 7; 

int n;
int c[N];
int l[N], r[N];

std::vector<int> rainWater(std::vector<int> a)
{
  n = a.size();
  for (int i = 1; i <= n; i++) c[i] = a[i - 1];
  l[1] = c[1]; 
  r[n] = c[n];
  for (int i = 2; i <= n; i++) {
    l[i] = max(l[i - 1], c[i]); }
  for (int i = n - 1; i >= 1; i--) {
    r[i] = max(r[i + 1], c[i]);
  }
  vector <int> res;
  for (int i = 1; i <= n; i++) {
    int x = min(l[i], r[i]);
    res.push_back(x);
  }
  return res;
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}