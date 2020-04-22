using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 2e5 + 10;
const int MOD = 1e9 + 7; 

int c[N]; 

int busStation(int t, int d, std::vector<int> a)
{
  long long ma = *max_element(a.begin(), a.end()); 
  for (int i = 0; i < a.size(); ++i) {
    c[a[i] + 1] += 1; 
  } 
  int cnt = 0, res = 1; 
  for (int i = 1; i <= ma + 1; ++i) c[i] += c[i - 1]; 
  for (int id = 1; id <= 100004; ++id) {
    long long l,r; 
    int p;  
    l = t + (id - 2) * d; 
    if (l > ma + 1) break; 
    if (id == 1) {
      l = 0 ;
      r = min(ma + 1, 1LL * t + 1); 
      p = c[r] - c[l];
      //cout << id << " " << p << endl; 
      if (p > cnt) {
        res = id;
        cnt = p;  
      } 
    } 
    else {
      l = min(ma + 1, t + 1LL * (id - 2) * d + 1); 
      r = min(ma + 1, t + 1LL * (id - 1) * d + 1); 
      p = c[r] - c[l]; 
      //cout << id << " " << p << endl; 
      if (p > cnt) {
        res = id; 
        cnt = p; 
      } 
    }
  }
  return res; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << busStation(3, 5, vector<int> {3,4,10,6}) << endl; 
     
  return 0;
}