#include <bits/stdc++.h>
using namespace std;
 
const int N = 110;
const int P = 998244353;
 
int D[N][N], E[N][N], F[N][N];
 
int k;
 
void mul(int A[N][N], int B[N][N], int C[N][N]) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) D[i][j] = A[i][j], E[i][j] = B[i][j];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			long long val = 0;
			for (int l = 0; l < k; l++) {
				val += 1LL * D[i][l] * E[l][j];
				val %= (P - 1);
			}
			C[i][j] = val;
		}
	}
}
 
void pow(int A[N][N], int n, int B[N][N]) {
	if (n == 0) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if (i == j) B[i][j] = 1;
				else B[i][j] = 0;
			}
		}
		return;
	}
	int hn = n / 2;
	pow(A, hn, B);
	mul(B, B, B);
	if (n & 1) mul(B, A, B);
}
 
int modExp(int a, long long n, int p) {
	int ret = 1; ((a %= p) < 0) && (a += p);
	for (; n; n >>= 1, a = (long long)a * a % p)
		if (n & 1) ret = (long long)ret * a % p;
	return ret;
}
 
map<int, int> M;
 
template<typename T>
T mod_inv(T a, T mod) {
	if (__gcd(a, mod) != 1) return -1;
	T b = mod, s = 1, t = 0;
	while (b) {
		T q = a / b;
		swap(a -= q * b, b);
		swap(s -= q * t, t);
	}
	return s < 0 ? s + mod : s;
}
 
int L = 100000;
 
int A[N][N], B[N][N];
int b[N];
 
void  solveTest() {
	cin >> k;
	for (int i = 0; i < k; i++) cin >> b[i];
	int n, m; cin >> n >> m;
	for (int i = 0, j = 1; i < L; i++, j = 1LL * j * 3 % P) {
		M[j] = i;
	}
	int PJ = modExp(3, P-1-L, P);
	int pm;
	for (int add = 0, cur = m; ; add += L, cur = 1LL * cur * PJ % P) {
		if (M.count(cur)) {
			pm = M[cur] + add;
			break;
		}
	}
	assert(modExp(3, pm, P) == m);
	memset(A, 0, sizeof A);
	for (int i = 0; i < k; i++) A[0][i] = b[i];
	for (int i = 1; i < k; i++) {
		A[i][i-1] = 1;
	}
	pow(A, n - k, B);
	int a = B[0][0];
	int d = __gcd(a, P - 1);
	if (pm % d != 0) {
        cout << -1 << endl; 
        return ;
    }
	a /= d, pm /= d;
	int p = (P - 1) / d;
	int x = 1LL * mod_inv(a, p) * pm % p;
	cout << modExp(3, x, P) << endl;
}
 
int main()
{
#define TASK "test"
    // freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nTest;
    cin >> nTest;
    while(nTest--){
        solveTest();
    }
    return 0;
}