#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N = 30010;
int n, a[N], s[N];

int main() {
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", a+i);
    int k = 1;
    s[1] = a[1];
    FOR(i,2,n) {
        int j = k;
        while (j > 0 && a[i] <= s[j]) j--;
        if (j == k) s[++k] = a[i];
        s[j+1] = min(s[j+1], a[i]);
    }
    printf("%d\n", k);

    return 0;
}
