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

map <string, bool> f;
int sum[N]; 

std::string boxChat(std::string s, std::vector<std::string> a)
{
    for (int i = 0; i < a.size(); i++) {
        string tmp = a[i];
        f[tmp] = true;
    }

    s = s + " ";
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            tmp.push_back(s[i]);
        } else {
            if (f[tmp] == true) {
            	int r = i - 1;
            	int l = r - tmp.size() + 1;
            	sum[l]++;
            	sum[r + 1]--;
            }
            tmp =  "";
        }
    }
    for (int i = 1; i < s.size(); i++) sum[i] += sum[i - 1];
   	string ans = "";
   	for (int i = 0; i < s.size() - 1; i++)
   		if (sum[i]) ans.push_back('*');
   	else ans.push_back(s[i]);
   	return ans;
}

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
     
  return 0;
}