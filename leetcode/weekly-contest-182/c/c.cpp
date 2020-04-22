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

class UndergroundSystem {
public:
		map<int, pair<string, int>> fID ; 
		map<pair<string, string>, pair<int, int>> f; 
    UndergroundSystem() {
			fID = map<int, pair<string, int>>(); 
			f = map<pair<string, string>, pair<int, int>>(); 
        
    }
    
    void checkIn(int id, string stationName, int t) {
        fID[id] = make_pair(stationName, t); 
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> p = fID[id];
				fID.erase(id);  
				pair<string, string> q = make_pair(p.first, stationName); 
				f[q].first++; 
				f[q].second += t - p.second; 

    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> p = make_pair(startStation, endStation); 
				return (double) f[p].second/ f[p].first; 
    }
};

 
int main() {
  #define TASK "TASK"
  // freopen(TASK".inp","r",stdin);
  // freopen(TASK".out","w",stdout);
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  
  return 0;
}