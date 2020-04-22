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
bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
    if (x_center >= x1 && y_center >= y1 && x_center <= x2 && y_center <= y2) return true; 
    int distancex = abs(x_center - x1); 
    int distancey = abs(y_center - y1); 
    int width = x2 - x1; 
    int height = y2 - y1; 
    // cout << width << " " << height << endl; 
    if (2 * distancex > (width + radius * 2)) return false; 
    if (2 * distancey > (height + radius * 2)) return false; 

    if (2 * distancex <= (width)) return true; 
    if (2 * distancey <= (height)) return true; 
    int cornerDistance_sq = (distancex * 2 - width) * (distancex * 2 - width) + (distancey * 2 - height) * (distancey * 2 - height); 
    return cornerDistance_sq <= (4 * radius * radius); 
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << checkOverlap(4, 102, 50, 0, 0, 100, 100) << endl; 
  return 0;
}