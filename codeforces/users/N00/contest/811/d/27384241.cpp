#include <bits/stdc++.h> 
using namespace std; 
	
int nr, nc; 
char grid[105][105]; 
pair<int, int> trace[105][105]; 
pair<int, int> finish; 
bool inside (int x, int y) {
	return min(x, y) >= 1 && x <= nr && y <= nc; 
}
pair<int, int> get (char c) {
	printf("%c\n", c);
	fflush(stdout); 
	int x, y; 
	scanf("%d %d", &x, &y); 
	return pair<int, int> (x, y); 
}

int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, 1, -1}; 
vector<pair<int, int> > path;
void bfs () {
	queue<pair<int, int> > q; 
	q.push(make_pair(1, 1)); 
	trace[1][1] = make_pair(-1, -1); 
	while (not q.empty()) {
		int x = q.front().first; 
		int y = q.front().second; 
		q.pop(); 
		for (int d = 0; d < 4; d++) {
			int x2 = x + dx[d]; 
			int y2 = y + dy[d]; 

			if (trace[x2][y2] == make_pair(0, 0) && grid[x2][y2] != '*' && inside(x2, y2)) {
				trace[x2][y2] = make_pair(x, y);
				q.push(make_pair(x2, y2));  
			}
		}
	}
	pair<int, int> curr = finish; 
	while (true) {
		//cout << curr.first << " " << curr.second << endl; 
		path.push_back(curr);
		if (trace[curr.first][curr.second] == make_pair(-1, -1)) break;  
		curr = trace[curr.first][curr.second]; 
		
	}
	reverse(path.begin(), path.end()); 
}

char direct (int x, int y, int x2, int y2) {	
	for (int d = 0; d < 4; d++) {
		if (x2 == x + dx[d] && y2 == y + dy[d]) {
			if (d == 0) return 'U';
			if (d == 1) return 'D'; 
			if (d == 2) return 'R'; 
			if (d == 3) return 'L';
		}
	}
	return 'S';
}




int main() {
	cin >> nr >> nc; 
	for (int x = 1; x <= nr; x++) {
		for (int y = 1; y <= nc; y++) {
			cin >> grid[x][y]; 
			if (grid[x][y] == 'F') finish = make_pair(x, y); 
		}
	}

	map<char, int> m; 
	m['U'] = 0; m['D'] = 1;
	m['R'] = 2; m['L'] = 3;
	bfs();

	
	int swapLR = -1, swapUD = -1;
	for (int i = 0; i < path.size() - 1; i++) {
		int x = path[i].first; 
		int y = path[i].second; 
		char d = direct(path[i].first, path[i].second, path[i + 1].first, path[i + 1].second); 
		if (not inside(x + dx[m[d] ^ 1], y + dy[m[d] ^ 1])) {
			if (get(d) == path[i]) {
				if (d == 'U' || d == 'D') {
				  swapUD = 1; 
					if (d == 'U') get('D'); 
					else get('U'); 
				} 
				else {
					swapLR = 1;
					if (d == 'R') get('L'); 
					else get('R');
				}
			} 
			else {
				if (d == 'U' || d == 'D') swapUD = 0; 
				else swapLR = 0;
			}
		}
		else {
			if (d == 'L') { if (swapLR) get('R'); else get('L'); };
			if (d == 'R') { if (swapLR) get('L'); else get('R'); };
			if (d == 'U') { if (swapUD) get('D'); else get('U'); }; 
			if (d == 'D') { if (swapUD) get('U'); else get('D'); }; 
		}	
	} 
} 