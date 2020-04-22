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

vector<pair<long long, int>> fact (long long n) {
  vector <pair<long long, int>> res; 
  for(long long i = 2 ; i * i <= n; ++i) {
    if (n % i == 0) {
      int c = 0; 
      while(n % i == 0) c++, n /= i; 
      res.push_back(make_pair(i, c)); 
    }
  }
  if (n > 1) res.push_back(make_pair(n, 1)); 
  return res; 
}

long long cnt (long long n, long long b) {
  long long res = 0; 
  while (n) {
    res += n / b; 
    n /= b; 
    /* code */
  }
  return res; 
}

long long powNumber(long long n, long long b)
{
  long long res = 0; 
  vector<pair<long long, int>> a = fact(b); 
  long long ans = 9223372036854775807; 
  for (auto c : a) {
    // cout << c.first << " " << c.second << endl; 
    ans = min(ans, cnt(n, c.first) / c.second); 
  }
  return ans; 
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << powNumber(25, 8) << endl; 
     
  return 0;
}