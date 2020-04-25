#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FOD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N = 1001, inf = 2e9;
int n, m, a[N], ans, F[2][N][4];

int main() {
    scanf("%d%d", &n,&m);

    FOR(i,1,m) {
        FOR(j,1,n) {
            scanf("%d", &a[j]);
            FOR(t,0,3) F[0][j][t] = F[1][j][t];
            F[1][j][2] = a[j] + F[0][j][3];
            if (j == 1)
                F[1][j][0] = inf;
            else
                F[1][j][0] = a[j] + min(F[1][j-1][0], F[1][j-1][2]);
        }
        FOD(j,n,1) {
            if (j == n)
                F[1][j][1] = inf;
            else
                F[1][j][1] = a[j] + min(F[1][j+1][1], F[1][j+1][2]);
            F[1][j][3] = min(min(F[1][j][0], F[1][j][1]), F[1][j][2]);
        }
    }

    int ans = inf;
    FOR(j,1,n) ans = min(ans, F[1][j][3]);

    printf("%d\n", ans);

    return 0;
}
