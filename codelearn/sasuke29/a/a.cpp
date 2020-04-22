using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e5 + 1;
const int MOD = 1e9 + 7; 

bool isPrime (int n) {
  if (n < 2) return false; 
  if (n == 2) return true; 

  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false; 
  }
  return true; 
}

int findNumber(int n) {
  vector <int> v; 
  for (int i = 2; i <= 2000; ++i) {
    if (v.size() > 100) {
      break; 
    }
    if (isPrime(i)) {
      v.push_back(i); 
    } 
  }
  return n * v[n - 1];
}


 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}