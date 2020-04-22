using namespace std;
#include<bits/stdc++.h>
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e6 + 1;
const int MOD = 1e9 + 7; 

int n;
int b[N];
int l[N], r[N];

std::vector<int> maxLengMountain(std::vector<int> a)
{       n = a.size();
    for (int i = 0; i < a.size(); i++) {
        b[i + 1] = a[i];
    }
    b[0] = b[n + 1] = (int) (1e9 + 9);
    for (int i = 1; i <= n; i++) {
        l[i] = i;
        if (b[i] > b[i - 1]) l[i] = l[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        r[i] = i;
        if (b[i] > b[i + 1]) r[i] = r[i + 1];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, i - l[i] + 1 + r[i] - i + 1);
    }
    vector <int> result; 
    if (ans == -1) return result;

    for (int i = 1; i <= n; i++) {
        if (i - l[i] + 1 >= 2 && r[i] - i + 1 >= 2) {
        if (i - l[i] + 1 + r[i] - i + 1 == ans) {
            for (int j = l[i]; j <= r[i]; j++) result.push_back(b[j]);
            return result;
        }
        }
    }
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}