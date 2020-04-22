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

int a[200];
int cnt[200]; 

int sumDigit(int x) {
  int res = 0;
  while(x) {
    res += x % 10; 
    x = x / 10; 
  }
  return res; 
} 
int countLargestGroup(int n) {
  int maxS = 0; 
  int maxk = 0; 
  for(int i = 1; i <= n; ++i) {
    int k = sumDigit(i); 
    a[k] += 1;
    maxS = max(maxS, k);  
  }
  for (int i = 1; i <= maxS; ++i) { 
    cnt[a[i]] += 1; 
    maxk = max(maxk, a[i]); 
  }
  return cnt[maxk];  
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << countLargestGroup(13) << endl; 
     
  return 0;
}