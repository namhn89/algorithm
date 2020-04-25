#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<complex>
using namespace std;

typedef complex<double> Point;
const int N = 1e5 + 1 , TIME = 100;
Point mul (cos(M_PI/TIME), sin(M_PI/TIME));
Point p1[N] , p2[N] ;
int m, n;

void enter(int &n , Point p[N]) {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> p[i].real() >> p[i].imag();
}

bool cmp(const Point &a , const Point &b) {
	return a.real() < b.real();
}

int main() {
	ios::sync_with_stdio(false);
	int tc ; cin >> tc;
	while(tc--) {
		enter(m, p1); enter(n, p2);
		bool ans = true;
		for(int i = 0; i < TIME; ++i) {
			if(max_element(p1 , p1+m , cmp )->real() < min_element(p2 , p2+n , cmp)->real() ||
					max_element(p , p2+n , cmp )->real() < min_element(p1 , p1+m , cmp)->real()) {
				ans = false;
				break;
			}
			for(int i = 0; i < m; ++i) p1[i] *= mul;
			for(int i = 0; i < n; ++i) p2[i] *= mul;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
