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

#define x first
#define y second

const int INF = (int) 2e9 + 9;

typedef pair <int, int> II;
II a[4];

long long sqr(int x) {
  return 1LL * x * x;
}

long long distance(II u, II v) {
  return sqr(u.x - v.x) + sqr(u.y - v.y);
}

std::vector<int> createRectangle(std::vector<std::vector<int>> points)
{ 

  a[0] = {points[0][0], points[0][1]};
  a[1] = {points[1][0], points[1][1]};
  a[2] = {points[2][0], points[2][1]};

  int idx[4];
  for (int i = 0; i < 3; i++) idx[i + 1] = i;
  do {
    long long d1 = distance(a[idx[1]], a[idx[2]]);
    long long d2 = distance(a[idx[1]], a[idx[3]]);
    long long d3 = distance(a[idx[3]], a[idx[2]]);
    if (d1 + d2 != d3) continue;
    vector <int> tmp;
    tmp.push_back(a[idx[1]].x + a[idx[2]].x + a[idx[3]].x - 2 * a[idx[1]].x);
    tmp.push_back(a[idx[1]].y + a[idx[2]].y + a[idx[3]].y - 2 * a[idx[1]].y);
    return tmp;
  } while (next_permutation(idx + 1, idx + 1 + 3));
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);  

 
  return 0;
}