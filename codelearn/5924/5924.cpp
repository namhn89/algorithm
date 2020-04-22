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

int prev(int a) {
  return (a - 1 + 26) % 26; 
}

int dis(int a, int b) {
  return (b - a + 26) % 26; 
} 

int funStringTransformation(std::string a, std::string b) {
    int cnta[26], cntb[26];
    for (int i = 0; i < 26; i++) cnta[i] = cntb[i] = 0;
    for (char c : a) cnta[c - 'A']++;
    for (char c : b) cntb[c - 'A']++;
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (cntb[i] == 0)
            continue;
        if (cnta[i] >= cntb[i]) {
            cnta[i] -= cntb[i];
            cntb[i] = 0;
            continue;
        }
        cntb[i] -= cnta[i];
        cnta[i] = 0;
        for (int j = prev(i); cntb[i] > 0 && j != i; j = prev(j)) {
            if (cnta[j] > 0) {
                int uses = min(cntb[i], cnta[j]);
                cnta[j] -= uses;
                cntb[i] -= uses;
                res += uses * dis(j, i);
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
     
  return 0;
}