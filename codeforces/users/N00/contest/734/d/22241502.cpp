#include <bits/stdc++.h> 

using namespace std;

#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define FOR(i, a, b) for(int i = a, _b = (b) ; i <= _b ; i++)
#define FORD(i, a, b) for(int i = a, _b = (b) ; i >= _b ; i--)

typedef long long int64;

vector <pair <char, int64> > maincross, subcross, row, columm; 

int N; 

int find_smaller(vector <pair<char, int64> > a, int64 x) {
	int low = 0, high = a.size() - 1, res = -1; 
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid].second <= x) {
			res = mid; 
			low = mid + 1; 
		}
		else high = mid - 1; 
	}
	return res; 
}
int find_bigger (vector <pair<char, int64> > a, int64 x) {
	int low = 0, high = a.size() - 1, res = -1; 
	while (low <= high) {
		int mid = (low + high) / 2; 
		if (a[mid].second >= x) {
			res = mid; 
			high = mid - 1; 
		}
		else low = mid + 1; 
	}
	return res; 
}

bool compare (pair <char, int64> a, pair<char, int64> b) { return a.second < b.second; }

int main() {
    #define file "in"
    //freopen(file".INP","r",stdin); freopen(file".OUT","w", stdout);

 	scanf("%d", &N);
 	int64 xking, yking; 
 	scanf("%lld %lld", &xking, &yking);   
    for (int i = 1; i <= N; i++) {
    	int64 x, y; 
    	char c; 
    	cin >> c; 
    	scanf("%lld %lld", &x, &y);
    	if (x + y == xking + yking) {
    		subcross.push_back(make_pair(c, x));
    	}
    	if (x - y == xking - yking) {
    		maincross.push_back(make_pair(c, x));
    	}
    	if (x == xking) {
    		columm.push_back(make_pair(c, y));
    	}
    	if (y == yking) {
    		row.push_back(make_pair(c, x));
    	}
    }
    sort (subcross.begin(), subcross.end(), compare);
    sort (maincross.begin(), maincross.end(), compare);
    sort (columm.begin(), columm.end(), compare);
    sort (row.begin(), row.end(), compare);  
    int p1, p2;
    p1 = find_smaller(subcross, xking); 
    p2 = find_bigger(subcross, xking);
    #define outyes return cout << "YES", 0;
    #define LINE(x) (x.first == 'Q' || x.first == 'R')
    #define CROSS(x) (x.first == 'Q' || x.first == 'B')
   	//foreach(P, subcross) cout << P -> first << " " << P -> second << endl;  
    if (p1 != -1) {
    	if (CROSS(subcross[p1])) outyes; 
    }
    if (p2 != -1) {
    	if (CROSS(subcross[p2])) outyes; 
    }
    p1 = find_smaller(maincross, xking); 
    p2 = find_bigger(maincross, xking);
    if (p1 != -1) {
    	if (CROSS(maincross[p1])) outyes; 
    }
    if (p2 != -1) {
    	if (CROSS(maincross[p2])) outyes; 
    }
    p1 = find_smaller(row, xking);
    p2 = find_bigger(row, xking);
    if (p1 != -1) {
    	if (LINE(row[p1])) outyes; 
    }
    if (p2 != -1) {
    	if (LINE(row[p2])) outyes; 
    }
    p1 = find_smaller(columm, yking); 
    p2 = find_bigger(columm, yking);
    if (p1 != -1) {
    	if (LINE(columm[p1])) outyes; 
    }
    if (p2 != -1) {
    	if (LINE(columm[p2])) outyes; 
    }
    cout << "NO";
    return 0; 	
}