#include<bits/stdc++.h>
using namespace std;
const int N = 1010, oo = N*300;
int n, a[N], F[N][N], ans = oo;

int main() {
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &a[i]);
    FOR(i,0,n+1) FOR(j,0,n+1) F[i][j] = oo;
    F[0][0] = 0;
    FOR(i,1,n)
        FOR(j,0,n)
            if (a[i] > 100 && j > 0)
                F[i][j] = min(F[i-1][j-1] + a[i], F[i-1][j+1]);
            else
                F[i][j] = min(F[i-1][j] + a[i], F[i-1][j+1]);
    FOR(i,0,n) ans = min(ans, F[n][i]);
    printf("%d\n", ans);

    return 0;
}
