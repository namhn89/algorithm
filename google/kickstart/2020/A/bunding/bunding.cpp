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
int n, k;
int cnt[N];  
string s[N]; 
int solve(vector<int> indexs, int pos) {
    if (indexs.size() < k) return 0;
    vector<int> vChar[30];
    for (int i = 'A' - 'A'; i <= 'Z' - 'A'; i++) {
        cnt[i] = 0;
        vChar[i].clear();
    }
    for (auto id : indexs) {
        int c = s[id][pos] - 'A';
        cnt[c]++;
        if (pos + 1 < s[id].size())
            vChar[c].push_back(id);
    }
    int res = 0;
    for (int i = 'A' - 'A'; i <= 'Z' - 'A'; i++)
        res += cnt[i] / k;
    for (int i = 'A' - 'A'; i <= 'Z' - 'A'; i++)
        res += solve(vChar[i], pos + 1);
    return res;
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; 
  cin >> t; 
  for(int iTest = 0; iTest < t; ++iTest) {
    /* code */
    cout <<"Case #"<< iTest + 1 <<": ";
    cin >> n >> k; 
    for (int i = 1; i <= n; ++i) {
      cin >> s[i]; 
    }
    vector<int> tmp;
    for (int i = 1; i <= n; i++) tmp.push_back(i);
    cout << solve(tmp, 0) <<endl;
  }
  
     
  return 0;
}