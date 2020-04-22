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

std::vector<int> trianglesPointed(int a, int b)
{ 
  if (a < b) swap(a, b);
  long long l = a, r = b; 
  long long x = sqrtl(l * l + r * r);
  if (l * l + r * r == x * x) x--;
  long long y = sqrtl(l * l - r * r);
  if (y * y + r * r <= l * l) y++;
  vector <int> ans;
  int ansL = min(x, y); 
  int ansR = max(x, y);
  ans.push_back(ansL);
  ans.push_back(ansR);
  return ans;
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}