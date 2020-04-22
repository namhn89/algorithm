#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define remove_duplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

typedef long long longint;

const int MAXN = 2e5 +  10;
const long long oo = 1e10 + 7;
struct T {
    int a, b;
    T (int a = 0, int b = 0) : a(a), b(b) {}
    bool operator < (const T &other) {
        return b - a > other.b - other.a;
    }
} a[MAXN];
int n, k;


long long suma[MAXN], sumb[MAXN];

int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].a;
    for (int i = 1; i <= n; i++) cin >> a[i].b;

    sort (a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--) sumb[i] = sumb[i + 1] + a[i].b;
    for (int i = 1; i <= n; i++) suma[i] = suma[i - 1] + a[i].a;

    long long res = oo;
    for (int i = k; i <= n; i++) {
        res = min(res, suma[i] + sumb[i + 1]);
    }
    cout << res;
    return 0;
}
