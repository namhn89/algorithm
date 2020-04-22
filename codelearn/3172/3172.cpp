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

int sum[N]; 

int treeBottom(std::string s) {
    int n = s.size(); 
    int md = 0;
    for (int i = 0; i < n; i++) sum[i] = 0;

    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            cur++;
        else if (s[i] == ')')
            cur--;
        else if ('0' <= s[i] && s[i] <= '9') {
            int v = s[i] - '0';
            for (; i + 1 < n; i++) {
                if ('0' <= s[i + 1] && s[i + 1] <= '9') {
                    v = v * 10 + (s[i + 1] - '0');
                } else {
                    break;
                }
            }
            sum[cur] += v;
        }
        md = max(md, cur);
    }

    return sum[md - 1];
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}