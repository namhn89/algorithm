#include<iostream>
#include<cstdio>
#define FOR(i,a,b)for(int i=(a),_b=(b);i<_b;i++)
#define st first
#define nd second
using namespace std;
const int N = 500005;
int m, n, cnt, F[N];

int main(){
    scanf("%d%d", &m,&n);
    FOR(i,1,m) {
        int h, l, r;
        scanf("%d", &h);
        if (i%2) l = 1, r = h;
        else l = n-h+1, r = n;
        F[l]++; F[r+1]--;
    }
    FOR(i,1,n) {
        F[i] += F[i-1];
        if (F[i] < m) m = F[i], cnt = 1;
        else if (F[i] == m) cnt++;
    }
    printf("%d %d\n", m, cnt);

    return 0;
}
