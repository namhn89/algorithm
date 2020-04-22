#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
int a[2][6];

int main() {
    int n;
    scanf("%d", &n);
    int x;
    for(int i = 0; i < n + n; i++) {
        scanf("%d", &x);
        if(i < n) a[0][x]++;
        else a[1][x]++;
    }
    int s = 0;
    for(int i = 1; i < 6; i++) {
        if((a[0][i] + a[1][i]) % 2) {
            puts("-1");
            return 0;
        }
        s += abs((a[0][i] + a[1][i]) / 2 - a[0][i]);
    }
    printf("%d\n", s / 2);
    return 0;
}
