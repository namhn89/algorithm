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
const int INF = 1e9 + 7; 

long long lx, rx, tx, ly, ry, ty; 

int caculate (int k, int k1) {
  if (k < 0 || k1 < 0) return 0; 
  
  long long r = min(rx + 1LL * tx * k, ry + 1LL * ty * k1); 
  long long l = max(lx + 1LL * tx * k, ly + 1LL * ty * k1);  
  if (k == 0 && k1 == 0) {
    /*
    cout << "Debug" << endl; 
    cout << rx << " " << ry << endl; 
    cout << lx << " " << ly << endl; 
    cout << l << " " << r << endl; 
    */
  }
  if (r >= l) {
    return r - l + 1; 
  } 
  return 0; 
  
}
int maximalLucky(int l1, int r1, int t1, int l2, int r2, int t2)
{
  int la = l1, ra = r1, ta = t1, lb = l2, rb = r2, tb = t2; 
  int tg = __gcd(ta, tb);
  int dl = la % tg - lb % tg;
	if (dl < 0) dl += tg;
	int ans = 0;
	ans = max(ans, min(rb - lb + 1 - dl, ra - la + 1));
	ans = max(ans, min(rb - lb + 1, ra - la + 1 - (tg - dl)));
	int dr = ra % tg - rb % tg;
	if (dr < 0) dr += tg;
	ans = max(ans, min(rb - lb + 1, ra - la + 1 - (dr)));
	ans = max(ans, min(ra - la + 1, rb - lb + 1 - (tg - dr)));
  return ans; 
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << maximalLucky(0, 2, 5, 1, 3, 5) << endl;
 
  return 0;
}