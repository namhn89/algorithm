#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 1;

struct item {
    int a, b, d;
    item (int _a = 0, int _b = 0, int _d = 0): a(_a), b(_b), d(_d) {};
    bool operator < (const item& op) const {
        if(d == op.d) {
            if(a == op.a) return b < op.b;
            else return a < op.a;
       } else return d < op.d;
    }
};
item f[MAXN];

int main() {
    int n, k;
    scanf ("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf ("%d", &f[i].a);
    for (int i = 0; i < n; i++) scanf ("%d", &f[i].b);
    for (int i = 0; i < n; i++) f[i].d = f[i].a - f[i].b;
    sort (f, f + n);
    long long ans = 0;
    for (int i = 0; i < k; i++) ans += 1ll * f[i].a;
    for (int i = k; i < n; i++)
        if (f[i].d < 0) ans += 1ll * f[i].a;
        else ans += 1ll * f[i].b;
    printf("%lld\n", ans);
    return 0;
}
