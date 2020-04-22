#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N = 30010;
int n, a[N], s[N];

int main() {
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", a+i);
    int k = 1;
    s[1] = 1;
    FOR(i,2,n) {
        int l = 1, r = k, j = 0;
        while (l <= r) {
            int m = (l+r)/2;
            if (a[i] > a[s[m]]) {
                j = m;
                l = m+1;
            }
            else
                r = m-1;
        }
        if (j == k) s[++k] = i;
        if (a[i] < a[s[j+1]]) s[j+1] = i;
    }
    printf("%d\n", k);

    return 0;
}
