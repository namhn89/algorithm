#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
int n, a[35];
ll x, F[35][35];

int main() {
    scanf("%d", &n); n = 2*n+1;

    F[0][0] = 1ll; F[1][1] = 1ll;
    FOR(j,2,n-1) {
        F[0][j] = F[1][j-1];
        FOR(i,1,n+1) F[i][j] = F[i-1][j-1] + F[i+1][j-1];
    }

    FOR(i,1,n) scanf("%d", &a[i]);
    x = 1ll;
    FOR(i,2,n) {
        if (a[i] < a[i-1] || a[i-1] == 0) continue;
        x += F[a[i-1]-1][n-i];
    }
    printf("%lld\n", x);

    scanf("%lld\n", &x); x--;
    a[1] = 0;
    FOR(i,2,n) {
        if (a[i-1] == 0) a[i] = 1;
        else {
            if (x >= F[a[i-1]-1][n-i]) {
                x -= F[a[i-1]-1][n-i];
                a[i] = a[i-1]+1;
            }
            else a[i] = a[i-1]-1;
        }
    }
    FOR(i,1,n) printf("%d ", a[i]);

    return 0;
}
