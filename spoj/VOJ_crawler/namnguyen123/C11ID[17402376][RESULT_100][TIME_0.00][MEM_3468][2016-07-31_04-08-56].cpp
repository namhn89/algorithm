#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5, mod = 1e9+7;
ll n, a[N], ans = 1ll;

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;++i) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
    for(int i=1;i<=n;++i) ans = ans * (a[i]-i+1) % mod;
    printf("%lld\n", ans);

    return 0;
}
