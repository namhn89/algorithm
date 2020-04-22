#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define remove_duplicate(a) sort(a.begin(), a.end()); a.resize(distance(a.begin(), unique(a.begin(), a.end())));

typedef long long longint;

const int MAXN = 2e5 + 10;
const int SIZE = sqrt(MAXN * log2(MAXN));
const int MAXBLOCK = MAXN / SIZE + 2;
int n, nQuery, bsize, nBlock;
int a[MAXN];
int block[MAXN], start[MAXN], finish[MAXN];
struct Fenic {
    vector<int> data;
    Fenic (int n = 0) { data.resize(n + 1); }
    void up (int node, int value) {
        for (; node <= n; node += node & -node) {
            data[node] += value;
        }
    }
    int get (int node) {
        int res = 0;
        for (; node > 0; node -= node & -node) {
            res += data[node];
        }
        return res;
    }
} bit[MAXBLOCK];


int main(){
    #define file "in"
    //freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);

    scanf("%d %d", &n, &nQuery);
    bsize = max(1, (int)sqrt(n * (log2(n))));
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        block[i] = i / bsize + 1;
    }
    nBlock = block[n];
    for (int i = 1; i <= n; i++) {
        if (block[i] != block[i - 1]) start[block[i]] = i;
        if (block[i] != block[i + 1]) finish[block[i]] = i;
    }
    for (int iBlock = 1; iBlock <= nBlock; iBlock++) {
        bit[iBlock] = Fenic(n);
    }
    for (int i = 1; i <= n; i++) {
        bit[block[i]].up(a[i], 1);
    }

    /*for (int iBlock = 1; iBlock <= nBlock; iBlock++) {
        cout << start[iBlock] << " " << finish[iBlock] << endl;
    }
    cout << endl;*/
    longint res = 0;
    while (nQuery--) {
        int L, R;
        scanf("%d %d", &L, &R);
        if (L > R) swap(L, R);
        if (block[L] == block[R]) {
            for (int i = L + 1; i <= R - 1; i++) {
                if (a[L] > a[i]) res--;
            }
            for (int i = L + 1; i <= R - 1; i++) {
                if (a[i] > a[R]) res--;
            }
            if (a[L] > a[R]) res--;
            swap(a[L], a[R]);
            for (int i = L + 1; i <= R - 1; i++) {
                if (a[L] > a[i]) res++;
            }
            for (int i = L + 1; i <= R - 1; i++) {
                if (a[i] > a[R]) res++;
            }
            if (a[L] > a[R]) res++;
            printf("%lld\n", res);
            continue;
        }
        for (int i = L + 1; i <= finish[ block[L] ]; i++) {
            if (a[L] > a[i]) res--;
            if (a[i] > a[R]) res--;
        }
        for (int i = start[ block[R] ]; i <= R - 1; i++) {
            if (a[L] > a[i]) res--;
            if (a[i] > a[R]) res--;
        }
        for (int iBlock = block[L] + 1; iBlock <= block[R] - 1; iBlock++) {
            res -= bit[iBlock].get(a[L] - 1);
            res -= bit[iBlock].get(n) - bit[iBlock].get(a[R]);
        }
        bit[block[L]].up(a[L], -1);
        bit[block[R]].up(a[R], -1);
        if (a[L] > a[R]) res--;
        swap(a[L], a[R]);
        bit[block[L]].up(a[L], 1);
        bit[block[R]].up(a[R], 1);
        for (int i = L + 1; i <= finish[ block[L] ]; i++) {
            if (a[L] > a[i]) res++;
            if (a[i] > a[R]) res++;
        }
        for (int i = start[ block[R] ]; i <= R - 1; i++) {
            if (a[L] > a[i]) res++;
            if (a[i] > a[R]) res++;
        }
        for (int iBlock = block[L] + 1; iBlock <= block[R] - 1; iBlock++) {
            res += bit[iBlock].get(a[L] - 1);
            res += bit[iBlock].get(n) - bit[iBlock].get(a[R]);
        }
        if (a[L] > a[R]) res++;
        printf("%lld\n", res);
        /*for (int iBlock = 1; iBlock <= 2; iBlock++) {
            for (int value = 1; value <= n; value++) if (bit[iBlock].get(value) - bit[iBlock].get(value - 1) == 1) cout << value << " "; cout << endl;
        }*/
    }
    return 0;
}
