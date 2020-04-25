#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <set>
#include <stack>
#include <queue>
#define FORE(i,c) for (__typeof ((c).begin ()) i = (c).begin (); i != (c).end (); ++(i))
#define FOR(i,a,b) for (int i = (int) (a), _b = (int) (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (int) (a), _b = (int) (b); i >= _b; --i)
#define REP(i, n) for (int i = 0, _n = (int) (n); i < _n; ++i)
#define REPD(i, n) for (int i = (int) (n) - 1; i >= 0; --i)
#define RESET(i, j) memset (i, j, sizeof i)
#define ALL(v) (v).begin (), (v).end ()
#define PB push_back
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef pair <int, int> PII;
typedef long long LL;
typedef double DD;
typedef long double LD;
const LL LLINF = 1LL << 61;
const int INF = 1e9;
const double EPS = 1e-9;

LL MOD, a, b, k;

void add (LL &a, LL b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

LL mul (LL a, LL b) {
	if (!b) return 0;
	LL c = mul (a, b >> 1);
	add (c, c);
	if (b & 1) add (c, a);
	return c;
}

struct Mat {
	LL v [2][2];
	Mat () {
		memset (v, 0, sizeof v);
	}
	LL *operator [] (int i) {
		return v [i];
	}
} iden;

Mat mul (Mat a, Mat b) {
	Mat c;
	REP (i, 2) REP (j, 2) REP (k, 2)
		add (c [i][j], mul (a [i][k], b [k][j]));
	return c;
}

Mat power (Mat a, LL b) {
	if (!b) return iden;
	Mat c = power (a, b >> 1);
	c = mul (c, c);
	if (b & 1) c = mul (c, a);
	return c;
}

int main () {
	REP (i, 2) iden [i][i] = 1;
//	freopen ("in", "r", stdin);
	int test; cin >> test;
	REP (zz, test) {
		cin >> a >> b >> MOD >> k;
//		cerr << a << " " << b << " " << MOD << " " << k << endl;
		a %= MOD;
		b %= MOD;
		Mat step, start;
		start [0][1] = 1;
		step [0][0] = a; step [1][0] = b;
		step [1][1] = 1;
		Mat tmp = power (step, k);
//		REP (i, 2) { REP (j, 2) cerr << tmp [i][j] << " "; cerr << endl; }
		tmp = mul (start, tmp);
		cout << tmp [0][0] << endl;
	}
	return 0;
}
