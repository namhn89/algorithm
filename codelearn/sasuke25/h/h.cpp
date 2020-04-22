using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;

int bit[N]; 

int n = 4e4 + 1; 

void update(int pos) {
  for ( ; pos >= 1; pos -= pos & -pos) {
    bit[pos] += 1;
  }
}

int get(int pos) {
  int ans = 0;
  for ( ; pos <= n; pos += pos & -pos) {
    ans += bit[pos];
  }
  return ans;
}

int getInvCount (const vector<int> a) {
  int inv_count = 0;
  for(int i = 0; i < a.size() - 1; ++i) {
    for(int j = i + 1; j < a.size(); ++j) {
      if (a[i] && a[j] && a[i] > a[j]){
        inv_count += 1; 
      }
    }
  }
  return inv_count; 
}

int countInv (const vector <int> a) {
  int ans = 0; 
  n = a.size();
  for (int i = 0; i < a.size(); ++i) {
    ans += get(a[i] + 1); 
    update(a[i]);
  }
  return ans; 
}

int findPosition (vector<vector<int>> a) {
  for(int i = a.size() - 1; i >= 0; --i) {
    for(int j = a[i].size() - 1; j >= 0; --j) {
      if (a[i][j] == -1) {
        return a.size() - i; 
      }
    }
  }
}

bool gameShapedBuilding(std::vector<std::vector<int>> a){
  vector<int> arr; 
  int n = a.size();
  int m = a[0].size(); 
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < a[i].size(); ++j) {
        if (a[i][j] == -1) continue; 
        arr.push_back(a[i][j]); 
    }
  }
  // for (int p: arr) cout << p << " "; cout << endl;
  int inv_count = countInv(arr);
  // cout << inv_count << endl;   
  if (n & 1) {
    return !(inv_count & 1) ; 
  }
  else {
    int pos = findPosition(a); 
    if (pos & 1) {
      return !(inv_count & 1) ; 
    }
    else
    {
      return (inv_count & 1); 
    } 
  }
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  vector <int> a = {1, 3}; 
  vector <int> b = {2, -1};
  vector <vector<int>> p; 
  p.push_back(a);
  p.push_back(b);  
  cout << gameShapedBuilding(p) << endl; 
  return 0;
}