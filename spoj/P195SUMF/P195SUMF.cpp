using namespace std;
#include<bits/stdc++.h>
#define st first
#define nd second
#define FORE(i,a,b) for(int i=(a),b_=(b);i<=b_;++i)
#define FORD(i,a,b) for(int i=(a),b_=(b);i>=b_;--i)
#define TR(c, it) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define removeDuplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())))
 
const int N = 1e5 + 1; // careful
const int M = 110 + 1;
const int MOD = 998244353;
const int primitiveRoot = 3;
 
struct Matrix {
    int n;
    long long data[M][M];
    Matrix () {
        n = 0;
        memset(data, 0, sizeof(data));
    }
 
    Matrix(int sz){
        n = sz;
        for(int i = 0; i < n; ++i) {
            data[i][i] = 1;
        }
    }
 
    Matrix operator * (const Matrix &b) const {
        Matrix ans;
        Matrix a = *this;
        ans.n = a.n;
        for(int i = 0; i < a.n; ++i){
            for(int j = 0; j < a.n; ++j){
                for(int k = 0; k < a.n; ++k){
                    ans.data[i][j] = (ans.data[i][j] + data[i][k] * b.data[k][j]) % (MOD - 1);
                    ans.data[i][j] %= (MOD - 1);
                }
 
            }
        }
        return ans;
    }
    Matrix power (long long p) {
        Matrix t = *this, res;
        res.n = t.n ;
        for(int i = 0; i < res.n; ++i) res.data[i][i] = 1;
        while (p) {
            if (p & 1LL) res = (res * t);
            t = t * t;
            p >>= 1LL;
        }
        return res;
    }
 
    void printMatrix(){
        cout << n << endl;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
 
};
 
namespace solveEquation {
    long long power(long long a, long long n, int mod){
        long long res = 1;
        while(n){
            if(n & 1LL) res = (res * a) % mod;
            a = (a * a) % mod;
            n >>= 1LL;
        }
        return res;
    }
 
    int solve(int a, int b, int mod){
        /// find z such that a ^ z = b (mod M)
        int n = (int) sqrt(mod) + 1;
        map<long long, int> vals ;
        for(int p = 1; p <= n; ++p){
            vals[power(a, p * n, mod)] = p;
        }
        for(int q = 0; q <= n; ++q){
            long long cur = (power(a, q, mod) * b) % mod;
            if(vals.count(cur)){
                int ans = vals[cur] * n - q;
                return ans;
            }
        }
        return -1;
    }
    vector <int> solveVector(int a, int b, int mod){
        /// find z such that a ^ z = b (mod M)
        vector<int> res;
        int n = (int) sqrt(mod) + 1;
        map<long long, int> vals ;
        for(int p = 1; p <= n; ++p){
            vals[power(a, p * n, mod)] = p;
        }
        for(int q = 0; q <= n; ++q){
            long long cur = (power(a, q, mod) * b) % mod;
            if(vals.count(cur)){
                int ans = vals[cur] * n - q;
                res.push_back(ans);
            }
        }
        return res;
    }
}
 
long long inv (long long a , long long m) {
    return 1 < a ? m - inv(m % a , a) * m / a : 1 ;
}
 
int k;
int f[N];
int n, m;
 
void solveTest() {
    cin >> k;
    Matrix base;
    base.n = k;
    for(int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        base.data[0][i] = x ;
    }
    cin >> n >> m;
    for(int i = 1; i < k; ++i){
        base.data[i][i - 1] = 1;
    }
    vector <int> result;
    for(auto z : solveEquation::solveVector(primitiveRoot, m, MOD)){
        base = base.power(n - k);
        int x = base.data[0][0];
        int y = MOD - 1;
        int g = __gcd(x, y);
        if (z % g != 0) {
            cout << -1 << endl; 
            return; 
        }
        x /= g, y /= g, z /= g;
        long long res = (inv(x, y) * z) % y;
        result.push_back(solveEquation::power(primitiveRoot, res, MOD));
    }
    sort(result.begin(), result.end());
    if(result.size() == 0) {
        cout << -1 << endl;
    }
    else {
        cout << result[0] << endl; 
    }
}
 
 
int main()
{
#define TASK "test"
    freopen(TASK".inp","r",stdin);
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
 