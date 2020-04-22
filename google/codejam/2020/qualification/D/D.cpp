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

int B; 

int querry(int x) {
  cout << x << endl; 
  int res; 
  cin >> res;
  return res;  
} 

void test_case() {
  vector <int> answer(B + 1); 
  int queries = 0;
  for (int i = 1; i <= B; ++i) {
    answer[i] = querry(i); 
    queries += 1; 
    if (queries % 10 == 0) {
      if (answer[0] != querry(0)){
        for (int j = 1; j <= i; ++j) {
          answer[j] ^= 1; 
        }
      }
      queries += 1; 
    }
  }

  for(int i = 1; i <= B; ++i) {
    cout << answer[i]; 
  }
  cout << endl;
	string response;
	cin >> response;
	assert(response == "Y");
	return; 
}

int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int T; 
  cin >> T >> B;  
  for(int nr = 1; nr <= T; ++nr) { 
    test_case(); 
  }
  return 0;
}