#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N = 50005;
int n, m, a[N], tmax[4*N];


int main() {
    cin >> n >> m;
    while (m--) {
        int i, j, k; scanf("%d%d%d", &i,&j,&k);
        a[i] += k; a[j+1] -= k;
    }
    FOR(i,2,n) a[i] += a[i-1];

    build(1,1,n);

    cin >> m;
    while (m--) {
        int L, R; scanf("%d%d", &L,&R);
        printf("%d\n", get_max(1,1,n,L,R));
    }

    return 0;
}
