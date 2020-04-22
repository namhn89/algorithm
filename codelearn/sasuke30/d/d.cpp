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

#define st first
#define nd second

const int N = (int) 1e5 + 5;

pair <int, pair <string, int> > x[N];

int chooseEmployee(std::vector<std::string> skill, std::vector<int> salary, std::string requestSkill, int k)
{
    map <string, int> cnt;
    int n = 0;
    int choose = 0;
    int ans = 0;
    if (choose >= k) return ans;
    for (int i = 0; i < skill.size(); i++) {
       cnt[skill[i]]++;
    }
    for (int i = 0; i < skill.size(); i++) x[i] = make_pair(cnt[skill[i]], make_pair(skill[i], -salary[i]));
    sort(x, x + (int) skill.size());

    int j = -1;
    for (int i = skill.size() - 1; i >= 0; i--)
      if (x[i].nd.st == requestSkill) {
        j = i;
        break;
      }
    if (j != -1) {
      for (int i = j; i >= 0; i--) {
        if (x[i].nd.st == requestSkill) {
          choose++;
          ans += -x[i].nd.nd;
        } else break;
        if (choose >= k) break;
      }
    }
    if (choose >= k) return ans;
    for (int i = skill.size() - 1; i >= 0; i--) {
      if (x[i].nd.st == requestSkill) continue;
      choose++;
      ans += -x[i].nd.nd;
      if (choose >= k) break;
    }
    if (choose < k) return -1;
    return ans;
}
 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}